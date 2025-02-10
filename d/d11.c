#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/wait.h>

int main(int argc, char **argv) {
    if (argc < 4) {
        fprintf(stderr, "Usage: %s pr1 arg1 < file\n", argv[0]);
        return 1;
    }

    pid_t pid = fork();
    if (pid == -1) {
        perror("fork");
        return 2;
    }
    if (pid == 0) {
        int fd = open(argv[3], O_RDONLY);
        if (fd == -1) {
            perror("open");
            //printf("1");
            return 3;
        }
        dup2(fd, 0);
        close(fd);
        execlp(argv[1], argv[1], argv[2], NULL);
        perror("execlp");
        return 4;
    }

    wait(NULL);
    return 0;
}