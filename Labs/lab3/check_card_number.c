#include <stdio.h>

int check_card_number(char *str) {
    int digit;
    int sum = 0;
    int i = 0;

    while(*(str + i++)) {
        int offset = i - 1;
        digit = *(str + offset) - 48;
        if(offset % 2 == 0) {
            digit *= 2;
            if(digit > 9)
                /* digit = digit % 10 + digit / 10; */
                digit -= 9;
        }
        sum += digit;
    }

    if(sum % 10 == 0)
        return 1;
    return 0;
}

int main(void) {
    char *n1 = "1234567898645231";
    char *n2 = "4539366868975365";
    char *n3 = "4658872453879792";

    if(check_card_number(n1))
        printf("card: `%s` is valid\n", n1);
    else
        printf("card: `%s` is invalid\n", n1);
    
    if(check_card_number(n2))
        printf("card: `%s` is valid\n", n2);
    else
        printf("card: `%s` is invalid\n", n2);

    if(check_card_number(n3))
        printf("card: `%s` is valid\n", n3);
    else
        printf("card: `%s` is invalid\n", n3);

    return 0;
}
