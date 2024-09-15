#include <stdio.h>

int main(){
    int x, y, z;
    long long sum = 0;

    scanf("%d %d %d",&x,&y,&z);

    sum = (long) x + y + z;
    printf("%ld+%d+%d=%lld",x,y,z,sum);
    return 0;
}