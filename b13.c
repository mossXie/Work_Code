#include <stdio.h>  
  
void print_rwx(short num) {    
    char result[10];
    int i;  
    short mask = 0x100; // h 16  0-》0000 2
  
    for (i = 0; i < 9; i++) {  
        if ((num & mask) != 0) {  
            switch (i % 3) {  
                case 0:  
                    result[i] = 'r';  
                    break;  
                case 1:  
                    result[i] = 'w';  
                    break;  
                case 2:  
                    result[i] = 'x';  
                    break;  
            }  
        } else {  
            result[i] = '-';  
        }  
        mask >>= 1;
    }  
  
    result[9] = '\0';
  
    printf("%s\n", result);  
}  
  
int main() {  
    short num;  

    scanf("%ho", &num);  // o8 x16 d10
    print_rwx(num);  
  
    return 0;  
}