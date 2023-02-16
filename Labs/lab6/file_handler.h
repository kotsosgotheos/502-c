#ifndef __FILE_HANDLER_H_
#define __FILE_HANDLER_H_

#include <stdio.h> /* FILE, fopen */
#include <stdlib.h> /* exit */

#include <fcntl.h> /* .macros. */
#include <errno.h> /* errno */

void handle_exit(char *message) {
    printf("%s\n", message);
    exit(1);
}

int file_exists(char *filename) {
    /*
    FILE *file;
    if((file = fopen("sample.txt","r"))!=NULL) {
        // File found;
        fclose(file);
    else {
        // File not found, no memory leak since 'file' == NULL
        // fclose(file) would cause an error
    }
    */

    int fd;
    if((fd = open(filename, (O_CREAT|O_WRONLY|O_EXCL), (S_IRUSR|S_IWUSR))) < 0) {
        if(errno == EEXIST)
            return 1;
        return 0;
    }
    else
        return 0;
}

FILE *file_open(char *filename, char *mode) {
    FILE *fd;
    
    if(!(fd = fopen(filename, mode)))
        handle_exit("error on open");

    return fd;
}

char *file_readline(FILE *fd) {
    char *line;

    /*
    fgets(line, 64, fd);
    */
    if(!(fscanf(fd, "%s", line)))
        handle_exit("error on readline");

    return line;
}

void file_write(FILE *fd, char *data) {
    /*
    fputs(data, fd);
    fputs("\n", fd);
    */
    if(!(fprintf(fd, "%s\n", data)))
        handle_exit("error on write");
}

void file_close(FILE *fd) {
    fclose(fd);
    fd = NULL;
}

#endif

