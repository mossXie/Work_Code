#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <fcntl.h>

int main(int argc, char **argv) {
    if (argc < 7) { 
        fprintf(stderr, "Usage: %s pr1 arg1 | pr2 arg2 arg3  pr3\n", argv[0]);
        return 1;
    }

    int fd1[2];
    if (pipe(fd1) < 0) {
        perror("pipe1");
        return 1;
    }


    int fd2[2];
    if (pipe(fd2) < 0) {
        perror("pipe2");
        return 1;
    }

    pid_t pid1 = fork();
    if (pid1 < 0) {
        perror("fork1");
        return 1;
    }
    if (pid1 == 0) { 
        if (dup2(fd1[1], 1) < 0) {
            perror("dup2");
            return 1;
        }
        close(fd1[0]);
        close(fd1[1]);
        execlp(argv[1], argv[1], argv[2], NULL);
        perror("execlp");
        return 1;
    }

    pid_t pid2 = fork();
    if (pid2 < 0) {
        perror("fork2");
        return 1;
    }
    if (pid2 == 0) {
        close(fd1[1]);
        if (dup2(fd1[0], 0) < 0 || dup2(fd2[1], 1) < 0) {
            perror("dup2");
            return 1;
        }
        close(fd1[0]);
        close(fd2[0]);
        close(fd2[1]);
        execlp(argv[3], argv[3], argv[4], argv[5], NULL);
        perror("execlp");
        return 1;
    }

    pid_t pid3 = fork();
    if (pid3 < 0) {
        perror("fork3");
        return 1;
    }
    if (pid3 == 0) {
        close(fd2[1]);
        if (dup2(fd2[0], 0) < 0) {
            perror("dup2");
            return 1;
        }
        close(fd2[0]);
        close(fd2[1]);
        execlp(argv[6], argv[6], NULL);
        perror("execlp");
        return 1;
    }

    close(fd1[0]);
    close(fd1[1]);
    close(fd2[0]);
    close(fd2[1]);

    wait(NULL);
    wait(NULL);
    wait(NULL);

    return 0;
}