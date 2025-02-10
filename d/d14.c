#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

void freememoyr(char ***cmd, int cmdnums, int **fd) {
    for (int i = 0; i < cmdnums; i++) {
        free(cmd[i]);
    }
    free(cmd);

    for (int i = 0; i < cmdnums - 1; i++) {
        close(fd[i][0]);
        close(fd[i][1]);
        free(fd[i]);
    }
    free(fd);
}

void runCmd(char ***cmd, int cmdnums, int **fd) {
    for (int i = 0; i < cmdnums; i++) {
        pid_t pid = fork();
        if (pid == -1) {
            perror("fork");
            return;
        }

        if (pid == 0) { // zi
            if (i > 0) {
                if (dup2(fd[i - 1][0], 0) < 0) {
                    perror("dup2");
                    return;
                }
                close(fd[i - 1][0]);
            }
            if (i < cmdnums - 1) {
                if (dup2(fd[i][1], 1) < 0) {
                    perror("dup2");
                    return;
                }
                close(fd[i][1]);
            }
            execvp(cmd[i][0], cmd[i]);
            perror("execvp");
            return;
        } else { // fu
            if (i > 0) {
                close(fd[i - 1][0]);
            }
            if (i < cmdnums - 1) {
                close(fd[i][1]);
            }
        }
    }

    for (int i = 0; i < cmdnums; i++) {
        wait(NULL);
    }
}

int main(int argc, char **argv) {
    if (argc < 4 || argv[1] == NULL) {
        fprintf(stderr, "Usage: %s command1 | command2 | ... \n", argv[0]);
        return 1;
    }

    char ***cmd = malloc(sizeof(char **) * (argc / 2 + 1));
    if (cmd == NULL) {
        fprintf(stderr, "malloc cmd\n");
        return 2;
    }

    int cmdnums = 0;
    int argnums = 0;
    cmd[cmdnums] = malloc(sizeof(char *) * (argc + 1));
    if (cmd[cmdnums] == NULL) {
        fprintf(stderr, "malloc error\n");
        free(cmd);
        return 2;
    }

    for (int i = 1; i < argc; i++) {
        if (strcmp(argv[i], "|") == 0) {
            cmd[cmdnums][argnums] = NULL;
            cmdnums++;
            argnums = 0;
            cmd[cmdnums] = malloc(sizeof(char *) * (argc + 1));
            if (cmd[cmdnums] == NULL) {
                fprintf(stderr, "malloc error\n");
                for (int j = 0; j <= cmdnums; j++) {
                    free(cmd[j]);
                }
                free(cmd);
                return 3;
            }
        } else {
            cmd[cmdnums][argnums++] = strdup(argv[i]);
            if (cmd[cmdnums][argnums - 1] == NULL) {
                fprintf(stderr, "strdup error\n");
                for (int j = 0; j <= cmdnums; j++) {
                    free(cmd[j]);
                }
                free(cmd);
                return 4;
            }
        }
    }
    cmd[cmdnums][argnums] = NULL;
    cmdnums++;

    int **fd = malloc(sizeof(int *) * (cmdnums - 1));
    if (fd == NULL) {
        for (int i = 0; i <= cmdnums; i++) {
            free(cmd[i]);
        }
        free(cmd);
        fprintf(stderr, "malloc fd\n");
        return 2;
    }

    for (int i = 0; i < (cmdnums - 1); i++) {
        fd[i] = malloc(sizeof(int) * 2);
        if (fd[i] == NULL) {
            for (int j = 0; j <= cmdnums; j++) {
                free(cmd[j]);
            }
            free(cmd);
            for (int j = 0; j < i; j++) {
                free(fd[j]);
            }
            free(fd);
            fprintf(stderr, "malloc\n");
            return 2;
        }
        if (pipe(fd[i]) == -1) {
            perror("pipe");
            for (int j = 0; j <= cmdnums; j++) {
                free(cmd[j]);
            }
            free(cmd);
            for (int j = 0; j < i; j++) {
                close(fd[j][0]);
                close(fd[j][1]);
                free(fd[j]);
            }
            free(fd);
            return 4;
        }
    }

    runCmd(cmd, cmdnums, fd);
    freememoyr(cmd, cmdnums, fd);

    return 0;
}