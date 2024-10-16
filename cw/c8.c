#include <stdio.h>
#include <stdlib.h>

int sumMax(int **A, int Row, int Col){
    int sum = 0;    
    for(int i = 0; i < Row; i++){
        int jmax = 0;
        for(int j = 1; j < Col; j++){
            if(A[i][j] > A[i][jmax]){
                jmax = j;
            }
        }
        sum += A[i][jmax];
    }
    return sum;
}

int main(){
    int **Matr1 = NULL;
    int Row, Col;

    scanf("%d %d", &Row, &Col);

    Matr1 = (int **)malloc(Row * sizeof(int*)); 
    if(Matr1 == NULL){
        printf("can't allocate memory\n");
        return 1;
    }
    for(int i = 0; i < Row; i++){
        Matr1[i] = (int *)malloc(Col * sizeof(int));
        if(Matr1[i] == NULL){
            printf("Can't allocate memory\n");
            for(int j = 0; j < i; j++){
                free(Matr1[j]); 
            }
            free(Matr1);
            return 1;
        }
    }
    for(int i = 0; i < Row; i++){
        for(int j = 0; j < Col; j++){
            scanf("%d", &Matr1[i][j]); 
        }
    }
    printf("%d\n", sumMax(Matr1, Row, Col)); 
    for(int i = 0; i < Row; i++){
        free(Matr1[i]); 
    }
    free(Matr1);
    Matr1 = NULL;
    return 0;
}