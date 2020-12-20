#include<iostream>
#include<string>
using namespace std;

int main()
{
    int a[3][4]={{32,1,2,3},{34,32,34,2},{3,4,6,4}};
    int b[4][3]={{2,3,4},{2,3,2},{0,2,1},{3,4,3}};
    int c[3][3]={0};
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            for(int k=0;k<4;k++)
                c[i][j]+=a[i][k]*b[k][j];
        }
    }
    printf("a:\n");
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            printf("%5d ", a[i][j]);
        }
        printf("\n");
    }
    printf("\n");
    printf("b:\n");
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            printf("%5d ", b[i][j]);
        }
        printf("\n");
    }
    printf("\n");
    printf("c=a*b\n");
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            printf("%5d ",c[i][j]);
        }
        printf("\n");
    }
    return 0;
}
