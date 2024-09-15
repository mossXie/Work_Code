#include<stdio.h>

int readedsymbol = 0, symbol = 1, cycleFlag = 0;
long long num = 0, sum = 0;

int main() {

    while ((readedsymbol = scanf("%lld", &num)) != EOF) {
        if (readedsymbol == 1) {
            cycleFlag ++;
        } else {
            break;
        }
        if (cycleFlag == 1) {
            sum = sum + num;
            continue;
        }
        if (cycleFlag > 1 && readedsymbol == 1) {
            if (symbol == 1) {
                sum += num;
                symbol = 0;
                continue;

            } else if (symbol == 0) {
                sum -= num;
                symbol = 1;
                continue;
            }
        }
    }

    printf("%lld\n", sum);
    return 0;
}
/* while (scanf("%lld", &num) == 1) {
        sum += sign * num; // 根据符号加或减
        sign = -sign; // 翻转符号
 }*/