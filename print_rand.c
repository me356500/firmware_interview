#include <stdio.h>
#include <math.h>

void swap(int* i, int* j) {
    int tmp = *i;
    *i = *j;
    *j = tmp;
}

int main() {

    int a[500] = {0};

    for (int i = 0; i < 500; ++i)
        a[i] = i;

    srand((unsigned)time(NULL));

    int x = 500;
    int y = rand() % x;

    for (int i = 0; i < 500; ++i) {
        y = rand() % x;
        printf("%d ", a[y]);
        swap(&a[y], &a[--x]);
    }
}