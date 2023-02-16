#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int test = 0xfaced042;
    int first = 0xfa;
    
    char *hex = (char*)&test;

    if(*hex == first)
        printf("little endian\n");
    else
        printf("big endian\n");

    return 0;
}
