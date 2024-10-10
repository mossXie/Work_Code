/*#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int Row;
    int Col;
    int size;
    int cont;
    int **Matr;
} sizeMatr;

void initMatr(sizeMatr *m, int row, int col);

void freeMatr(sizeMatr *m);

int main() {
    sizeMatr m;
    int row, col;

    scanf("%d %d", &row, &col);

    initMatr(&m, row, col);

    for (int i = 0; i < m.Row; i++) {
        for (int j = 0; j < m.Col; j++) {
            m.Matr[i][j] = rand() % 100;
            printf("%d ", m.Matr[i][j]);
        }
        printf("\n");
    }

    freeMatr(&m);

    return 0;
}

void initMatr(sizeMatr *m, int row, int col) {
    m->Row = row;
    m->Col = col;
    m->Matr = (int **)malloc(row * sizeof(int *));
    for (int i = 0; i < row; i++) {
        m->Matr[i] = (int *)malloc(col * sizeof(int));
    }
}

void freeMatr(sizeMatr *m) {
    for (int i = 0; i < m->Row; i++) {
        free(m->Matr[i]);
    }
    free(m->Matr);
}*/
/*#include <stdio.h>
#include <stdlib.h>

int main() {
    int Row1 = 0, Col1 = 0, Row2 = 0, Col2 = 0;
//1
    scanf("%d %d", &Row1, &Col1);
    int **Matr1 = (int **)malloc(Row1 * sizeof(int *));
    for(int i = 0; i < Row1; i++){
        Matr1[i] = (int *)malloc(Col1 * sizeof(int));
        if(Matr1[i] == NULL){
            printf("Can't allocate memory\n");
            for(int j = 0; j < i; j++){
                free(Matr1[j]); 
            }
            free(Matr1);
            printf("-1\n");
            return 1;
        }
    }
    for(int i = 0; i < Row1; i++){
        for(int j = 0; j < Col1; j++){
            scanf("%d", &Matr1[i][j]); 
        }
    }
// read
    scanf("%d %d", &Row2, &Col2);
//C1 != R2
     if (Col1 != Row2) {
        printf("-1\n");
        freeMatr(Matr1, Row1);
        return 0;
    }
// Matr2
    int **Matr2 = (int **)malloc(Row2 * sizeof(int *));
    for(int i = 0; i < Row1; i++){
        Matr2[i] = (int *)malloc(Col2 * sizeof(int));
        if(Matr2[i] == NULL){
            printf("Can't allocate memory\n");
            for(int j = 0; j < i; j++){
                free(Matr2[j]); 
            }
            free(Matr2);
            printf("-1\n");
            return 1;
        }
    }
    for(int i = 0; i < Row2; i++){
        for(int j = 0; j < Col2; j++){
            scanf("%d", &Matr2[i][j]); 
        }
    }

    return 0;
}

#include <stdio.h>
#include <stdlib.h>

int** crtMatr(int rows, int cols);
void freeMatr(int** matrix, int rows);
int** MatrMul(int** mat1, int rows1, int cols1, int** mat2, int rows2, int cols2);
void Mprint(int** matrix, int rows, int cols);

int main() {
    int Row1, Col1, Row2, Col2;
    int** mat1, **mat2, **result;

    scanf("%d %d", &Row1, &Col1);

    mat1 = crtMatr(Row1, Col1);
    for (int i = 0; i < Row1; i++) {
        for (int j = 0; j < Col1; j++) {
            scanf("%d", &mat1[i][j]);
        }
    }

    scanf("%d %d", &Row2, &Col2);

    if (Col1 != Row2) {
        printf("-1\n");
        freeMatr(mat1, Row1);
        return 0;
    }
    mat2 = crtMatr(Row2, Col2);
    
    for (int i = 0; i < Row2; i++) {
        for (int j = 0; j < Col2; j++) {
            scanf("%d", &mat2[i][j]);
        }
    }

    result = MatrMul(mat1, Row1, Col1, mat2, Row2, Col2);

    Mprint(result, Row1, Col2);

    freeMatr(result, Row1);
    freeMatr(mat2, Row2);
    freeMatr(mat1, Row1);

    return 0;
}
// test and create matrix
int** crtMatr(int rows, int cols) {
    int** matrix = (int**)malloc(rows * sizeof(int*));
    if (matrix == NULL){
        printf("-1\n");
        return NULL;
    }
    for (int i = 0; i < rows; i++) {
        matrix[i] = (int*)malloc(cols * sizeof(int));
        if (matrix[i] == NULL){
            printf("-1\n");
            for (int j = 0; j < i; j++) {
                free(matrix[j]);
                }
            free(matrix);
            return 1;
        }
    }
    return matrix;
}
// free
void freeMatr(int** matrix, int rows) {
    for (int i = 0; i < rows; i++) {
        free(matrix[i]);
    }
    free(matrix);
}
//mul
int** MatrMul(int** mat1, int rows1, int cols1, int** mat2, int rows2, int cols2) {
    if (cols1 != rows2) {
        printf("-1\n");
        return 1;
    }
    int** result = crtMatr(rows1, cols2);
    for (int i = 0; i < rows1; i++) {
        for (int j = 0; j < cols2; j++) {
            for (int k = 0; k < cols1; k++) {
                result[i][j] += mat1[i][k] * mat2[k][j];
            }
        }
    }
    return result;
}


void Mprint(int** matrix, int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}*/
#include <stdio.h>
#include <stdlib.h>

int** crtMatr(int rows, int cols);
void freeMatr(int** matrix, int rows);
int** MatrMul(int** mat1, int rows1, int cols1, int** mat2, int rows2, int cols2);
void Mprint(int** matrix, int rows, int cols);

int main() {
    int Row1, Col1, Row2, Col2;
    int** mat1, **mat2, **result;

    scanf("%d %d", &Row1, &Col1);

    mat1 = crtMatr(Row1, Col1);
    for (int i = 0; i < Row1; i++) {
        for (int j = 0; j < Col1; j++) {
            scanf("%d", &mat1[i][j]);
        }
    }

    scanf("%d %d", &Row2, &Col2);

    mat2 = crtMatr(Row2, Col2);
    
    for (int i = 0; i < Row2; i++) {
        for (int j = 0; j < Col2; j++) {
            scanf("%d", &mat2[i][j]);
        }
    }

    if (Col1 != Row2) {
        printf("-1\n");
        freeMatr(mat1, Row1);
        return 0;
    }

    result = MatrMul(mat1, Row1, Col1, mat2, Row2, Col2);

    if (result != NULL) {
        Mprint(result, Row1, Col2);
        freeMatr(result, Row1);
    }

    freeMatr(mat2, Row2);
    freeMatr(mat1, Row1);

    return 0;
}

int** crtMatr(int rows, int cols) {
    int** matrix = (int**)malloc(rows * sizeof(int*));
    if (matrix == NULL) {
        return NULL;
    }
    for (int i = 0; i < rows; i++) {
        matrix[i] = (int*)malloc(cols * sizeof(int));
        if (matrix[i] == NULL) {
            for (int j = 0; j < i; j++) {
                free(matrix[j]);
            }
            free(matrix);
            return NULL;
        }
    }
    return matrix;
}

void freeMatr(int** matrix, int rows) {
    for (int i = 0; i < rows; i++) {
        free(matrix[i]);
    }
    free(matrix);
}

int** MatrMul(int** mat1, int rows1, int cols1, int** mat2, int rows2, int cols2) {
    if (cols1 != rows2) {
        return NULL;
    }
    int** result = crtMatr(rows1, cols2);
    if (result == NULL) {
        return NULL;
    }
    for (int i = 0; i < rows1; i++) {
        for (int j = 0; j < cols2; j++) {
            result[i][j] = 0;
            for (int k = 0; k < cols1; k++) {
                result[i][j] += mat1[i][k] * mat2[k][j];
            }
        }
    }
    return result;
}

void Mprint(int** matrix, int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}