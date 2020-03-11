#include <stdio.h>
#include <math.h>
int main()
{
    int n;
    printf("请输入来那个菱形边长:");
    scanf("%d", &n);
    for (int x =-(n-1);x<=(n - 1);x++)
    {
        for (int y = -(n - 1); x <= (n - 1); y++)
        {
            if (abs(x) + abs(y) == (n - 1))
                printf("*");
            else
                printf(" ");
        }
        printf("\n");
    }
    return 0;
}