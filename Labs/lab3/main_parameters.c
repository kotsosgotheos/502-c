#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv) {
    int result = 0;

    assert(argc >= 3);
    
    switch(**++argv) {
        case '+':
            while(*++argv)
                result += atoi(*argv);
            break;
        case '-':
            result = atoi(*++argv);
            while(*++argv)
                result -= atoi(*argv);
            break;
        case '*':
            while(*++argv)
                result *= atoi(*argv);
            break;
        case '/':
            result = atoi(*++argv);
            while(*++argv)
                result /= atoi(*argv);
            break;
    }

    printf("result: %d\n", result);
    return 0;
}
