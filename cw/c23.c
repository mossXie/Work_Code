#include <stdio.h>
#include <stdlib.h>

#define SIZE 51

int main(int argc, char **argv){
    FILE *fin, *fout;
    char buf[SIZE];
    int numStrCopy = 0;

    if(argc < 3){
        fprintf(stderr, "Use: %s input_file output_file num of string\n", argv[0]);
        return 1;
    }
    fin = fopen(argv[1], "r");
    if(fin == NULL){
        fprintf(stderr, "Can't open file %s\n", argv[1]);
        return 2;
    }
    fout = fopen(argv[2],"w");
    if(fout == NULL){
        fprintf(stderr,  "Can't open file %s\n", argv[2]);
        fclose(fin);
        return 2;
    }
    numStrCopy = atoi(argv[3]);
    if (numStrCopy <= 0){
        fprintf(stderr, "Not correct number\n");
        fclose(fin);
        fclose(fout);
        return 3;
    }

    int ch;
    int count = 0;
    while((ch = fgetc(fin))!= EOF && count < numStrCopy){
        if(ch == '\n'){
            count++;
        }
        fputc(ch, fout);
    }
    fclose(fin);
    fclose(fout);
    return 0;
}