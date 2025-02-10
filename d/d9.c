#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    pid_t pid, cpid;
    int fd[2];
    if (pipe(fd) == -1) {
        perror("pipe");
        return 1;
    }

    pid = fork();
    if (pid == -1) {
        perror("fork");
        return 2;
    }

    if (pid == 0) { 
        close(fd[1]);
         int min = 0, max = 0;
        int num, first = 1;

        while (read(fd[0], &num, sizeof(num)) > 0) {
            if (first) {
                min = max = num;
                first = 0;
            } else {
                if (num < min) min = num;
                if (num > max) max = num;
            }
        }
        close(fd[0]);
        printf("%d %d\n", min, max);
    } else {
        cpid = fork();
        if (cpid == -1) {
            perror("fork");
            return 3;
        }
        if (cpid == 0) {
            close(fd[0]);
            int num;
            while (scanf("%d", &num) == 1) {
                write(fd[1], &num, sizeof(num));
            }
            close(fd[1]);
        } else {
            close(fd[0]);
            close(fd[1]);
            wait(NULL);
            wait(NULL);
        }
    }
    return 0;
}