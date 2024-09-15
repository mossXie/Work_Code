#include<stdio.h>

int main(){

    long num, cnt=0, sum=0; char c;

    while(((c=getchar())!='\n') && (c!=EOF)){
        if(c=='\n'){continue;}
        else{ungetc(c,stdin);}
        if(scanf("%ld",&num)==0){break;}
        else if(cnt==0){
            sum = num;
        }
        else if(cnt%2==1){
            sum = sum + num;
        }
        else if(cnt%2==0){
            sum = sum - num;
        }
        cnt++;
    }
    printf("%ld", sum);

    return 0;
}