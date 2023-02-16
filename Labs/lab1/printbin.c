#include <stdio.h>
#include <stdlib.h>

void printbin(int num) {
    int i;

    for(i = 0; num > 0; i++) {
        printf("%d", num % 2);
        num /= 2;
    }

    printf("\n");
}

int main(void) {
    int num = 0;
    while(num != 502) {
        printf("dec to bin: ");
        scanf("%d", &num);
        printbin(num);
    }

    return 0;
}
