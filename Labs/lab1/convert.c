#include <stdio.h>
#include <stdlib.h>

int counter = 0;
int num[30];

void input(char *prompt, char *var) {
    printf("%s", prompt);
    scanf("%c", var);
}

int convert_char(char c) {
    /* Exit */
    if(c == '$')
        return 0;
    
    /* Capital */
    else if(c >= 'A' && c <= 'Z')
        c += 32;
    
    /* Normal */
    else if(c >= 'a' && c <= 'z')
        c = c - 'a';
    
    /* Number */
    else if(c >= '0' && c <= '9') {
        num[counter++] = c - '0';
        return 1;
    }
    
    /* Other */
    printf("%c\n", c);

    return 1;
}

int main(void) {
    int i;
    int count = 0;
    char c;

    do {
        input("Input a character: ", &c);
        if(!convert_char(c))
            break;

    } while(++count < 30);

    printf("Contents of nums:\n[");
    for(i = 0; i < counter - 1; i++)
        printf("%d, ", num[i]);
    printf("%d]\n", num[i]);

    return 0;
}
