#include <stdio.h>

int highestone(int n) {
    int highest = 0;

    for (int i = 31; ~i; --i) {
        if ((n >> i) & 1) {
            highest = i;
            break;
        }
    }

    return highest;
}