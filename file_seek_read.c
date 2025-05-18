#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>

int main() {
    int fd = open("testfile.bin", O_RDWR | O_CREAT, 0666);
    if (fd < 0) {
        perror("open");
        return 1;
    }

    unsigned char data[10] = {4, 5, 2, 2, 3, 3, 7, 9, 1, 5};
    write(fd, data, 10);
    lseek(fd, 3, SEEK_SET);

    unsigned char buffer[4];
    read(fd, buffer, 4);

    printf("Read bytes: ");
    for (int i = 0; i < 4; ++i)
        printf("%d ", buffer[i]);
    printf("\n");

    close(fd);
    return 0;
}
