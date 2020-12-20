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
BTNode *CreateBT2(char *post, char *in, int n)
{
    BTNode *b;
    char r, *p;
    int k;
    if (n <= 0)
        return NULL;
    r = *(post + n - 1);                  //�����ֵ
    b = (BTNode *)malloc(sizeof(BTNode)); //�������������*b
    b->data = r;
    for (p = in; p < in + n; p++) //��in�в��Ҹ����
        if (*p == r)
            break;
    k = p - in;                                        //kΪ�������in�е��±�
    b->lchild = CreateBT2(post, in, k);                //�ݹ鹹��������
    b->rchild = CreateBT2(post + k, p + 1, n - k - 1); //�ݹ鹹��������
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
    ElemType in[] = "DGBAECF";
    ElemType post[] = "GDBEFCA";
    int n = 7;
    printf("��������:%s\n", in);
    printf("��������:%s\n", post);
    b = CreateBT2(post, in, n);
    printf("����һ�ö�����b:\n");
    printf(" ���ű�ʾ��:");
    DispBTree(b);
    DestroyBTree(b);
    printf("\n");
    return 0;
}
