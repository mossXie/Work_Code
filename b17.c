#include <stdio.h>
#include <math.h>
#include <stdlib.h>

#define N 10

double MAX(double arr[], int size);
double MIN(double arr[], int size); 
void abs_arr(double arr[], int size);
double turn(double arr[], int size);

int main(){
    double num = 0, arr[N];
    int tip,readFlag;
    for (int i = 0; i < N; i++)
    {
        scanf("%lf", &num);
        arr[i] = num;
    }
    readFlag = scanf("%d", &tip);
    if (readFlag != 1)
    {
        printf("-1");
        return 0;
    }
    
    switch (tip)
    {
    case 0:
        printf("%.1lf\n", MAX(arr, N));
        break;
    case 1:
        printf("%.1lf\n", MIN(arr, N));
        break;
    case 2:
        abs_arr(arr, N);
        break;
    case 3:printf("%.1lf",MAX(arr, N)+MIN(arr, N));
        break;
    case 4:
        printf("%.1lf",turn(arr, N));
        break;
    default:
        printf("-1\n");
        break;
    }
    
    return 0;
}

double MAX(double arr[], int size){
    double max = arr[0];
    for(int i = 1; i < size; i++){
        if(arr[i] > max){
            max = arr[i];
        }
    }
    return max;
}

double MIN(double arr[], int size){
    double min = arr[0];
    for(int i = 1; i < size; i++){
        if(arr[i] < min){
            min = arr[i];
        }
    }
    return min;
}

void abs_arr(double arr[], int size){
    for(int i = 0; i < size; i++){
        arr[i] = fabs(arr[i]);
        printf("%.1lf ",arr[i]);
    }
}


double turn(double arr[], int size){
    double sum = 0;
    for(int i = 0; i < size - 1; i++){
        sum += arr[i] * arr[i+1];
    }
    return sum;
}