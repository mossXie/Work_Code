#include <stdio.h>

int my_strcmp(char *str1, char *str2) {
    int i = 0;
    while (str1[i] != '\0' && str2[i] != '\0') {
        if (str1[i] < str2[i]) {
            return -1;
        } else if (str1[i] > str2[i]) {
            return 1;
        }
        i++;
    }
    if (str1[i] == '\0' && str2[i] == '\0') {
        return 0;
    } else if (str1[i] == '\0') {
        return -1;
    } else {
        return 1;
    }
}

int main() {
    char str1[101];
    char str2[101];

    scanf("%100[^\n]", str1);
    getchar();
    scanf("%100[^\n]", str2);

    int num = my_strcmp(str1, str2);
    if (num < 0) {
        printf("Second");
    } else if (num > 0) {
        printf("First");
    } else {
        printf("Equal");
    }
    return 0;
}