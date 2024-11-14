#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

int main(int argc, char **argv) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s file_name\n", argv[0]);
        return 1;
    }

    int fd = open(argv[1], O_RDWR);
    if (fd == -1) {
        perror("open");
        return 2;
    }

    long max = 0;
    long temp = 0;
    off_t maxP = 0;

    if (read(fd, &temp, sizeof(long)) != sizeof(long)) {
        perror("read");
        close(fd);
        return 3;
    }
    max = temp;
    maxP = 0;

    
    while (read(fd, &temp, sizeof(long)) == sizeof(long)) {
        if (temp > max) {
            max = temp;
            maxP = lseek(fd, 0, SEEK_CUR) - sizeof(long);
        }
    }

    max *= 2;
    lseek(fd, maxP, SEEK_SET);
    if (write(fd, &max, sizeof(long)) != sizeof(long)) {
        perror("write");
        close(fd);
        return 4;
    }

    close(fd);
    return 0;
}