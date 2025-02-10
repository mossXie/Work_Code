#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include <sys/wait.h>

volatile sig_atomic_t flag = 0, flagi = 1;

typedef struct {
    int Dec;
    int Inc;
} cnt;

/*void swap(int num1, int num2){
    int temp;
    temp = num1;
    num1 = num2;
    num2 = temp;
}*/

void SigHandler(int s){
    signal(SIGUSR1, SigHandler);
    flag = 1;
}

void childProcess1(pid_t parentPid, int fd[2], cnt Cnt) {
    while (Cnt.Inc < Cnt.Dec) {
        if (!flag) {
            pause();
        }
        flag = 0;
        read(fd[0], &Cnt, sizeof(cnt));
        if (Cnt.Inc <= Cnt.Dec) {
            printf("son1 %d %d\n", Cnt.Dec, Cnt.Inc); fflush(stdout);
            Cnt.Dec--; Cnt.Inc++;
        }
        write(fd[1], &Cnt, sizeof(cnt));
        kill(parentPid, SIGUSR1);
    }
    close(fd[0]); close(fd[1]);
}

void childProcess2(pid_t parentPid, int fd[2], cnt Cnt) {

    while (Cnt.Inc < Cnt.Dec) {
        if (!flag) {
            pause();
        }
        flag = 0;
        read(fd[0], &Cnt, sizeof(cnt));

        if (Cnt.Inc <= Cnt.Dec) {
            printf("son2 %d %d\n", Cnt.Dec, Cnt.Inc); fflush(stdout);
            Cnt.Dec--; Cnt.Inc++;
        }
        write(fd[1], &Cnt, sizeof(cnt));
        kill(parentPid, SIGUSR1);
    }
    close(fd[0]); close(fd[1]);
}

int main() {
    pid_t pid;
    pid_t pid2;
    cnt Cnt;
    int fd[2];
    signal(SIGUSR1, SigHandler);
    
    if (pipe(fd) < 0) { perror("pipe"); return 1; }
    
    scanf("%d %d", &Cnt.Dec, &Cnt.Inc);


    pid = fork();
    if (pid < 0) { perror("fork"); return 2; }    
    if (pid > 0) { // father
        pid2 = fork();
        if (pid2 < 0) { perror("fork"); return 2; }
        if (pid2 == 0) { 
            if(flagi){
                if (Cnt.Inc == Cnt.Dec){
                    printf("son2 %d %d\n", Cnt.Dec, Cnt.Inc); fflush(stdout); 
                }
                flagi = 0;
            }
            childProcess2(pid, fd, Cnt);
            return 0;
        } else { // father
            write(fd[1], &Cnt, sizeof(cnt));
            kill(pid2, SIGUSR1);

            while (Cnt.Inc < Cnt.Dec) {
                if (!flag) {
                    pause();
                }
                flag = 0;
                read(fd[0], &Cnt, sizeof(cnt));        
                if (Cnt.Inc <= Cnt.Dec) {
                    printf("father %d %d\n", Cnt.Dec, Cnt.Inc); fflush(stdout);
                    Cnt.Dec--; Cnt.Inc++;
                }
                write(fd[1], &Cnt, sizeof(cnt));
                kill(pid2, SIGUSR1);
            }
            close(fd[0]); close(fd[1]);
            wait(NULL); wait(NULL);
        }
    } else if (pid == 0) { // son1
        pid_t pid_father = getppid();
        childProcess1(pid_father, fd, Cnt);
        return 0;
    }

    return 0;
}