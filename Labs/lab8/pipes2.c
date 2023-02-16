#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <sys/wait.h>
#include <sys/types.h>

#include "standard_boolean.h"

int fd[2];

void child(void) {
    printf("Child: (%d) - executing gnuplot\n", getpid());
    close(fd[1]);

    if(dup2(fd[0], STDIN_FILENO) < 0) { /* Force pipe to flow to stdin */
        perror("dup2()");
        exit(1);
    }

    execl("/usr/bin/gnuplot", "gnuplot", NULL); /* Exec gnuplot */
    printf("execl() failed; gluplot could not be run.\n");
}


int main(void) {
    if(pipe(fd) < 0) {
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