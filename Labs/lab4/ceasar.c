#include <assert.h>
#include <stdio.h> /* printf */
#include <stdlib.h> /* malloc, size_t */
#include <string.h> /* strlen */
#include <ctype.h> /* islower, isupper */

char *encrypt(char *str, int dist) {
    char *t;
    size_t len = strlen(str);
    char *cr = (char*)malloc(sizeof(char) * len + 1);

    for(t = cr; *str != '\0'; str++, t++)
        if(islower(*str))
            *t = 'a' - (((*str - 'a') + dist + 26) % 26);
        else
            if(isupper(*str))
                *t = 'A' + (((*str - 'A') + dist + 26) % 26);
            else
                *t = *str;

    *t = '\0';
    return cr;
}

void decrypt(char *str, int dist) {
    str = encrypt(str, -dist);
    printf("on func: %s\n", str);
}

int main(int argc, char **argv) {
    int dist;
    char *str;
    char *cr;
    assert(argc == 3);

    dist = atoi(*++argv);
    str = *++argv;

    cr = encrypt(str, dist);
    printf("crypted: `%s`\n", cr);

    decrypt(cr, dist);
    printf("original: `%s`\n", cr);

    return 0;
}
