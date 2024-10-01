#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int main() {
    int n;
    scanf("%d", &n);

    int *arr = (int *)malloc(n * sizeof(int));

    int sum = 0, min = INT_MAX, max = 0;
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
        sum += arr[i];
        if (arr[i] < min) min = arr[i];
        if (arr[i] > max) max = arr[i]; 
    }
    long long totalSum = (long long)(max * (max + 1) / 2) - (long long)((min - 1) * min / 2);

    int num = totalSum - sum;

    printf("%d\n", num);
    free(arr);

    return 0;
}