#include <assert.h>

unsigned long srl(unsigned long x, int k)
{
    unsigned long xsra = (long) x >> k;
    unsigned long mask = ((long) 1 << (8*sizeof(long) - k)) - 1;    // what if k==0 or k==1 ?
    return xsra & mask;
}

long sra(long x, int k)
{
    long xsrl = (unsigned long) x >> k;
    long mask = ((1 << k) - 1) << (8*sizeof(long) - k);
    return xsrl | mask;
}
