#include <stdio.h>


unsigned long long strlen(const char *str) {
   
    unsigned long long len = 0;
    while ((unsigned char)*str++) {
        ++len;
    }
       
    return len;
}

char *strcpy(char *dest, const char *src) {
    char *ret = dest;
    while ((*dest++ = *src++));
    return ret;
}

int strcmp(const char *s1, const char *s2) {
    while (*s1 && *s2 && (*s1 == *s2)) {
        s1++;
        s2++;
    }
    return *s1 - *s2;
}

int strncmp(const char *s1, const char *s2, int n) {
    while (n-- && *s1 && (*s1 == *s2)) {
        s1++;
        s2++;
    }
    if (n == (int) -1) {
        return 0;
    }
    return *(const unsigned char *) s1 - *(const unsigned char *) s2;
}