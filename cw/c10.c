#include <stdio.h>
#include <string.h>

int is_palindrom(char *str){
    int l = 0;
    int r = (strlen(str) - 1);
    while(l < r){
        if(str[l] == str[r]){
            l++;
            r--;
        }else{
            return 0;
        }
    }
    return 1;
}

int main(int argc, char *argv[]){
    if(argc != 2){
        return 1;
    }
    if(is_palindrom(argv[1])){
        printf("YES");
    }else{
        printf("NO");
    }

}