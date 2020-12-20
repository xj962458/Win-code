#include <stdio.h>
#include <malloc.h>
#define MaxSize 100
#define MaxWidth 40
typedef char ElemType;
typedef struct node
{
    ElemType data;       //����Ԫ��
    struct node *lchild; //ָ�����ӽ��
    struct node *rchild; //ָ���Һ��ӽ��
} BTNode;

BTNode *CreateBT(char *pre, char *in, int n)
{
    BTNode *b;
    char *p;
    int k;
    if (n <= 0)
        return NULL;
    b = (BTNode *)malloc(sizeof(BTNode)); //�������������*b
    b->data = *pre;
    for (p = in; p < in + n; p++)                        //�������������ҵ���*pre��λ��k
        if (*p == *pre)                                  //preָ������
            break;                                       //��in���ҵ����˳�ѭ��
    k = p - in;                                          //ȷ���������in�е�λ��
    b->lchild = CreateBT(pre + 1, in, k);                //�ݹ鹹��������
    b->rchild = CreateBT(pre + k + 1, p + 1, n - k - 1); //�ݹ鹹��������
    return b;
}

void DestroyBTree(BTNode *&b) //���ٶ�����
{
    if (b != NULL)
    {
        DestroyBTree(b->lchild);
        DestroyBTree(b->rchild);
        free(b);
    }
}
void DispBTree(BTNode *b) //�����ű�ʾ�����������
{
    if (b != NULL)
    {
        printf("%c", b->data);
        if (b->lchild != NULL || b->rchild != NULL)
        {
            printf("(");          //�к��ӽ��ʱ�����(
            DispBTree(b->lchild); //�ݹ鴦��������
            if (b->rchild != NULL)
                printf(",");      //���Һ��ӽ��ʱ�����,
            DispBTree(b->rchild); //�ݹ鴦��������
            printf(")");          //�к��ӽ��ʱ�����)
        }
    }
}

int main()
{
    BTNode *b;
    ElemType pre[] = "ABDGCEF";
    ElemType in[] = "DGBAECF";
    int n = 7;
    b = CreateBT(pre, in, n);
    printf("��������:%s\n", pre);
    printf("��������:%s\n", in);
    printf("����Ķ�����bΪ:");
    DispBTree(b);
    DestroyBTree(b);
    printf("\n");
    return 0;
}
