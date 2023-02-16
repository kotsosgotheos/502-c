#include <stdio.h>
#include <string.h>

int letters[26];

static void charstats(char *str) {
    while(*str++)
        letters[((((int)*(str-1) - 'A') % 32) - 'a') % 26 + 19]++;
}

int main(void) {
    int i;
    char buf[1024];

    while(strncmp(strtok(fgets(buf, sizeof(buf), stdin), "\n"), "###", 3))
        charstats(buf);

    for(i = 0; i < 26; i++)
        printf("%c : %d\n", 'a' + i, letters[i]);
}
