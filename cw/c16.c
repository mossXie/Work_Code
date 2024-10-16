#include <stdio.h>
#include <string.h>
#define MAX_STRINGS 30

struct color
{   
    char name_color[20];//color name
    int count;//how much times this color showed
};

int main(){
    struct color Color[MAX_STRINGS];
    char buf[20];
    int num_colors = 0;

    while(scanf("%19s",buf)!=EOF){
        int exist = 0;
        for(int i = 0;i < num_colors;i++){
            if(strcmp(Color[i].name_color,buf) == 0){
                Color[i].count++;
                exist = 1;
            }
        }
    if(!exist){
        if (num_colors >= MAX_STRINGS)
                break;
        strcpy(Color[num_colors].name_color,buf);
        Color[num_colors].count = 1;
        num_colors++;
        }
    }
    for (int i = 0;i<num_colors;i++)
        printf("%s %d\n",Color[i].name_color, Color[i].count);

    return 0;
}