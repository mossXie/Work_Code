#include <stdio.h>

void printDate(unsigned short num) {
    int yy = 0, mm = 0, dd = 0;
    // 提取年、月、日
    yy = num >> 9;
    mm = (num >> 5) & 0x0F;
    dd = num & 0x1F;

    if (yy >= 50) {
        yy = 1900 + yy;
    } else {
        yy = 2000 + yy;
    }

    printf("%d %d %d\n", yy, mm, dd);
}

int main() {
    unsigned short num;
    scanf("%hu", &num);
    printDate(num);
    return 0;
}