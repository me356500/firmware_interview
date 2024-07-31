#include <stdio.h>
#include <stdint.h>

int main() {
    uint32_t a = 0x12345678;

    uint8_t* p = (uint8_t *)&a;

    if (*p == 0x78) {
        printf("little endian\n");
    }
    else {
        printf("big endian\n");
    }

    printf("%x\n", *p);
    printf("%x\n", *(p + 1));
    printf("%x\n", *(p + 2));
    return 0;
}