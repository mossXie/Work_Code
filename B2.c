#include <stdio.h>  
  
int main() {  
    int N;  
    unsigned long long num1, num2, sum;     
    unsigned long long arr[51];  
  
    num1 = 0;  
    num2 = 1;  
    arr[0] = 0;  
    arr[1] = 1;  

    for (int i = 2; i < 51; i++) {  
        sum = num1 + num2;  
        arr[i] = sum;  
        // sum = 0; // 这行不需要，因为sum每次都会被重新赋值  
        num1 = num2;  
        num2 = arr[i]; 
    }  

    sum = 0;  

    scanf("%d", &N);  
  
    for (int i = 0; i < N; i++) {  
        sum += arr[i];  
    }  
  
    // 打印求和结果  
    printf("%llu", sum);  
  
    return 0;  
}