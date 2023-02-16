#include <stdio.h> /* printf */
#include <stdlib.h> /* malloc */

char *my_strndup(char *str, size_t n) {
    size_t i;
    char *dup = (char*)malloc(sizeof(char) * n);

    if(!dup) return NULL;
    
    for(i = 0; i < n; i++)
        *dup++ = *str++;

    *dup = '\0';
    dup -= n;

    /* str -= n; */

    return dup;
}

int main(void) {
    char *test = my_strndup("copyme", 10);
    printf("test: `%s`\n", test);
    
    return 0;
}
