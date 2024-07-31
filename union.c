#include <stdio.h>

union tmp1 {
    int a;
    char b[2];
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
}