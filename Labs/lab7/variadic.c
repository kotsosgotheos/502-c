#include <stdio.h>
#include <stdarg.h>

void print_type(va_list args, int type) {
    switch (type) {
        case 'i':
            printf("%d\n", va_arg(args, int));
            break;
        case 'd':
            printf("%g\n", va_arg(args, double));
            break;
        default:
            printf("unknown type: `%c`\n", type);
            va_arg(args, void*);
    }
}

void iterate_numbers(va_list args, int size) {
    int i;
    for(i = 0; i < size; i++) {
        int type = va_arg(args, int);
        print_type(args, type);
    }
}

void printnums(int size, ...) {
    va_list args;
    va_start(args, size);
    iterate_numbers(args, size);
    va_end(args);
}

int main(void) {
    printnums(3, 'i', 12, 'd', 23.4, 'i', 14);

    return 0;
}
