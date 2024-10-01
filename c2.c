#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;
    scanf("%d", &n);

    int *arr = (int*)malloc(n * sizeof(int)); 
    if (arr == NULL) {
        return 1;
    }

    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    int *result = (int*)malloc(n * sizeof(int));
    if (result == NULL) {
        free(arr);
        return 1;
    }
    int count = 0;

    for (int i = 0; i < n; i++) {
        int temp = arr[i];
        int hundreds = temp / 100;
        int tens = (temp / 10) % 10;
        if (tens == 0) {
            result[count++] = arr[i];
        }
    }

    for (int i = 0; i < count; i++) {
        if (i != 0) {
            printf(" ");
        }
        printf("%d", result[i]);
    }
    
    printf("\n");
    free(arr);
    free(result);

    return 0;
}