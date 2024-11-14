#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv){
    FILE *fin; // 二进制文件
    FILE *fout; // 文本文件
    int num; // 用于存储从二进制文件中读取的整数

    if(argc < 3){
        fprintf(stderr, "Usage: %s input_binary_file output_text_file\n", argv[0]);
        return 1;
    }

    fin = fopen(argv[1], "rb"); // 以二进制读取模式打开
    if(fin == NULL){
        fprintf(stderr, "Can't open input file %s\n", argv[1]);
        return 2;
    }

    fout = fopen(argv[2], "w"); // 以文本写入模式打开
    if(fout == NULL){
        fprintf(stderr, "Can't open output file %s\n", argv[2]);
        fclose(fin);
        return 2;
    }

    
    fprintf(stderr, "Input file and output file opened successfully.\n");

    while(fread(&num, sizeof(int), 1, fin) == 1){
        fprintf(fout, "%d\n", num); 
    }

    fclose(fin);
    fclose(fout);
    fprintf(stderr, "Files closed.\n");

    return 0;
}