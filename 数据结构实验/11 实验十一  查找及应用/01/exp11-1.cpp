//文件名:exp11-1.cpp
#include <stdio.h>
#include <malloc.h>
#define MAXL 100     //最大长度
typedef int KeyType; //定义关键字类型为int
typedef char InfoType;

typedef struct
{
    KeyType key;   //关键字项
    InfoType data; //其他数据项，类型为InfoType
} RecType;         //查找元素的类型

void CreateList(RecType R[], KeyType keys[], int n) //创建顺序表
{
    for (int i = 0; i < n; i++) //R[0..n-1]存放排序记录
        R[i].key = keys[i];
}
void DispList(RecType R[], int n) //输出顺序表
{
    for (int i = 0; i < n; i++)
        printf("%d ", R[i].key);
    printf("\n");
}

int SeqSearch(RecType R[], int n, KeyType k) //顺序查找算法
{
    int i = 0;
    while (i < n && R[i].key != k)
    {
        printf("%d ", R[i].key);
        i++; //从表头往后找
    }
    if (i >= n)
        return 0;
    else
    {
        printf("%d", R[i].key);
        return i + 1;
    }
}
int main()
{
    RecType R[MAXL];
    int n = 10, i;
    KeyType k = 5;
    int a[] = {3, 6, 2, 10, 1, 8, 5, 7, 4, 9};
    CreateList(R, a, n); //建立顺序表
    printf("关键字序列:");
    DispList(R, n);
    printf("查找%d所比较的关键字:\n\t", k);
    if ((i = SeqSearch(R, n, k)) != 0)
        printf("\n元素%d的位置是%d\n", k, i);
    else
        printf("\n元素%d不在表中\n", k);
    return 0;
}
