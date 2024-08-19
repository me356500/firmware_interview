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
    return (n & (1 << idx));
}

int setnthbit(unsigned int n, int idx) {
    return (n | (1 << idx));
}

int clearnthbit(unsigned int n, int idx) {
    return (n & ~(1 << idx));
}

int inversenthbit(unsigned int n, int idx) {
    return (n ^ (1 << idx));
}

int ispoweroftwo(unsigned int x) {
    return (x != 0) && (x & (x - 1)) == 0;
}

unsigned int odd_even_change(unsigned int a) {
    return ((a & 0xAAAAAAAA) >> 1) | ((a & 0x55555555) << 1);
}

int count_bit(unsigned int n) {
    int ret = 0;

    for (int i = 0; i < 32; ++i) {
        if (n & (1 << i))
            ++ret;
    }

    return ret;
}

int highest_bit(int n) {
    int highest = 0;

    for (int i = 31; ~i; --i) {
        if ((n >> i) & 1) {
            highest = i;
            break;
        }
    }

    return highest;
}