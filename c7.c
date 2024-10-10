#include <stdio.h>

enum { Row = 5, Col = 5 };

int average(int arr[Row][Col]) {
    int backnum = 0;
    int cont = 0;
    double avg;

    for (int i = 0; i < Row; i++) {
        backnum += arr[i][i];
    }

    avg = backnum / 5;

    for (int i = 0; i < Row; i++) {
        for (int j = 0; j < Col; j++) {
            if (arr[i][j] > avg && arr[i][j] > 0) {
                cont++;
            }
        }
    }

    return cont;
}

int main() {
    int arr[Row][Col] = {0};
    int num = 0;

    for (int i = 0; i < Row; i++) {
        for (int j = 0; j < Col; j++) {
            scanf("%d", &arr[i][j]);
        }
    }

    printf("%d\n", average(arr));

    return 0;
}