#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int compare_ints(const void *a, const void *b) {
    return *(int*)a - *(int*)b;
}

int main() {
    char input[1001];
    scanf("%[^\n]", input);

    int *numbers = (int*)malloc(10 * sizeof(int));
    if (numbers == NULL) {
        printf("Memory allocation failed.\n");
        return 1;
    }
    int count = 0;
    int size = 10;

    for (int i = 0; input[i] != '\0'; i++) {
        if (isdigit(input[i])) {
            int num = 0;
            while (isdigit(input[i])) {
                num = num * 10 + (input[i] - '0');
                i++;
            }
            if (count >= size) {
                size *= 2;
                int *temp = (int*)realloc(numbers, size * sizeof(int));
                if (temp == NULL) {
                    free(numbers);
                    return 1;
                }
                numbers = temp;
            }
            numbers[count++] = num;
            i--;
        }
    }

    qsort(numbers, count, sizeof(int), compare_ints);

    for (int i = 0; i < count; i++) {
        if (i != 0) {
            printf(" ");
        }
        printf("%d", numbers[i]);
    }
    printf("\n");

    free(numbers);

    return 0;
}