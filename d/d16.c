#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <signal.h>

volatile sig_atomic_t sigquitNums = 0;
volatile sig_atomic_t sigintNums = 0;
volatile sig_atomic_t flag = 0;


/*void test_signal(pid_t pid)
{
        usleep(10);
        kill(pid, SIGQUIT);
        usleep(10);
        kill(pid, SIGINT);//1:1
        usleep(10);
        kill(pid, SIGQUIT);
        usleep(10);
        kill(pid, SIGQUIT);
        usleep(10);
        kill(pid, SIGINT);//2:2
        usleep(10);
        kill(pid, SIGQUIT);
        usleep(10);
        kill(pid, SIGQUIT);
        usleep(10);
        kill(pid, SIGQUIT);
        usleep(10);
        kill(pid, SIGINT);//4:3
        usleep(10);
        kill(pid, SIGINT);//4：0
        usleep(10);
        kill(pid, SIGQUIT);
        usleep(10);
        kill(pid, SIGINT);//5：1
}*/

void fonct1(int sig) {
    sigquitNums++;
}

void fonct2(int sig) {
    sigintNums++;
    if (sigintNums > 5) {
        flag = 1;
        return;
    }
    char buf[64];
    int len;

    len = 0;
    if (sigintNums == 1) {
        len += sprintf(buf + len, "SIGINT 1 SIGQUIT ");
    } else {
        len += sprintf(buf + len, "SIGINT %d SIGQUIT ", sigintNums);
    }
    len += sprintf(buf + len, "%d\n", sigquitNums);

    write(1, buf, len);
    sigquitNums = 0; 
}


int main() {
    signal(SIGQUIT, fonct1);
    signal(SIGINT, fonct2);
    pid_t pid = fork();
    if (pid > 0) {
        test_signal(pid);
        waitpid(getpid(), NULL, 0);
        return 0;
    } else if (pid == 0) {
        while (!flag) {
            pause();
        }
    } else {
        perror("fork");
        return 2;
    }
}