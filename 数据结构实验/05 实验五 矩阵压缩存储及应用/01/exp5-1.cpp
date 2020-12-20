//exp5-1.cpp
#include <stdio.h>
#define N 4
#define M 10
void fun(int a[][N], int b[M])
{
    int i, j;
    for (i = 0; i < N; i++)
        for (j = 0; j < N; j++)
        {
            if (i >= j)
                b[(i * (i + 1)) / 2 + j] = a[i][j];
            else
                b[(j * (j + 1)) / 2 + i] = a[i][j];
        }
}

int value(int a[], int i, int j) //压缩为一维数组
{
    if (i >= j)
        return a[(i * (i + 1)) / 2 + j];
    else
        return a[(j * (j + 1)) / 2 + i];
}
void madd(int a[], int b[], int c[][N]) //压缩存储a和b的和
{
    int i, j;
    for (i = 0; i < N; i++)
        for (j = 0; j < N; j++)
            c[i][j] = value(a, i, j) + value(b, i, j);
}
void mult(int a[], int b[], int c[][N]) //压缩存储a和b的乘积
{
    int i, j, k, s;
    for (i = 0; i < N; i++)
        for (j = 0; j < N; j++)
        {
            s = 0;
            for (k = 0; k < N; k++)
                s = s + value(a, i, k) * value(b, k, j);
            c[i][j] = s;
        }
}
void disp1(int a[]) //输出原始矩阵
{
    int i, j;
    for (i = 0; i < N; i++)
    {
        for (j = 0; j < N; j++)
            printf("%4d", value(a, i, j));
        printf("\n");
    }
}
void disp2(int c[][N]) //输出求和，求积矩阵
{
    int i, j;
    for (i = 0; i < N; i++)
    {
        for (j = 0; j < N; j++)
            printf("%4d", c[i][j]);
        printf("\n");
    }
}
int main()
{
    int a[M], b[M];
    int A[N][N] = {{9, 1, 3, 5}, {1, 2, 7, 8}, {3, 7, 6, 4}, {5, 8, 4, 0}};
    int B[N][N] = {{11, 14, 31, 56}, {14, 12, 71, 83}, {31, 71, 13, 42}, {56, 83, 42, 14}};
    int c1[N][N], c2[N][N];
    fun(A, a);
    fun(B, b);
    madd(a, b, c1);
    mult(a, b, c2);
    printf("a矩阵为:\n");
    disp1(a);
    printf("b矩阵为:\n");
    disp1(b);
    printf("a+b:\n");
    disp2(c1);
    printf("a*b:\n");
    disp2(c2);
    return 0;
}
