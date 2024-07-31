#include <stdio.h>

int ishexequal(unsigned short input) {

    unsigned short hex[4];

    hex[0] = (input & 0xF000) >> 12;
    hex[1] = (input & 0x0F00) >> 8;
    hex[2] = (input & 0x00F0) >> 4;
    hex[3] = (input & 0x000F);

    return ((hex[0] == hex[1]) && (hex[1] == hex[2]) && (hex[2] == hex[3]));
}

int main(){

    // 0x0000 0x1111 0x2222 ... 0xFFFF
    

}