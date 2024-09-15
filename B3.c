#include <stdio.h>

double isPotInRec(double ptx,double pty,
            double ptox1,double ptoy1,double ptox2,double ptoy2);
int main(){
    double ptx, pty, ptox1, ptox2, ptoy1, ptoy2;
    scanf("%lf %lf %lf %lf %lf %lf",
        &ptx, &pty, &ptox1, &ptox2, &ptoy1, &ptoy2);
    
    if (isPotInRec(ptx, pty, ptox1, ptox2, ptoy1, ptoy2))
    {
        printf("YES");
    }else {  
        printf("NO");  
    }  
    
    return 0;
}
double isPotInRec(double ptx,double pty,double ptox1,double ptoy1,double ptox2,double ptoy2){
    double min_x = (ptox1 < ptox2) ? ptox1 : ptox2;  
    double max_x = (ptox1 > ptox2) ? ptox1 : ptox2;  
    double min_y,max_y;
    if (ptoy1 < ptoy2) {  
        min_y = ptoy1;  
        max_y = ptoy2;  
    } else {  
        min_y = ptoy2;  
        max_y = ptoy1;  
    }  
  
    if (ptx >= min_x && ptx <= max_x && pty >= min_y && pty <= max_y) {  
        return 1;   
    } else {  
        return 0;  
    }  
}