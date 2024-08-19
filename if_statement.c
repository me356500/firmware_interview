#include <stdio.h>
#define THRD 0x8 

int main() {
    int ch = 26;
	// --> (ch & (0xF > THRD))
	// --> (ch & 1) --> false
    if (ch & 0xF > THRD)
    {
        printf("MORE %d",ch & 0xF);
    }
    else
    {
        printf("LESS %d",ch & 0xF);
    }
    // LESS 10
    return 0;
}