#include <stdio.h>

union tmp1 {
    int a;
    char b[2];
};

union tmp2 {
    char a[8];
    long long b;
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

union MyUnion {
    int a[2];
    char b[8];
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

    union MyUnion temp;
    temp.a[0] = 3406;
	// 3406 --> 0x00000d4e
    /**
     * High address
     * 
     * 00      b[3]
     * 00      b[2]
     * 0d  --> b[1]
     * 4e      b[0] 
     * 
     * Low address
     */
	
    printf("%x\n%x\n", temp.b[0], temp.b[1]);
}