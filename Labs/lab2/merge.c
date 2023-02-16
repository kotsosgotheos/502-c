#include <stdio.h>

void mergearrays(int *A, int na, int *B, int nb, int *C) {
    int i = 0, j = 0, k = 0;

    while(i < na && j < nb)
        if(A[i] <= B[j])
            C[k++] = A[i++];
        else
            C[k++] = B[j++];

    while(i < na)
        C[k++] = A[i++];
    while(j < nb)
        C[k++] = B[j++];
}

int main(void) {
    int i;

    int na = 5;
    int A[5] = {1, 3, 5, 7, 9};

    int nb = 5;
    int B[5] = {2, 4, 6, 8, 10};

    int C[10];

    mergearrays(A, na, B, nb, C);

    printf("[");
    for(i = 0; i < na + nb - 1; printf("%d ", C[i++]));
    printf("%d]\n", C[na+nb-1]);
}
