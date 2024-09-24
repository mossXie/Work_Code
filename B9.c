#include <stdio.h>

long long sumCycle();

int main() {
    long long sum1 = 0, sum2 = 0;

    sum1 = sumCycle();
    if (sum1 == -1)
    {
        return 0;
    }

    sum2 = sumCycle();
    if (sum2 == -1)
    {
        return 0;
    }
    
    

    if (sum1 == sum2) {
        printf("Equal\n");
    } else if (sum1 > sum2) {
        printf("First\n");
    } else if(sum1 < sum2){
        printf("Second\n");
    }

    return 0;
}

long long sumCycle() {
    int ch;
    long long sum = 0;
    int cycleFlag = 0;
    while ((ch = getchar()) != ' ' && ch != '\n' && ch != EOF) {
        if (ch == '=')
        {
            cycleFlag += 1;
            sum += 1;
        }else{
            printf("Incorrect\n");
            return -1;
        }
        
    }
    if (cycleFlag == 0)
    {
        printf("Incorrect\n");
        return -1;
    }
    
    return sum;
}