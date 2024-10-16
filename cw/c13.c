#include <stdio.h>
#include <string.h>

double sum (double);
double mul (double);

int main (int argc,char** argv)
{
    double res;
    int N;
    double (*fptr)(double);

    if (argc < 4)
    {
        printf("Use: %s sum/mul N array_of_Nnumbers\n",argv[0]);
        return 1;
    }
    if ( sscanf(argv[2],"%d",&N) != 1)
    {
        printf("Isn't a number\n");
        return 2;
    }
    if (strcmp(argv[1],"sum") == 0)
        fptr = sum;
    else if (strcmp(argv[1],"mul") == 0)
        fptr = mul;
    else
    {
        printf("Wrong function\n");
        return 3;
    }
    int count = argc > N+3 ? N+3 : argc;
    for (int i = 3 ; i < count ; i++)
    {
        double x;
        int k = sscanf(argv[i],"%lf",&x);
        if (k != 1)
            break;
        res = fptr(x);
    }
    printf("%.3f\n",res);
    return 0;
}

double sum (double num)
{
    static double sum = 0.;
    sum += num;
    return sum;
}
double mul (double num)
{
    static double mul = 1.;
    mul *= num;
    return mul;
}