#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <fcntl.h>

int main() {
    int pipefd[2];
    char buffer[4096];
    memset(buffer, 'A', sizeof(buffer));

    if (pipe(pipefd) == -1) {
        perror("pipe");
        exit(EXIT_FAILURE);
    }

    fcntl(pipefd[1], F_SETFL, O_NONBLOCK);

    ssize_t written = write(pipefd[1], buffer, sizeof(buffer));
    if (written == -1) {
        perror("write");
    } else {
        printf("write() wrote %ld bytes instead of %ld\n", written, sizeof(buffer));
    }

    return 0;
}
