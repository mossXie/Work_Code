#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    int N;
    scanf("%d", &N);

    pid_t pid = getpid();
    //printf("%d\n", pid);

    for (int i = 1; i <= N; i++) {
        pid_t cpid= fork();
        if (cpid== -1) {
            perror("fork");
            return 3;
        } else if (cpid== 0){            
            printf("%d %d\n", getpid() - getppid(), getpid() - pid);
            fflush(stdout);
            fprintf(stderr, "PID = %d PPID = %d\n", getpid(), getppid());
            fflush(stderr);
        } else {
            wait(NULL);
            break;
        }
    }

    return 0;
}
