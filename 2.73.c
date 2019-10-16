#include <limits.h>

/* Addition that saturates to TMin or TMax */
int saturating_add(int x, int y)
{
    int sum = x + y;
    int mask = (1 << ((8*sizeof(int))-1));
    int overflow = sum & mask;
    int diffsign = (x & mask) ^ (y & mask);
    
    !diffsign && overflow && (sum = INT_MAX);
    !diffsign && !overflow && (sum = INT_MIN);
    
    return sum;
}
