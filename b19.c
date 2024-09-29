#include <stdio.h>

int str_length(char *str){
    int length = 0;
    while (*str != '\0') {
        length++;
        str++;
    }
    return length;
}

int main(){
    char str[100];
    scanf("%99[^\n]",str);//"[^sybol]"扫描此处表示读取任意99个字符除非是/n
    // fgets(str);
    printf("%d\n",str_length(str));
    return 0;
}