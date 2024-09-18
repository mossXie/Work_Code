#include <stdio.h>
void printSumtime(int yy,int mm,int dd){
    unsigned short sum = 0,pack_data = 0,mask = 1 <<(8*sizeof(short)-1);

    pack_data = (yy << 9) | (mm << 5) | dd;
    sum = pack_data;
    for(;mask;mask >>= 1){
        if(mask & pack_data){
            printf("1");
        }else printf("0");
    }
    printf("\n");
    printf("%hd",sum);

}
int main(){
    int yy, mm, dd;
    scanf("%d %d %d",&yy, &mm, &dd);
    if((yy < 0) || (yy > 99) || (mm < 1) || (mm > 12)|| (dd < 1) || (dd > 31)){
        return 1;
    }
    printSumtime(yy,mm,dd);
    return 0;
}