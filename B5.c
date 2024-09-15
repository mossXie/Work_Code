#include <stdio.h>

int main() {
    long long cont = 0, sum = 0;
    int ch;
    long inReadFlag = 0;

    while (1) {
        ch = getchar();
        if (((ch == '\n') || (ch == EOF)) && (cont == 0)) {
            break;
        }

        inReadFlag = 1;
        // first symbol error
        if ((ch <'0' || ch >'9') && cont == 0)
        {
            printf("0");
            return 0;
        }
        
        if ((ch == '\n') || (ch == EOF)) {
            printf("%lld ", sum);
            break;
        } else if (ch >= '0' && ch <= '9') {
            if (ch == '5') {
                cont++;
                continue;
            } else {
                sum += ch - '0';
                cont++;
            }
        } else if (ch == ' ') {
            printf("%lld ", sum);
            sum = 0;
        } else {
            break;
        }
    }

    if (!inReadFlag) {
        printf("-1");
    }

    return 0;
}