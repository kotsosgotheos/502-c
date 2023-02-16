#include <assert.h> /* assert */
#include <stdio.h> /* printf */
#include <stdlib.h> /* exit */
#include <unistd.h> /* open */
#include <fcntl.h> /* O_* flags */

#include <sys/stat.h> /* S_* flags */
#define P755 S_IRWXU | S_IRGRP | S_IXGRP | S_IROTH | S_IXOTH

void minicp(char *input, char *output) {
    char buf;
    int fd = open(input, O_RDONLY);
    int outfd = open(output, (O_WRONLY | O_CREAT | O_TRUNC), P755);

    while((read(fd, &buf, sizeof(char))))
        write(outfd, &buf, sizeof(char));

    close(fd);
    close(outfd);
}

int main(int argc, char **argv) {
    char *input, *output;
    assert(argc == 3);

    input = *++argv;
    output = *++argv;

    minicp(input, output);

    return 0;
}
