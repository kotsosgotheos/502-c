#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <sys/wait.h>
#include <sys/types.h>

int fd[2];

void parent(N) {
    int i, sum = 0, child_res;
    close(fd[1]);

    for(i = 1; i <= N/2; i++)
        sum += i;
    
    read(fd[0], &child_res, sizeof(int)); /* Read result from child */
    close(fd[0]);
    waitpid(-1, NULL, 0);  /* Wait for child */

    /* Sum */
    printf("Sum form 1 to %d = %d\n", N, sum + child_res);
}

void child(N) {
    int i, sum = 0;
    close(fd[0]);

    for(i = N/2 + 1; i <= N; i++)
        sum += i;
    
    write(fd[1], &sum, sizeof(int));
    close(fd[1]);
}

int main(void) {
    int N;

    if(pipe(fd) < 0) {
        perror("pipe()");
        exit(1);
    }

    do {
        printf("Give positive number >= 2: ");
        scanf("%d", &N);
    } while(N < 2);

    if(fork() != 0) /* parent */
        parent(N);
    else
        child(N);
    
    return 0;
}