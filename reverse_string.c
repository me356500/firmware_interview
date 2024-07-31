#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void swap(char* i, char* j) {
    char tmp = *i;
    *i = *j;
    *j = tmp;
}

int main() {
    char str[10] = "TestFile";

    int l = 0, r = strlen(str) - 1;

    while (l < r) {
        swap(&str[l], &str[r]);

        ++l;
        --r;
    }

    printf("%s\n", str);

    return 0;
}