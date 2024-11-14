#include <stdio.h>
#include <math.h>

int main(int argc, char **argv){
    FILE* fin;//文本文件
    FILE* fout;//二进制文件
    unsigned int num;
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
        fprintf(stderr,"Can't open file %s\n",argv[2]);
        fclose(fin);
        return 2;
    }
    /*while(fscanf(fin, "%d", &num) == 1){
        fwrite(&num, sizeof(int), 1, fout);
    }*/
    while(fread(&num, sizeof(unsigned int), 1, fin) == 1){
        fprintf(fout, "%d\n", num);
    }
    fclose(fin);
    fclose(fout);
    return 0;
}