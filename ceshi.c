/*#include <stdio.h>

int main() {
    int Nx, Ny;
    scanf("%d %d", &Nx, &Ny);
    double xStep = 1.0 / (Nx - 1);  
    double yStep = 1.0 / (Ny - 1);  
 
// 使用两个嵌套的循环来生成和打印坐标  
    for (int i = 0; i < Ny; i++) {  
        double y = (1 - (i * yStep));  
        for (int j = 0; j < Nx; ++j) {  
            double x = j * xStep;   
            printf("(%.3f, %.3f) ", x, y);  
        }  
    printf("\n");  
    }  

return 0;
}
#include <stdio.h>  
#include <stdlib.h>  
  
// 定义双链表节点结构  
typedef struct Node {  
    double x, y;  
    struct Node* next;  
    struct Node* prev;  
} Node;  
  
// 创建新节点  
Node* createNode(double x, double y) {  
    Node* newNode = (Node*)malloc(sizeof(Node));  
    newNode->x = x;  
    newNode->y = y;  
    newNode->next = NULL;  
    newNode->prev = NULL;  
    return newNode;  
}  
  
// 打印链表中的节点  
void printList(Node* head) {  
    Node* current = head;  
    while (current != NULL) {  
        printf("(%.3f, %.3f) ", current->x, current->y);  
        current = current->next;  
        if (current != NULL && current->x == 0) { // 假设每行的开始x坐标都为0，用于换行  
            printf("\n");  
        }  
    }  
    printf("\n");  
}  
  
// 释放链表内存  
void freeList(Node* head) {  
    Node* current = head;  
    Node* next;  
    while (current != NULL) {  
        next = current->next;  
        free(current);  
        current = next;  
    }  
}  
  
int main() {  
    int Nx, Ny;  
    scanf("%d %d", &Nx, &Ny);  
  
    double xStep = 1.0 / (Nx - 1);  
    double yStep = 1.0 / (Ny - 1);  
  
    // 创建链表的头节点（哑节点）  
    Node* head = createNode(0, 0);  
    Node* tail = head; // 用于追踪链表的尾部  
  
    // 生成节点并加入链表  
    for (int i = 0; i < Ny; ++i) {  
        double y = i * yStep;  
        for (int j = 0; j < Nx; ++j) {  
            double x = j * xStep;  
            Node* newNode = createNode(x, y);  
            tail->next = newNode;  
            newNode->prev = tail;  
            tail = newNode;  
        }  
    }  
  
    // 打印节点坐标  
    printList(head->next); // 跳过头节点（哑节点）  
  
    // 释放链表内存  
    freeList(head);  
  
    return 0;  
}
#include <stdio.h>

int main(){
    int weiBa1 = 0, weiBa2 = 0, ch;
    while ((ch = getchar()) != EOF){
        switch (ch)
        {
            case '+':printf("Incorrect");
            break;
            case '=':weiBa1 += ch;
            break;
        }
    }
        while ((ch = getchar()) != EOF){
        switch (ch)
        {
            case '+':printf("Incorrect");
            break;
            case '=':weiBa2 += ch;
            break;
        }
    }

    if (weiBa1 > weiBa2)
    {
        printf("First");
    }else if (weiBa1 < weiBa2)
    {
        printf("Second");
    }else printf("Equal");
    
    return 0;
}
#include <stdio.h>  
  
int main() {  
    int cont = 0, sum = 0;  
    int ch;

    while((ch = getchar()) != EOF){
        
    }

}
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
        }else if (cr == '-' && fuhaoFlag == 1)
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
     if (cycleFlag >= 1)
     {
        printf("YES");
     }else printf("NO");
     
    return 0;
}
#include <stdio.h>

long long sum_of_digits(long long num) {
    long long sum = 0;
    while (num > 0) {
        int digit = num % 10;
        if (digit != 5) {
            sum += digit;
        }
        num /= 10;
    }
    return sum;
}

int main() {
    long long number;
    int has_valid_input = 0; // 标记是否有有效输入
    int is_input_empty = 1; // 标记输入是否为空

    while (scanf("%lld", &number) == 1) {
        is_input_empty = 0; // 标记输入不为空
        has_valid_input = 1; // 标记有有效输入
        if (number < 0) { // 如果输入的是负数，则输出0并结束程序
            printf("0\n");
            has_valid_input = 0; // 标记没有有效输入
            break;
        }
        printf("%lld ", sum_of_digits(number));
    }

    if (is_input_empty) {
        // 如果输入为空，输出 -1
        printf("-1\n");
    } else if (!has_valid_input) {
        // 如果输入不为空但没有任何有效输入（即一开始就是错误的输入），输出0
        printf("0\n");
    }

    return 0;
}*/
/*while ((ch = getchar()) != '\n' && ch != EOF){
        cycleFlag += 1;

        if (ch == ' ' && cycleFlag == 1){
            return 1;
        }else if (ch == ' ' && cycleFlag >= 1)
        {
            continue;
        }
        
        
        if (ch >= '0' && ch <= '9'){
            if (cycleFlag == 1)
            {
                sum += ch - '0';
            }else if (cycleFlag == 2)//index = 
            {
                sum += ch - '0';
            }
            
            
        }else{
            printf("%lld",sum);
            return 1;
        }
    }
    if (((readedSymbol = getchar()) == '\n' || readedSymbol == EOF) && cycleFlag == 0)
    {
        return 1;
    }//空输入
    
    while (((readedSymbol = getchar()) != '\n' || readedSymbol != EOF)){
        //第一个数字
        cycleFlag += 1;
        if(readedSymbol == '-' && minusFlag == 0){
            minusFlag = 1;
            continue;
        }else if (readedSymbol == '-' && minusFlag == 1)
        {
            printf("%lld",sum);
            return 1;
        }else if (readedSymbol == '0' && minusFlag == 1 && numFlag == 0)
        {
            printf("%lld",sum);
            return 1;
        }else if (readedSymbol == '0' && minusFlag == 1)
        {
            /* code
        }
        
        
        
    
    }*/
#include <stdio.h>

int main(){
    int x;
    float z;
   scanf("%d %f", &x, &z);
    printf("%d", x%2);
}