#include<iostream>
using namespace std;
int main()
{
    int i,j;
    for(i=1;i<=9;i++)
    {
        for(j=i;j<=9;j++)
            cout<<i<<'*'<<j<<'='<<i*j<<' ';
        cout<<endl;
    }
    printf("\n");
    for(i=1;i<=9;i++)
    {
        for(j=i;j<=9;j++)
            printf("%d*%d=%d ",i,j,i*j);
        printf("\n");
    }
    
}