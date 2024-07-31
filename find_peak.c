#include <stdio.h>


int findFirstIndex(unsigned int a[], int size) {
    int left = 0;
    int right = size - 1;
    int result = -1; 

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (a[mid] == 0) {
            result = mid;  
            right = mid - 1; 
        } 
        else {
            left = mid + 1; 
        }
    }

    return result;
}

int main() {
    unsigned int a[20] = {1, 1, 1, 1, 1, 0, 0, 0}; 
    int size = sizeof(a) / sizeof(a[0]);

    int firstIndex = findFirstIndex(a, size);

    if (firstIndex != -1) {
        printf("First index of 0 is: %d\n", firstIndex);
    } else {
        printf("No 0 found in the array.\n");
    }

    return 0;
}
