#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int main(int argc, char **argv) {
    if (argc < 3) {
        fprintf(stderr, "Usage: %s source_file target_file", argv[0]);
        return 1;
    }

    int fin = open(argv[1], O_RDWR);
    if (fin == -1) {
        perror("open");
        return 2;
    }

    struct stat s;
    if (stat(argv[1], &s) == -1) {
        perror("stat");
        close(fin);
        return 3;
    }

    int fout = open(argv[2], O_WRONLY | O_CREAT | O_TRUNC, s.st_mode);
    if (fout == -1) {
        perror("fout");
        close(fin);
        return 4;
    }

    long fsize = s.st_size;
    if (fsize % sizeof(int) != 0) {
        fprintf(stderr, "Invalid file format");
        close(fin);
        close(fout);
        return 5;
    }

    long arrnum = fsize / sizeof(int);
    int buf[arrnum]; 

    if (read(fin, buf, fsize) != fsize) {
        perror("read");
        close(fin);
        close(fout);
        return 7;
    }

    for (long i = 0; i < arrnum -1 ; i++) {
        for (long j = 0; j < arrnum - 1 - i; j++) {
            if (buf[j] < buf[j + 1]) {
                swap(&buf[j], &buf[j + 1]);
            }
        }
    }

    if (write(fout, buf, fsize) != fsize) {
        perror("write");
        close(fin);
        close(fout);
        return 8;
    }

    close(fin);
    close(fout);
    return 0;
}