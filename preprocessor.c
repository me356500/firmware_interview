#include <stdio.h>
#define num 100
int change()
{
#undef num
#define num 10
    return num;
}

int main()
{
    int a = 0;
    // preprocessor undef and define
    printf("num = %d, ", num); // 10
    a = change();
    printf("Sum = %d", num + a); // 20

    return 0;
}