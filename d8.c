#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main(){
    int N;
    scanf("%d", &N);

    pid_t pid = getpid();
    if(pid == -1){
        perror("error");
        return 1;
    }

    for (int i = 1; i <= N; i++) {
        pid_t cpid= fork();
        if (cpid== -1) {
            perror("fork");
            return 3;
        } else if (cpid== 0){            
            fprintf(stdout, "son %d\n", i);
            fflush(stdout);
            fprintf(stderr, "PID = %d PPID = %d\n", getpid(), getppid());
            fflush(stderr);
        } else {
            wait(NULL);
            break;
        }
    }
    //while(wait(NULL) > 0);
    return 0;
}