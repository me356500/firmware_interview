#include <stdio.h>

void swap(int* a, int *b) {
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

// Hoare Partition
int hpartition(int *a, int l, int r){

    /**
     * Differ with Lomuto partition 
     * qsort(a, l, pivot);
     * qsort(a, pivot + 1, r);
     */
    
    // Median of three 
    int m = l + (r - l) / 2;
    if (a[m] < a[l])
        swap(&a[l], &a[m]);
    if (a[r] < a[l])
        swap(&a[l], &a[r]);
    if (a[r] < a[m])
        swap(&a[m], &a[r]); 

    int pivot = a[m];
    int i = l - 1, j = r + 1;
    while (1) {
        do {
            i++;
        } while(a[i] < pivot);

        do {
            j--;
        } while(a[j] > pivot);
        
        if(i >= j)
            return j;
        
        swap(&a[i], &a[j]);
    }
}

// Lomuto Partition
int partition(int *a, int l, int r) {
    // whatever
    int pivot = a[r];

    int i = l - 1;

    for (int j = l; j < r; ++j) {
        // current element smaller than pivot
        if (a[j] < pivot) {
            ++i;
            // swap based on pivot
            swap(&a[i], &a[j]);
        }
    }

    ++i;
    swap(&a[i], &a[r]);

    return i;
}

void qsort(int *a, int l, int r) {
    if (l < r) {
        int pivot = partition(a, l, r);
        qsort(a, l, pivot - 1);
        qsort(a, pivot + 1, r);
    }
}