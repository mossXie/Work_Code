#include <stdio.h>
#include <string.h>
#include <math.h>

double tan(double num) {
    double num1 = sin(num);
    double num2 = cos(num);
    if(num2 != 0){
        return num1/num2;
    }else return NAN;
}

int main(int argc, char **argv) {
    char *str[] = {"sin", "cos", "tan", "log", "fabs", "sqrt", "exp"};
    double (*func[])(double) = {sin, cos, tan, log, fabs, sqrt, exp};
    double a, b, h;
    int i;

    if (argc != 5) {
        printf("-1\n");
        return 1;
    }

    for (i = 0; i < 7; i++) {
        if (!strcmp(argv[1], str[i])) {
            break;
        }
    }

    if (i == 7) {
        printf("-1\n");
        return 2;
    }

    if (sscanf(argv[2], "%lf", &a) != 1 || sscanf(argv[3], "%lf", &b) != 1 || sscanf(argv[4], "%lf", &h) != 1) {
        printf("-1\n");
        return 3;
    }

    if (((a > b) && (h > 0)) || ((a < b) && (h < 0 )) || (h == 0))  {
        printf("-1\n");
        return 4;
    }


    for (; a <= b; a += h) {
        printf("%.3lf ", func[i](a));
    }
    printf("\n");

    return 0;
}