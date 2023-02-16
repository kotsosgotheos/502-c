#include <stdio.h> /* printf, scanf */
#include <stdlib.h> /* malloc, srand */
#include <time.h> /* time */

#define MAXNUM size + 1

int main(void) {
    int i;
    int size;
    int *arr;
    float sum = 0;

    srand(time(NULL)); /* seed */

    printf("Input dim size: ");
    scanf("%d", &size);

    arr = (int*)malloc(sizeof(int) * size/* + 1*/);
    for(i = 0; i < size; i++)
        arr[i] = rand() % MAXNUM;

    for(i = 0; i < size; i++) {
        sum += arr[i];
        printf("arr[%d]: %d\n", i, arr[i]);
    }

    printf("sum: %g\n", sum / size);

    return 0;
}
