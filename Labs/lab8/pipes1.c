#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <sys/wait.h>
#include <sys/types.h>

#include "standard_boolean.h"

int pfd[2]; /* Pipe */

void parent(void) {
    FILE *txtfile;
    int n, num;

    close(pfd[1]); /* Close the parent pipe */
    printf("(%d) - I am the parent.\n", getpid());
    printf("       Waiting for nums and writing positive ones to file.\n");
    
    txtfile = fopen("positive.txt", "w"); /* Open text file for writing */
    if(txtfile == NULL) {
        perror("fopen()");
        exit(1);
    }

    /* Read from pipe and write to file */
    while((n = read(pfd[0], &num, sizeof(int))) > 0)
        if(num > 0)
            fprintf(txtfile, "%d\n", num); /* Write to file if positive */
    
    if(n < 0) { /* error */
        perror("read()");
        exit(1);
    }

    waitpid(-1, NULL, 0); /* Wait for child process */

    close(pfd[0]); /* (n = 0): child closed pipe */
    fclose(txtfile); /* close the textfile */
}

void child(void) {
    int num;

    close(pfd[0]); /* Close the child pipe */
    printf("(%d) - I am the child.\n", getpid());
    printf("       Type positive/negative ints (-1 to end):\n");

    while(true) {
        scanf("%d", &num);
        if(num == -1) {
            close(pfd[1]);
            return;
        }
        write(pfd[1], &num, sizeof(int)); /* Write to pipe */
    }
}

int main(void) {
    if(pipe(pfd) < 0) {
        perror("pipe()");
        exit(1);
    }

    /*
        fork != 0 -> Parent
        fork == 0 -> Child
    */
    if(fork() != 0)
        parent();
    else
        child();

    return 0;
}
