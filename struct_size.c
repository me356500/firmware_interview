#include <stdio.h>

struct tmp1 {
    double a;
    int b;
    char c;
    // padding 3
};

struct tmp2 {
    int a;
    // padding 4
    double b;
    char c;
    // padding 7
};

struct tmp3 {
    int a;
    char b;
    // padding 3
    double c;
};

struct Some_struct
{
    int a;
    char c[10];
};

int main() {
    struct tmp1 test1;
    struct tmp2 test2;
    struct tmp3 test3;

    printf("%d\n%d\n%d\n", sizeof(test1), sizeof(test2), sizeof(test3));

    // print struct size without using sizeof
    struct Some_struct ss[2];
    // char pointer
    printf("%d\n", (char*)(&ss[1]) - (char*)(&ss));

}