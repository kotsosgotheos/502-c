#include <stdio.h>

int *search(int *arr, int size, int x) {
    int i;
    for(i = 0; i < size; i++)
        if(arr[i] == x)
            return &arr[i];

    return NULL;
}

int main(void) {
    int *value;
    int size = 10;
    int arr[10] = {2, 3, 5, 7, 11, 42, 13, 17, 19, 101};
    int x = 42;

    value = search(arr, size, x);

    
    
    if(value)
        printf("value: %d, position: %ld\n",
            *value,
            ((int)value - (int)arr) / sizeof(int)
        );
    else
        printf("not value\n");

    return 0;
}
