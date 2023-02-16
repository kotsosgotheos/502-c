#include <assert.h>
#include <stdio.h> /* printf */
#include <stdlib.h> /* malloc */

int **pascal(int n) {
    int i, j;
    int **arr;
    assert(n >= 1);

    /* Allocate n pointers to point to the rows */
    if(!(arr = (int**)malloc(sizeof(int*) * n)))
        return NULL;

    for(i = 0; i < n; i++) {
        /* Allocate a row of size i+1 */
        if(!(arr[i] = (int*)malloc(sizeof(int) * (i + 1)))) {
            /* Free before exiting */
            for(j = 0; j < i; j++)
                free(arr[j]);
            free(arr);
            return NULL;
        }

        /* Calculate */
        arr[i][0] = 1;
        for(j = 1; j < i; j++)
            arr[i][j] = arr[i - 1][j - 1] + arr[i - 1][j];
        arr[i][j] = 1;
    }

    return arr;
}

int main(int argc, char **argv) {
    int i, j;
    int n;
    int **arr;
    assert(argc == 2);

    n = atoi(*++argv);
    arr = pascal(n);

    for(i = 0; i < n; i++) {
        for(j = 0; j <= i; j++)
            printf("%3d  ", arr[i][j]);
        printf("\n");
    }

    for(i = 0; i < n; i++)
        free(arr[i]);
    free(arr);

    return 0;
}
