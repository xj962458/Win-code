//文件名:exp8-2.cpp
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

int BinSearch(RecType R[], int n, KeyType k) //折半查找算法
{
    int low = 0, high = n - 1, mid, count = 0;
    while (low <= high)
    {
        mid = (low + high) / 2;
        printf("  第%d次比较:在[%d,%d]中比较元素R[%d]:%d\n", ++count, low, high, mid, R[mid].key);
        if (R[mid].key == k) //查找成功返回
            return mid + 1;
        if (R[mid].key > k) //继续在R[low..mid-1]中查找
            high = mid - 1;
        else
            low = mid + 1; //继续在R[mid+1..high]中查找
    }
    return 0;
}
int main()
{
    RecType R[MAXL];
    KeyType k = 2;
    int a[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10}, i, n = 10;
    CreateList(R, a, n); //建立顺序表
    printf("关键字序列:");
    DispList(R, n);
    printf("查找%d的比较过程如下:\n", k);
    if ((i = BinSearch(R, n, k)) != -1)
        printf("元素%d的位置是%d\n", k, i);
    else
        printf("元素%d不在表中\n", k);
    return 0;
}
