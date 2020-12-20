#include <stdio.h>
#include <malloc.h>
#define MaxSize 100
typedef char ElemType;
typedef struct node
{
    ElemType data;       //����Ԫ��
    struct node *lchild; //ָ�����ӽ��
    struct node *rchild; //ָ���Һ��ӽ��
} BTNode;
void CreateBTree(BTNode *&b, const char *str) //����������
{
    BTNode *St[MaxSize], *p = NULL;
    int top = -1, k, j = 0;
    char ch;
    b = NULL; //�����Ķ�������ʼʱΪ��
    ch = str[j];
    while (ch != '\0') //strδɨ����ʱѭ��
    {
        switch (ch)
        {
        case '(':
            top++;
            St[top] = p;
            k = 1;
            break; //Ϊ���ӽ��
        case ')':
            top--;
            break;
        case ',':
            k = 2;
            break; //Ϊ���ӽ���ҽ��
        default:
            p = (BTNode *)malloc(sizeof(BTNode));
            p->data = ch;
            p->lchild = p->rchild = NULL;
            if (b == NULL) //*pΪ�������ĸ����
                b = p;
            else //�ѽ��������������
            {
                switch (k)
                {
                case 1:
                    St[top]->lchild = p;
                    break;
                case 2:
                    St[top]->rchild = p;
                    break;
                }
            }
        }
        j++;
        ch = str[j];
    }
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

int Nodes(BTNode *b) //�������b�Ľ�����
{
    int num1, num2;
    if (b == NULL)
        return 0;
    else if (b->lchild == NULL && b->rchild == NULL)
        return 1;
    else
    {
        num1 = Nodes(b->lchild);
        num2 = Nodes(b->rchild);
        return (num1 + num2 + 1);
    }
}

int LeafNodes(BTNode *b) //�������b��Ҷ�ӽ�����
{
    int num1, num2;
    if (b == NULL)
        return 0;
    else if (b->lchild == NULL && b->rchild == NULL)
        return 1;
    else
    {
        num1 = LeafNodes(b->lchild);
        num2 = LeafNodes(b->rchild);
        return (num1 + num2);
    }
}

int Level(BTNode *b, ElemType x, int h) //�������b�н��ֵΪx�Ľ��Ĳ��
{
    int l;
    if (b == NULL)
        return (0);
    else if (b->data == x)
        return (h);
    else
    {
        l = Level(b->lchild, x, h + 1); //���������в���
        if (l != 0)
            return (l);
        else //����������δ�ҵ�,�����������в���
            return (Level(b->rchild, x, h + 1));
    }
}

int LevelK(BTNode *b, int k)
{
    if (b == NULL)
        return 0;
    if (k == 1)
        return 1;
    return LevelK(b->lchild, k - 1) + LevelK(b->rchild, k - 1);
}

void DispBTree(BTNode *b) //������������н��
{
    if (b != NULL)
    {
        printf("%c ", b->data);
        if (b->lchild != NULL || b->rchild != NULL)
        {
            DispBTree(b->lchild); //�ݹ鴦��������
            DispBTree(b->rchild); //�ݹ鴦��������
        }
    }
}

void DisLeafNodes(BTNode *b) //���������b��Ҷ�ӽ��
{
    if (b != NULL)
    {
        if ((b->lchild == NULL) && (b->rchild == NULL))
            printf("%c ", b->data);
        DisLeafNodes(b->lchild);
        DisLeafNodes(b->rchild);
    }
}

bool DispAncestor(BTNode *b, ElemType c) //���������b��ֵΪc���������Ƚ��
{
    if (b == NULL)
        return false;
    else if ((b->lchild != NULL && b->lchild->data == c) || (b->rchild != NULL && b->rchild->data == c))
    {
        printf("%c ", b->data);
        return true;
    }
    else if (DispAncestor(b->lchild, c) || DispAncestor(b->rchild, c))
    {
        printf("%c ", b->data);
        return true;
    }
    else
        return false;
}

int main()
{
    BTNode *b;
    CreateBTree(b, "A(B(D(,G)),C(E,F))");
    printf("������b�����н��:");
    DispBTree(b);
    printf("\n������b���ܵĽ�����:%d\n", Nodes(b));
    printf("������b������Ҷ�ӽ��:");
    DisLeafNodes(b);
    printf("\n������b���ܵ�Ҷ�ӽ�����:%d\n", LeafNodes(b));
    printf("������b��ֵΪ%c�Ľ��Ĳ��:%d\n", 'E', Level(b, 'E', 1));
    printf("������b��3��Ľ�����:%d\n", LevelK(b, 3));
    printf("������b��ֵΪ%c���������Ƚ��Ϊ:", 'E');
    DispAncestor(b, 'E');
    DestroyBTree(b);
    return 0;
}
