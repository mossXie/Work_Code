#include <stdio.h>

int divThree(int n) {
    int count = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            int product = i * j;
            while (product) {
                if (product % 10 == 3) {
                    count++;
                }
                product /= 10;
            }
        }
    }
    return count;
}

int main() {
    int N;
    scanf("%d", &N);
    printf("%d\n", divThree(N));
    return 0;
}