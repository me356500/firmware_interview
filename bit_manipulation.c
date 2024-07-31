#include <stdio.h>


/* a=target variable, b=bit number to act upon 0-n */
#define BIT_SET(a,b) ((a) |= (1ULL<<(b)))
#define BIT_CLEAR(a,b) ((a) &= ~(1ULL<<(b)))
#define BIT_FLIP(a,b) ((a) ^= (1ULL<<(b)))
#define BIT_CHECK(a,b) (!!((a) & (1ULL<<(b))))        // '!!' to make sure this returns 0 or 1

#define BITMASK_SET(x, mask) ((x) |= (mask))
#define BITMASK_CLEAR(x, mask) ((x) &= (~(mask)))
#define BITMASK_FLIP(x, mask) ((x) ^= (mask))
#define BITMASK_CHECK_ALL(x, mask) (!(~(x) & (mask)))
#define BITMASK_CHECK_ANY(x, mask) ((x) & (mask))

int getnthbit(unsigned int n, int idx) {
    // ith bit : idx - 1

    return (n & (1 << (idx - 1)));
}

int setnthbit(unsigned int n, int idx) {
    return (n | (1 << (idx - 1)));
}

int clearnthbit(unsigned int n, int idx) {
    return (n & ~(1 << (idx - 1)));
}

int inversenthbit(unsigned int n, int idx) {
    return (n ^ (1 << (idx - 1)));
}

int ispoweroftwo(unsigned int x) {
    return (x != 0) && (x & (x - 1)) == 0;
}

unsigned int odd_even_change(unsigned int a) {
    return ((a & 0xAAAAAAAA) >> 1) | ((a & 0x55555555) << 1);
}