
#include <stdio.h>

int binary_search(unsigned int * a, int l, int r, int target)
{
    while (l <= r) {
        // prevent overflow
        int mid = l + (r - l) / 2;

        if (a[mid] == target)
            return mid;
        else if (a[mid] < target)
            l = mid + 1;
        else 
            r = mid - 1;
    }

    return -1;
}

