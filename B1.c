#include <stdio.h>
#include <limits.h>

int main()
{
    long long arr[10];
    int tag_num;
    long long num;

    for (int i = 0; i < 10; i++)
    {
        scanf("%lld", &num);
        arr[i] = num;
    }
    scanf("%d", &tag_num);

    if (tag_num == 1)
    {
        num = 0;
        for (int i = 0; i < 10; i++)
        {
            num += arr[i];
        }
        printf("%lld", num);
    }
    else if (tag_num == 2)
    {
        num = LLONG_MAX;
        for (int i = 0; i < 10; i++)
        {
            if (arr[i] < num)
            {
                num = arr[i];
            }
        }
        printf("%lld", num);
    }
    else if (tag_num == 3)
    {
        num = LLONG_MIN;
        
        for (int i = 0; i < 10; i++)
        {
            if (arr[i] < 0)
            {
                arr[i] = -arr[i];
            }
            if (arr[i] > num)
            {
                num = arr[i];
            }
        }
        printf("%lld", num);
    }

    return 0;
}