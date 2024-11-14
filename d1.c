#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>
#include <stdatomic.h>
#define BUF_SIZE 128

int main(int argc, char **argv){
    int fd1, fd2, size;
    char buf[BUF_SIZE];
    if(argc < 3){
        fprintf(stderr, "Use: %s file_source file_dest\n", argv[0]);
        return 1;
    }

    fd1 = open(argv[1], O_RDONLY);
    if(fd1 == -1){
        perror("open");
        return 2;
    }

    struct stat s;
    stat(argv[1], &s);
    fd2 = open(argv[2], O_WRONLY | O_CREAT | O_TRUNC, s.st_mode);
    if(fd2 == -1){
        perror("open2");
        close(fd1);
        return 2;
    }

    while((size = read(fd1, buf, BUF_SIZE)) > 0)
        write(fd2, buf, size);
    close(fd1);
    close(fd2);

    return 0;
}