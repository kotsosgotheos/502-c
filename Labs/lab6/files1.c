#include <stdio.h> /* FILE, fopen, fputs, fgets */
#include <stdlib.h> /* atoi, malloc */

void write(FILE *fd, int curr) {
    fprintf(fd, "%d\n", curr);
}

int main(void) {
    FILE *fd, *pfd, *nfd;
    int i, num;
    int npos = 0, nneg = 0;
    int *arr;
    
    if(!(fd = fopen("data.txt", "r"))) {
        printf("Error on openning `data.txt`\n");
        return 1;
    }

    fscanf(fd, "%d", &num);
    arr = (int*)malloc(sizeof(int) * num);

    for(i = 0; i < num; i++) {
        fscanf(fd, "%d", &arr[i]);

        if(arr[i] > 0)
            npos++;
        else
            nneg++;
    }
    fclose(fd);

    pfd = fopen("positive.txt", "a");
    nfd = fopen("negative.txt", "a");
    fprintf(pfd, "%d\n", npos);
    fprintf(nfd, "%d\n", nneg);

    for(i = 0; i < num; i++) {
        if(arr[i] > 0)
            fprintf(pfd, "%d\n", arr[i]);
        else
            fprintf(nfd, "%d\n", arr[i]);
    }

    return 0;
}
