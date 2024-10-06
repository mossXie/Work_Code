/*#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

void transformString(char *str) {
    int len = strlen(str);
    int lowerIndex = 0, upperIndex = 0;

    char *lower = malloc(len + 1);
    char *upper = malloc(len + 1);
    if (lower == NULL || upper == NULL) {
        printf("Memory allocation failed.\n");
        if (lower) free(lower);
        if (upper) free(upper);
        return;
    }

    for (int i = 0; i < len; i++) {
        if (islower(str[i])) {
            lower[lowerIndex++] = str[i];
        } else if (isupper(str[i])) {
            upper[upperIndex++] = str[i];
        }
    }
    lower[lowerIndex] = '\0';
    upper[upperIndex] = '\0';

    memcpy(str, lower, lowerIndex + 1);
    memcpy(str + lowerIndex, upper, upperIndex + 1);

    free(lower);
    free(upper);
}

int main() {
    char *input = malloc(1001 * sizeof(char));
    if (input == NULL) {
        printf("Memory allocation failed.\n");
        return 1;
    }

    if (fgets(input, 1001, stdin) == NULL) {
        free(input);
        return 1;
    }

    size_t len = strlen(input);
    if (len > 0 && input[len - 1] == '\n') {
        input[--len] = '\0';
    }

    transformString(input);

    printf("%s\n", input);

    free(input);

    return 0;
}
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

void transformString(char *str) {
    int len = strlen(str);
    int upperCont = 0, lowerCont = 0;
    for (int i = 0; i < len; ++i) {
        if (isupper(str[i])) {
            ++upperCont;
        } else if (islower(str[i])) {
            ++lowerCont;
        }
    }

    int upperIndex = 0, lowerIndex = 0;
    for (int i = 0; i < len; ++i) {
        if (isupper(str[i])) {
            if (upperIndex < upperCont) {
                str[upperIndex + lowerCont] = str[i];
                ++upperIndex;
            }
        } else if (islower(str[i])) {
            if (lowerIndex < lowerCont) {
                str[lowerIndex] = str[i];
                ++lowerIndex;
            }
        }
    }
}

int main() {
    char *input = malloc(1001 * sizeof(char));
    if (input == NULL) {
        printf("Memory allocation failed.\n");
        return 1;
    }

    if (fgets(input, 1001, stdin) == NULL) {
        free(input);
        return 1;
    }

    size_t len = strlen(input);
    if (len > 0 && input[len - 1] == '\n') {
        input[--len] = '\0';
    }

    transformString(input);

    printf("%s\n", input);

    free(input);

    return 0;
}*/

/*#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *strcat(char *dest, const char *src) {
    char *ptr = dest; 
    while (*ptr != '\0') {
        ptr++;
    }
    while (*src != '\0') {
        *ptr = *src;
        ptr++;
        src++;
    }
    *ptr = '\0';
    return dest;
}

void convert_string(char str[], int len) {
    char *low = malloc(len + 1);
    char *upr = malloc(len + 1);
    int leb_l = 0, leb_u = 0;
    for (int i = 0; i < len; i++) {
        if (str[i] >= 'a' && str[i] <= 'z') {
            low[leb_l++] = str[i];
        } else if (str[i] >= 'A' && str[i] <= 'Z') {
            upr[leb_u++] = str[i];
        }
    }
    low[leb_l] = '\0';
    upr[leb_u] = '\0';
    strcat(low, upr);
    for (int i = 0; i < leb_l + leb_u; i++) {
        str[i] = low[i];
    }
    free(low);
    free(upr);
}

int main() {
    char *arr = NULL;
    int size = 10;
    int count = 0;

    arr = (char*)malloc(size * sizeof(char));
    if (arr == NULL) {
        printf("Can't allocate memory\n");
        return 0;
    }

    int c;
    while ((c = getchar()) != EOF && c != '\n') {
        if (count >= size - 1) {
            size *= 2;
            char *buf = realloc(arr, size * sizeof(char));
            if (buf == NULL) {
                free(arr);
                printf("Can't realloc memory\n");
                return 0;
            } else {
                arr = buf;
            }
        }
        arr[count++] = c;
    }
    if (count > 0 && arr[count - 1] == '\n') {
        count--;
    }
    arr[count] = '\0';

    convert_string(arr, count);

    for (int i = 0; i < count; i++) {
        printf("%c", arr[i]);
    }
    printf("\n");

    free(arr);
    return 0;
}*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

void transformString(char *str) {
    int len = strlen(str);
    int lowerIndex = 0, upperIndex = 0;

    char *lower = malloc(len + 1);
    char *upper = malloc(len + 1);
    if (lower == NULL || upper == NULL) {
        printf("Memory allocation failed.\n");
        if (lower) free(lower);
        if (upper) free(upper);
        return;
    }

    for (int i = 0; i < len; i++) {
        if (islower(str[i])) {
            lower[lowerIndex++] = str[i];
        } else if (isupper(str[i])) {
            upper[upperIndex++] = str[i];
        }
    }
    lower[lowerIndex] = '\0';
    upper[upperIndex] = '\0';

    memcpy(str, lower, lowerIndex + 1);
    memcpy(str + lowerIndex, upper, upperIndex + 1);

    free(lower);
    free(upper);
}

int main() {
    char *input;
    int len = 0;
    int size = 1001;
    char c;
    input = (char*)malloc(size * sizeof(char));
    if (input == NULL) {
        printf("Memory allocation failed.\n");
        return 1;
    }

    while ((c = getchar()) != EOF && c != '\n')
    {
        if (len >= size - 1) 
        {
            size *= 2;
            char *buf = realloc(input, size * sizeof(char));
            if (buf == NULL) {
                free(input);
                printf("Memory allocation failed.\n");
                return 1;
            } else {
                input = buf;
            }
        }
        input[len++] = c;
        
    }
    
    if (len > 0 && input[len - 1] == '\n') {
        input[--len] = '\0';
    }

    transformString(input);

    printf("%s\n", input);

    free(input);

    return 0;
}