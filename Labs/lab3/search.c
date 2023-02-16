#include <stdio.h>
#include <stdlib.h>

void search(int *arr, int size, int x, int **out_value) {
    int i;
    for(i = 0; i < size; i++)
        if(arr[i] == x) {
            *out_value = &arr[i];
            return;
        }
}

int main(void) {
    int *out_value = NULL;
    int size = 10;
    int arr[10] = {2, 3, 5, 7, 11, 42, 13, 17, 19, 101};
    int x = 42;

    search(arr, size, x, &out_value);

    if(out_value)
        printf("value: %d, position: %d\n", *(int*)out_value, ((int)out_value - (int)arr) / 4);
    else
        printf("not value\n");

    return 0;
}
