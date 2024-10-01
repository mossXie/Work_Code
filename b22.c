#include <stdio.h>
#include <stdbool.h>

int main() {
    char arr1[1001];
    char arr2[1001] = {0};
    bool symbolBool[256] = {false};
    int index = 0;

    scanf("%[^\n]", arr1);

    for (int i = 0; arr1[i] != '\0'; i++) {
        if ((arr1[i] >= 'a' && arr1[i] <= 'z') || (arr1[i] >= 'A' && arr1[i] <= 'Z')) {
            if (!symbolBool[arr1[i]]) {
                arr2[index++] = arr1[i];
                symbolBool[arr1[i]] = true;
            }
        }
    }
    arr2[index] = '\0';
    printf("%s", arr2);

    return 0;
}