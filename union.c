#include <stdio.h>

union tmp1 {
    int a;
    char b[2];
};

struct struct_test {
    char b4;
    char b3;
    char b2;
    char b1;
};

union union_test {
    struct struct_test s1;
    int all;
};

int main() {
    union tmp1 a;
    a.b[0] = 10;
    a.b[1] = 1;

    // char store from low addree
    /**
     * High address
     * 
     * 00      00
     * 00      00
     * 00  --> 01
     * 00      0A 
     * 
     * Low address
     */
    
    printf("%d\n", a.a);


    union union_test u1;
    u1.all = 0x12345678;

    u1.s1.b1 &= 0xAA;
    u1.s1.b2 = 0x33;
    u1.s1.b3 &= 0xBB;
    u1.s1.b4 = 0xCC;

    /**
     * High address
     * 
     * 12      02
     * 34      33
     * 56  --> 12
     * 78      CC 
     * 
     * Low address
     */

    printf("%x\n", u1.all);
}