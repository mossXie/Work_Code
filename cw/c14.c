/*#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>

int main(int argc, char const **argv)// argc 3
{
    if(argc != 3){
        printf("0 0\n");
        return 1;
    }
    /*if (argv[1] <= '0' || argv[1] >= '9')
    {
        printf("0 0");
        return 1;
    }
    if(argv[2] <= '0' && argv[2] >= '9'){
        printf("0 0");
        return 1;
    }
    if( !isdigit(argv[1]) == 0){
        printf("0 10\n");
        return 1;
    }
    if (!isdigit(argv[2]) == 0){
        printf("0 0\n");
        return 1;
    }
    
    
    int size = atoi(argv[2]), readNum = 0, temp = 0, numArgv1 = atoi(argv[1]);
    int *num = malloc(size*sizeof(int));

    if(num == NULL){
        printf("0 0\n");
        return 2;
    }

    for(int i = 0; i < size; i++){
        if (scanf("%d", &num[i]) != 1){
            printf("0 0\n");
            free(num);
            return 1;
        }
    }

    for(int i = 0; i < size - 1; i++){
        temp = num[i] + num[i+1];
        if (temp == numArgv1){
            printf("%d %d", num[i], num[i+1]);
            return 0;
        }
    }

    return 0;
}
复盘：
    if (argv[2] <= '0' && argv[2] >= '9'){
    printf("0 0");
    return 1;
}
    检查错误
    isdigit接受的是字符而不是字符串，非数字返回0
*/
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const **argv) {
    long long numArgv1 = 0, size = 0;

    if (argc != 3) {
        printf("0 0\n");
        return 1;
    }

    if(sscanf(argv[1], "%lld", &numArgv1) != 1){
        printf("0 0\n");
        return 1;
        //sscanf返回值是成功读取的元素个数，如果失败则返回0。atoi返回的是int类型，如果失败则返回0。
        //sscanf可以进行转换是否成功，而atoi只能判断时否为数字。
    }
    if(sscanf(argv[2], "%lld", &size) != 1){
        printf("0 0\n");
        return 1;
    }

    int readFlag = 0;
    long long temp = 0;
    if (size <= 0) {
        printf("0 0\n");
        return 1;
    }


    int *num = malloc(size * sizeof(int));
    if (num == NULL) {
        printf("0 0\n");
        return 2;
    }

    for (int i = 0; i < size; i++) {
        readFlag = 1;
        if (scanf("%d", &num[i]) != 1) {
            printf("0 0\n");
            free(num);
            return 1;
        }
    }
    if(readFlag == 0){
        printf("0 0\n");
        return 3;
    }

    for (int i = 0; i < size - 1; i++) {
        temp = (long long)num[i] + (long long)num[i + 1];
        if (temp == numArgv1) {
            printf("%d %d\n", num[i], num[i + 1]);
            free(num);
            return 0;
        }
    }

    printf("0 0\n");
    free(num);
    return 0;
}