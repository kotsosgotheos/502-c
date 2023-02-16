#include "file_handler.h"

int main(void) {
    if(file_exists("testfile.txt")) {
        printf("File already exists\n");
        exit(1);
    }

    FILE *fd = file_open("testfile.txt", "w");
    file_write(fd, "line1");
    file_write(fd, "line2");
    file_write(fd, "line3");
    file_write(fd, "line4");

    file_close(fd);
}

