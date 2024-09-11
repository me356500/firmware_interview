#include <stdio.h>
#include <stdint.h>

void write(int* a, int* b) {
    a = b;
    *a = 2;
}

void write_pointer() {
    int i = 0, j = 1;

    write(&i, &j);
    printf("%d %d\n", i, j); // 0 2
}

void ptr2() {
    int arr[5] = {10,20,30,40,50};
	int *ptr1 = arr;
	int *ptr2 = arr + 5; 
    int *ptr3 = (int *)(&arr + 1);
    int *ptr4 = (ptr2 - 1);
    /**
     *   10, 20, 30, 40, 50, 0
     *   p1              p4 p2
     */

	printf("%d\n", (ptr2 - ptr1)); // 5
	printf("%d\n", (char*)ptr2 - (char*)ptr1); // 20
    printf("%d\n", ptr3 - ptr2); // 0
    printf("%d\n", *ptr4); // 50
}


void ptr3(char **p)
{
    char *t;
    // {"ab", "cd", "ef", "gh", "ij", "kl"};
    // (p+= sizeof(int)) --> "ij"
    // [-1] --> "gh"
    t = (p+= sizeof(int))[-1];
    printf("%s",t); // gh
}

void ptr4() {
    char s[] = "0113256";
    char *p = s;
    printf("%c",*p++);      // 先取值再把p指標位移
    // 印0值不變再指到s[1]
    printf("%c",*(p++));    // 等同*p++
    // 印1值不變再指到s[2]
    printf("%c",(*p)++);    // 先取值再把值+1
    // 印1值變2一樣指到s[2]
    printf("%c",*++p);      // p指標位移再取值
    // 指到s[3]後取值
    printf("%c",*(++p));    // 等同*++p
    // 指到s[4]後取值
    printf("%c",++*p);      // *p的值+1後取值
    // s[4]值+1後取值
    printf("%c",++(*p));    // 同 ++*p
    // 再一次s[4]值+1後取值
    printf("\n%s",s);
    // **關鍵在於 p 和 ++ 碰在一起就是位移**
    //-> 0113234
    //-> 0123456
}

void ptr5() {
    uint32_t *a = 0x12345678;
    // move pointer size
    uint64_t *p1 = (uint64_t *)&a; // + 8
    uint32_t *p2 = (uint32_t *)&a; // + 4
    uint8_t *p3 = (uint8_t *)&a; // + 1

    uint32_t b = 0x12345678;
    uint64_t *p4 = (uint64_t *)&b;
    uint32_t *p5 = (uint32_t *)&b;
    uint8_t *p6 = (uint8_t *)&b;

    printf("\na : %x, p1 : %x, p2 : %x, p3 : %x\n", &a, p1 + 1, p2 + 1, p3 + 1);

    printf("\nb : %x, p4 : %x, p5 : %x, p6 : %x\n", b, *p4, *p5, *p6);
}

int main() {
   int a[] = {1,2,3,4,5,6};
    int *p = a;
    *(p++) += 100;
    *(++p) += 100;
    for (int i = 0; i < 6; i++)
        printf("%d ", a[i]);    

    // appendix
    int *p2 = a;
    int *p3 = a;
    int e = (*p2)++; 
    int f = ++*p3;
    printf("\n");
    write_pointer();
    printf("\n%d", e);  
    printf(", %d \n", f); 
    ptr2();

    // appendix 2.
    char *argv[] = {"ab", "cd", "ef", "gh", "ij", "kl"};
    ptr3(argv);
    ptr4();
    ptr5();
}