#include <stdio.h>    /* scanf, printf, puts */
#include <string.h>   /* exit */
#include <unistd.h>   /* fork, execl */
#include <errno.h>    /* perror */
#include <sys/wait.h> /* waitpid */

#include "standard_boolean.h"

typedef struct _program {
    char *menutitle;
    char *fullpath;
    char *name;
} program;

program ls_block_t      = { "1. run ls",                 "/usr/bin/ls",      "ls" };
program ls_t            = { "2. run ls (and wait)",      "/usr/bin/ls",      "ls" };
program sleep_block_t   = { "3. run sleep",              "/usr/bin/sleep 5", "sleep" };
program sleep_t         = { "4. run sleep (and wait)",   "/usr/bin/sleep 5", "sleep" };
program gnuplot_block_t = { "5. run gnuplot",            "/usr/bin/gnuplot", "gnuplot" };
program gnuplot_t       = { "6. run gnuplot (and wait)", "/usr/bin/gnuplot", "gnuplot" };
program exit_t          = { "0. exit",                   NULL,               NULL};

void execute(program *cmd) {
    int pid;

    if((pid = fork()) == 0) {/* Child */
        /* Exec application */
        execl(cmd->fullpath, cmd->name, NULL);

        perror("execl()"); /* This should not be executed */
    }
    else { /* Parent */
        if(strcmp(cmd->menutitle, "2. run ls (and wait)") == 0
        || strcmp(cmd->menutitle, "4. run sleep (and wait)") == 0
        || strcmp(cmd->menutitle, "6. run gnuplot (and wait)") == 0)
            waitpid(pid, NULL, 0);
    }
}

char scan_line(void) {
    int arg;
    scanf("%d", &arg);
    return arg;
}

void print(char *str) {
    printf("%s\n", str);
}

bool mainLoop(void) {
    char arg;

    print((&ls_block_t)->menutitle);
    print((&ls_t)->menutitle);
    print((&sleep_block_t)->menutitle);
    print((&sleep_t)->menutitle);
    print((&gnuplot_block_t)->menutitle);
    print((&gnuplot_t)->menutitle);
    print((&exit_t)->menutitle);
    
    printf("\n$> ");

    arg = scan_line();
    switch(arg) {
        case 1:
            execute(&ls_block_t);
            return true;
        case 2:
            execute(&ls_t);
            return true;
        case 3:
            execute(&sleep_block_t);
            return true;
        case 4:
            execute(&sleep_t);
            return true;
        case 5:
            execute(&gnuplot_block_t);
            return true;
        case 6:
            execute(&gnuplot_t);
            return true;
        case 0:
            printf("Exiting...\n");
            execute(&exit_t);
            return false;
        default:
            printf("Wrong option: `%c`", arg);
            return true;
    }
}

int main(void) {
    while(mainLoop());
}
