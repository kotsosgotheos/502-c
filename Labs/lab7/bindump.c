#include <stdio.h>

void printbin(int n) {
    int i;
    int mask = 1 << 31; /* 32 bit integers */

    for(i = 0; i < 32; i++) {
        if(n & mask)
            printf("1");
        else
            printf("0");

        n <<= 1; /* Left shift once */
    }
}

int main(void) {
    int n;

    while(1) {
        printf("\nEnter integer: (`0` exists): ");
        scanf("%d", &n);
        if(n == 0)
            break;

        printbin(n);
    }

    return 0;
}
