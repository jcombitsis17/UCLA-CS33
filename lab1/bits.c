/* 
 * CS:APP Data Lab 
 * 
 * <Please put your name and userid here>
 * Name: Jordan Combitsis
 * UID: 004-921-527
 * 
 * bits.c - Source file with your solutions to the Lab.
 *          This is the file you will hand in to your instructor.
 *
 * WARNING: Do not include the <stdio.h> header; it confuses the dlc
 * compiler. You can still use printf for debugging without including
 * <stdio.h>, although you might get a compiler warning. In general,
 * it's not good practice to ignore compiler warnings, but in this
 * case it's OK.  
 */

#if 0
/*
 * Instructions to Students:
 *
 * STEP 1: Read the following instructions carefully.
 */

You will provide your solution to the Data Lab by
editing the collection of functions in this source file.

INTEGER CODING RULES:
 
  Replace the "return" statement in each function with one
  or more lines of C code that implements the function. Your code 
  must conform to the following style:
 
  int Funct(arg1, arg2, ...) {
      /* brief description of how your implementation works */
      int var1 = Expr1;
      ...
      int varM = ExprM;

      varJ = ExprJ;
      ...
      varN = ExprN;
      return ExprR;
  }

  Each "Expr" is an expression using ONLY the following:
  1. Integer constants 0 through 255 (0xFF), inclusive. You are
      not allowed to use big constants such as 0xffffffff.
  2. Function arguments and local variables (no global variables).
  3. Unary integer operations ! ~
  4. Binary integer operations & ^ | + << >>
    
  Some of the problems restrict the set of allowed operators even further.
  Each "Expr" may consist of multiple operators. You are not restricted to
  one operator per line.

  You are expressly forbidden to:
  1. Use any control constructs such as if, do, while, for, switch, etc.
  2. Define or use any macros.
  3. Define any additional functions in this file.
  4. Call any functions.
  5. Use any other operations, such as &&, ||, -, or ?:
  6. Use any form of casting.
  7. Use any data type other than int.  This implies that you
     cannot use arrays, structs, or unions.

 
  You may assume that your machine:
  1. Uses 2s complement, 32-bit representations of integers.
  2. Performs right shifts arithmetically.
  3. Has unpredictable behavior when shifting an integer by more
     than the word size.

EXAMPLES OF ACCEPTABLE CODING STYLE:
  /*
   * pow2plus1 - returns 2^x + 1, where 0 <= x <= 31
   */
  int pow2plus1(int x) {
     /* exploit ability of shifts to compute powers of 2 */
     return (1 << x) + 1;
  }

  /*
   * pow2plus4 - returns 2^x + 4, where 0 <= x <= 31
   */
  int pow2plus4(int x) {
     /* exploit ability of shifts to compute powers of 2 */
     int result = (1 << x);
     result += 4;
     return result;
  }

FLOATING POINT CODING RULES

For the problems that require you to implent floating-point operations,
the coding rules are less strict.  You are allowed to use looping and
conditional control.  You are allowed to use both ints and unsigneds.
You can use arbitrary integer and unsigned constants.

You are expressly forbidden to:
  1. Define or use any macros.
  2. Define any additional functions in this file.
  3. Call any functions.
  4. Use any form of casting.
  5. Use any data type other than int or unsigned.  This means that you
     cannot use arrays, structs, or unions.
  6. Use any floating point data types, operations, or constants.


NOTES:
  1. Use the dlc (data lab checker) compiler (described in the handout) to 
     check the legality of your solutions.
  2. Each function has a maximum number of operators (! ~ & ^ | + << >>)
     that you are allowed to use for your implementation of the function. 
     The max operator count is checked by dlc. Note that '=' is not 
     counted; you may use as many of these as you want without penalty.
  3. Use the btest test harness to check your functions for correctness.
  4. Use the BDD checker to formally verify your functions
  5. The maximum number of ops for each function is given in the
     header comment for each function. If there are any inconsistencies 
     between the maximum ops in the writeup and in this file, consider
     this file the authoritative source.

/*
 * STEP 2: Modify the following functions according the coding rules.
 * 
 *   IMPORTANT. TO AVOID GRADING SURPRISES:
 *   1. Use the dlc compiler to check that your solutions conform
 *      to the coding rules.
 *   2. Use the BDD checker to formally verify that your solutions produce 
 *      the correct answers.
 */


#endif
/* 
 * bang - Compute !x without using !
 *   Examples: bang(3) = 0, bang(0) = 1
 *   Legal ops: ~ & ^ | + << >>
 *   Max ops: 12
 *   Rating: 4 
 */
int bang(int x) {
/*
 * ORing x with its 2's complement either yields all 0's or all 1's (0 or -1).
 * Add 1 to this to obtain desired result of 0 or 1.
 */
  int x_mask = x >> 31;
  int twos_mask = ((~x)+1)>>31;
  return (x_mask | twos_mask) + 1;
}
/*
 * bitCount - returns count of number of 1's in word
 *   Examples: bitCount(5) = 2, bitCount(7) = 3
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 40
 *   Rating: 4
 */
int bitCount(int x) {
/* 
 * Add bit values to each other incrementally, in groups of 2,4,8,16,...
 * ...until total sum is reached.
 * Each mask contains a pattern e.g. 0101,0011,etc. to select...
 * ...a certain number of bits (1,2,4,...) to add together.
 */
  int mask_1,mask_2,mask_4,mask_8,mask_16;
  
  mask_1 = 0x55 + (0x55 << 8);
  mask_1 += (mask_1 << 16);

  mask_2 = 0x33 + (0x33 << 8);
  mask_2 += (mask_2 << 16);

  mask_4 = 0x0f + (0x0f << 8);
  mask_4 += (mask_4 << 16);

  mask_8 = (0xff << 16) + 0xff;

  mask_16 = (0xff << 8) + 0xff;

  x = (x & mask_1) + ((x >> 1) & mask_1);
  x = (x & mask_2) + ((x >> 2) & mask_2);
  x = (x & mask_4) + ((x >> 4) & mask_4);
  x = (x & mask_8) + ((x >> 8) & mask_8);
  x = (x & mask_16) + ((x >> 16) & mask_16);
 
  return x;
}
/* 
 * bitOr - x|y using only ~ and & 
 *   Example: bitOr(6, 5) = 7
 *   Legal ops: ~ &
 *   Max ops: 8
 *   Rating: 1
 */
int bitOr(int x, int y) {
/*
 * In logic, an OR "gate" is equivalent to an AND "gate" with inverters (~)
 * both on the inputs (before gate) and output (after gate).
 */
  return ~((~x)&(~y));
}
/*
 * bitRepeat - repeat x's low-order n bits until word is full.
 *   Can assume that 1 <= n <= 32.
 *   Examples: bitRepeat(1, 1) = -1
 *             bitRepeat(7, 4) = 0x77777777
 *             bitRepeat(0x13f, 8) = 0x3f3f3f3f
 *             bitRepeat(0xfffe02, 9) = 0x10080402
 *             bitRepeat(-559038737, 31) = -559038737
 *             bitRepeat(-559038737, 32) = -559038737
 *   Legal ops: int and unsigned ! ~ & ^ | + - * / % << >>
 *             (This is more general than the usual integer coding rules.)
 *   Max ops: 40
 *   Rating: 4
 */
int bitRepeat(int x, int n) {
/*
 * If n >= 32, return x.
 * Else, start with the lowest n bits, and add them by shifting the int...
 * ... by n^p, where 0<=p<=4.
 * If n exceeds 32, do nothing (right half of "ans += ..." expressions).
 */
  int ans = x;
  int ge32 = (31 - n) >> 31;
  
  ans = x & ((1 << n) - 1);
  ans += (ans << (n));
  ans += (ans << (n<<1)) & (((n<<1)-31)>>31);
  ans += (ans << (n<<2)) & (((n<<2)-31)>>31);
  ans += (ans << (n<<3)) & (((n<<3)-31)>>31);
  ans += (ans << (n<<4)) & (((n<<4)-31)>>31);
  return (ge32 & x) | (~ge32 & ans);
}
/* 
 * fitsBits - return 1 if x can be represented as an 
 *  n-bit, two's complement integer.
 *   1 <= n <= 32
 *   Examples: fitsBits(5,3) = 0, fitsBits(-4,3) = 1
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 15
 *   Rating: 2
 */
int fitsBits(int x, int n) {
/*
 * XORing x with its sign bit gives the "absolute value of x"
 * Shift this right by (n-1). If the result is 0, return 1, else return 0.
 */
  int posx = x ^ (x >> 31);
  int shiftx = posx >> (n + (~0));
  return !shiftx;
}
/* 
 * getByte - Extract byte n from word x
 *   Bytes numbered from 0 (LSB) to 3 (MSB)
 *   Examples: getByte(0x12345678,1) = 0x56
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 6
 *   Rating: 2
 */
int getByte(int x, int n) {
/*
 * number of bits to shift = n * 8 (8 bits in a byte)
 * Create a mask by shifting 0xff (eight 1's) based on value of n.
 * Select the desired byte and right shift to lowest position.
 * AND result with 0xff to eliminate any sign bits that were copied.
 */
  int nbits = n << 3;
  int byte_mask = 0xff << nbits;
  int ans = (x & byte_mask) >> nbits;
  return ans & 0xff;
}
/* 
 * isLessOrEqual - if x <= y  then return 1, else return 0 
 *   Example: isLessOrEqual(4,5) = 1.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 24
 *   Rating: 3
 */
int isLessOrEqual(int x, int y) {
/*
 * diff_sign is 1 if x and y have different sign bits, else 0.
 * If different signs, return (x>>31).
 * If same signs, return 1 if (y-x) is non-negative.
 * Note: either diff or same will be all 0's.
 */
  int sum = y + ((~x) + 1);
  int diff_sign = !!((x>>31)^(y>>31));
  int diff = diff_sign & (x>>31);
  int same = (!diff_sign) & (!(sum>>31));
  return diff | same;
}
/* 
 * isPositive - return 1 if x > 0, return 0 otherwise 
 *   Example: isPositive(-1) = 0.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 8
 *   Rating: 3
 */
int isPositive(int x) {
/* 
 * !(x>>31) is 1 if x>=0, else 0.
 * (~!x+1) is 1 if x==0, else -1.
 * The sum of these gives desired result.
 */
  return !(x>>31) + (~!x+1);
}
/* 
 * logicalShift - shift x to the right by n, using a logical shift
 *   Can assume that 0 <= n <= 31
 *   Examples: logicalShift(0x87654321,4) = 0x08765432
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 20
 *   Rating: 3 
 */
int logicalShift(int x, int n) {
/* 
 * (x>>n) is a standard arithmetic shift.
 * The other expression creates a mask that is n 0's followed by (32-n) 1's.
 * ANDing these 2 expression yields the desired logical shift result.
 */
  return (x>>n) & ~(((1<<31)>>n)<<1);
}
/* 
 * tmin - return minimum two's complement integer 
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 4
 *   Rating: 1
 */
int tmin(void) {
/*
 * The smallest possible two's complement int is a 1 followed by 31 0's.
 */
  return 1 << 31;
}
