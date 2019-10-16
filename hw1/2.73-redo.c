#include <limits.h>

#include <stdio.h>

/* Addition that saturates to TMin or TMax */
int saturating_add(int x, int y)
{
    int sum = x + y;
    int mask = (1 << ((8*sizeof(int))-1));
    __builtin_add_overflow_p(x, y, (int) 0) && (sum & mask) && (sum = INT_MAX);
    __builtin_add_overflow_p(x, y, (int) 0) && !(sum & mask) && (sum = INT_MIN);
    return sum;
}
