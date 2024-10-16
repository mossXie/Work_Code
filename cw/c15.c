#include <stdio.h>
#include <string.h>

struct color {
    char name[20];
    int count;
};

int main() {

    struct color white = {"WHITE", 0};
    struct color black = {"BLACK", 0};
    struct color other = {"OTHER", 0};
    char buf[20];


    while (scanf("%19s", buf) != EOF) {
        if (strcmp(buf, white.name) == 0) {
            white.count++;
        } else if (strcmp(buf, black.name) == 0) {
            black.count++;
        } else {
            other.count++;
        }
    }

    printf("%s %d\n", white.name, white.count);
    printf("%s %d\n", black.name, black.count);
    printf("%s %d\n", other.name, other.count);

    return 0;
}