#define R 7
#define S 5
#define T 8

long A[R][S][T];

long
ele (long i, long j, long k)
{
  return A[R - i][1 - j][k - 1];
}

/* (1) Extend Equation 3.1
 * For an array A[R][S][T],
 * Element A[i][j][k] is located at memory address
 * &D[i][j][k] = xD + L(S*T*i + T*j + k)
 */

/* (2) Derive constants
 * The first 2 lines of ele.s store (7-i) in %rax, which matches...
 * ...the first part of the return (A[R-i]), so R = 7.
 * The first leaq command is equivalent to %rax*=5, right before...
 * ...using a subq for j, so S = 5.
 * The second leaq command involves a multiplication by 8, so... 
 * ... T must be T = 8.
 */
