#include <stdio.h>

int main() {
    int cycleFlag = 0, zeroFlag = 0, fuhaoFlag = 0, numFlag = 0;
    char cr;

    while ((cr = getchar()) != ' ' && cr != '\n' && cr != EOF) {
        cycleFlag += 1;
        if (cr == '-' && cycleFlag == 1 && fuhaoFlag == 0)
        {
            fuhaoFlag = 1;
            continue;    
        }else if (cr == '-' && fuhaoFlag == 1 )
        {
            printf("NO");
            return 0;
        }
        
        
        if (cr >= '0' && cr <= '9' && cycleFlag >= 1)
        {
            if (cr == '0' && fuhaoFlag == 1 && numFlag == 0)
            {
                printf("NO");
                return 0;
            }else if (cr == '0' && fuhaoFlag == 0 && zeroFlag == 0)
            {
                zeroFlag = 1;
                continue;
            }else if (cr == '0' && zeroFlag == 1 && cycleFlag == 2)
            {
                printf("NO");
                return 0;
            }
            
            numFlag += 1;

            if (numFlag >= 1)
            {
                continue;
            }
            
        }printf("NO");return 0;    
    }

    if (fuhaoFlag == 1 && numFlag == 0){
        printf("NO");
        return 0;
    }

     if (cycleFlag >= 1)
     {
        printf("YES");
     }else printf("NO");
     
    return 0;
}