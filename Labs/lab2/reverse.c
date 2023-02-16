#include <stdio.h>
#include <stdlib.h>

static char *string_end(char *str) {
    int i = 0;

    while(str[i++]);

    /* Counts up to strlen+1 */
    return &str[i - 2]; /* -2 for the last character */
}

void string_reverse(char *s) {
    char temp;
    char *e = string_end(s);

    /* TODO -> probably unsafe */
    char *start = s - 1;
    char *end = e + 1;

    while(end-- > start++) {
        temp = *end;
        *end = *start;
        *start = temp;

        /* start++;
        end--; */
    }
}

int main(void) {
    char test[7] = "abcdef";
    char test2[8] = "abcdefg";

    string_reverse(test);
    string_reverse(test2);

    printf("%s\n", test);
    printf("%s\n", test2);

    return 0;
}
