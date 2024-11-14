/*#include <stdio.h>

#define CONT 20

typedef struct date{
    unsigned int y;
    unsigned int m;
    unsigned int d;
}date;

int realdata(date temp){
    int i = 0;
    int mat1[12] = {31,28,31,30,31,30,31,31,30,31,30,31};
    int mat2[12] = {31,29,31,30,31,30,31,31,30,31,30,31};

    if(temp.m < 1 || temp.m >12  ){
        i = temp.m % 4;
    }else return 0;

    if(i == 0){
        if(temp.d <= mat2[temp.m] && temp.d > 0){
            return 1;
        }else return 0;
    }
    if(i != 0){
        if(temp.d <= mat1[temp.m] && temp.d > 0){
            return 1;
        }else return 0;
    }
}

void popsort(date *dates, int flag){
    for(int i = 0; i < flag - 1; i++){
        for(int j = i + 1; j < flag; j++){
            int swapfalg = 0;
            if(dates[i].y > dates[j].y){
                swapfalg = 1;
            }else if(dates[i].y < dates[j].y){
                CONTinue;
            else if(dates[i].y == dates[j].y){
                if(dates[i].m > dates[j].m){
                    swapfalg = 1;
                }else if(dates[i].m = dates[j].m){
                    CONTinue;
                }else if(dates[i].m == dates[j].m){
                    if(dates[i].d > dates[j].d){
                        swapfalg = 1;
                    }
                }
            }
            if(swapfalg){
                date reslt = dates[i];
                dates[i] = dates[j];
                dates[j] = reslt;
            }
        }
    }
}

int main(){
    date dates[20];
    int flag = 0, x = 0;
    date temp;

    while(scanf("%u %u %u", &temp.y, &temp.m, &temp.d) == 3){
        x = realdata(temp);
        if(x && flag < 20){
            flag++;
            dates[flag] = temp;
        }else{CONTinue;}
    }
    popsort(dates, flag);

    for(int i = 0; i < flag; i++){
        printf("%u %u %u\n", dates[i].y, dates[i].m, dates[i].d);
    }

}*/
#include <stdio.h>

#define CONT 20

typedef struct date{
    unsigned int y;
    unsigned int m;
    unsigned int d;
}date;

int realdata(date temp){
    //int rl = 0;
    int mat1[12] = {31,28,31,30,31,30,31,31,30,31,30,31};
    int mat2[12] = {31,29,31,30,31,30,31,31,30,31,30,31};

    if((temp.m >= 1) && (temp.m <= 12)){
        //rl = temp.y % 4; // 检查年份是否为闰年
        int isLeapYear = (temp.y % 4 == 0);
        if(isLeapYear){
            if(temp.d <= mat2[temp.m-1] && temp.d > 0){
                return 1;
            }else return 0;
        }else{
            if(temp.d <= mat1[temp.m-1] && temp.d > 0){
                return 1;
            }else return 0;
        }
    }
    return 0;
}

void popsort(date *dates, int flag){
    for(int i = 0; i < flag - 1; i++){
        for(int j = i + 1; j < flag; j++){
            int swapflag = 0;
            if(dates[i].y > dates[j].y){
                swapflag = 1;
            }else if(dates[i].y == dates[j].y){
                if(dates[i].m > dates[j].m){
                    swapflag = 1;
                }else if(dates[i].m == dates[j].m){
                    if(dates[i].d > dates[j].d){
                        swapflag = 1;
                    }
                }
            }
            if(swapflag){
                date reslt = dates[i];
                dates[i] = dates[j];
                dates[j] = reslt;
            }
        }
    }
}

int main(){
    date dates[CONT];
    int flag = 0, x = 0;
    date temp;

    while(scanf("%u %u %u", &temp.y, &temp.m, &temp.d) == 3){
        x = realdata(temp);
        if(x && flag < CONT){
            dates[flag] = temp;
            flag++;
        }
    }

    popsort(dates, flag);

    for (int i = 0; i < flag; i++) {
        if (dates[i].m < 10 && dates[i].d < 10) {
            printf("%u 0%u 0%u\n", dates[i].y, dates[i].m, dates[i].d);
        } else if (dates[i].m < 10) {
            printf("%u 0%u %u\n", dates[i].y, dates[i].m, dates[i].d);
        } else if (dates[i].d < 10) {
            printf("%u %u 0%u\n", dates[i].y, dates[i].m, dates[i].d);
        }else{
            printf("%u %u %u\n", dates[i].y, dates[i].m, dates[i].d);
        }
    }

    return 0;
}