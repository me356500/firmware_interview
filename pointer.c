#include <stdio.h>

void write(int* a, int* b) {
    a = b;
    *a = 2;
}

void write_pointer() {
    int i = 0, j = 1;

    write(&i, &j);
    printf("%d %d\n", i, j);
}

void ptr2() {
    int arr[] = {10,20,30,40,50};
	int *ptr1 = arr;
	int *ptr2 = arr + 5; 
    int *ptr3 = &arr + 1;
    int *ptr4 = *(ptr2 - 1);

	printf("%d\n", (ptr2 - ptr1));
	printf("%d\n", (char*)ptr2 - (char*)ptr1);
    printf("%d\n", ptr3 - ptr2);
    printf("%d\n", ptr4);
}

int main() {
   int a[] = {1,2,3,4,5,6};
    int *p = a;
    *(p++) += 100;
    *(++p) += 100;
    for(int i = 0; i<6 ; i++)
        printf("%d ", a[i]);    

    // appendix
    int *p2 = a;
    int *p3 = a;
    int e = (*p2)++; 
    int f = ++*p3;

    printf("\n%d", e);  
    printf(", %d \n", f); 
    ptr2();
}