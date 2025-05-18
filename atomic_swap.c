#define _GNU_SOURCE
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/syscall.h>
#include <errno.h>

int main() {
    if (renameat2(AT_FDCWD, "file1.txt", AT_FDCWD, "file2.txt", RENAME_EXCHANGE) == -1) {
        perror("renameat2");
        return 1;
    }
    printf("Files swapped atomically.\n");
    return 0;
}
