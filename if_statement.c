#include <stdio.h>
#define THRD 0x8 

void if1() {
    bool x = a();
    bool y = b();

    if (x || y) {
        // gurantee a() & b() must be executed
    }
    if (a() || b()) {
        // if a() is true, then b() won't be executed
    }
}

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