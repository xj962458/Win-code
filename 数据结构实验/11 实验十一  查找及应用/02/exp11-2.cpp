//�ļ���:exp8-2.cpp
#include <stdio.h>
#include <malloc.h>
#define MAXL 100     //��󳤶�
typedef int KeyType; //����ؼ�������Ϊint
typedef char InfoType;

typedef struct
{
    KeyType key;   //�ؼ�����
    InfoType data; //�������������ΪInfoType
} RecType;         //����Ԫ�ص�����

void CreateList(RecType R[], KeyType keys[], int n) //����˳���
{
    for (int i = 0; i < n; i++) //R[0..n-1]��������¼
        R[i].key = keys[i];
}
void DispList(RecType R[], int n) //���˳���
{
    for (int i = 0; i < n; i++)
        printf("%d ", R[i].key);
    printf("\n");
}

int BinSearch(RecType R[], int n, KeyType k) //�۰�����㷨
{
    int low = 0, high = n - 1, mid, count = 0;
    while (low <= high)
    {
        mid = (low + high) / 2;
        printf("  ��%d�αȽ�:��[%d,%d]�бȽ�Ԫ��R[%d]:%d\n", ++count, low, high, mid, R[mid].key);
        if (R[mid].key == k) //���ҳɹ�����
            return mid + 1;
        if (R[mid].key > k) //������R[low..mid-1]�в���
            high = mid - 1;
        else
            low = mid + 1; //������R[mid+1..high]�в���
    }
    return 0;
}
int main()
{
    RecType R[MAXL];
    KeyType k = 2;
    int a[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10}, i, n = 10;
    CreateList(R, a, n); //����˳���
    printf("�ؼ�������:");
    DispList(R, n);
    printf("����%d�ıȽϹ�������:\n", k);
    if ((i = BinSearch(R, n, k)) != -1)
        printf("Ԫ��%d��λ����%d\n", k, i);
    else
        printf("Ԫ��%d���ڱ���\n", k);
    return 0;
}
