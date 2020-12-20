#include <stdio.h>
#include <malloc.h>
#define MaxSize 100
typedef char ElemType;
typedef struct node
{
    ElemType data;       //数据元素
    struct node *lchild; //指向左孩子结点
    struct node *rchild; //指向右孩子结点
} BTNode;
void CreateBTree(BTNode *&b, const char *str) //创建二叉树
{
    BTNode *St[MaxSize], *p = NULL;
    int top = -1, k, j = 0;
    char ch;
    b = NULL; //建立的二叉树初始时为空
    ch = str[j];
    while (ch != '\0') //str未扫描完时循环
    {
        switch (ch)
        {
        case '(':
            top++;
            St[top] = p;
            k = 1;
            break; //为左孩子结点
        case ')':
            top--;
            break;
        case ',':
            k = 2;
            break; //为孩子结点右结点
        default:
            p = (BTNode *)malloc(sizeof(BTNode));
            p->data = ch;
            p->lchild = p->rchild = NULL;
            if (b == NULL) //*p为二叉树的根结点
                b = p;
            else //已建立二叉树根结点
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
void DestroyBTree(BTNode *&b) //销毁二叉树
{
    if (b != NULL)
    {
        DestroyBTree(b->lchild);
        DestroyBTree(b->rchild);
        free(b);
    }
}

int Nodes(BTNode *b) //求二叉树b的结点个数
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

int LeafNodes(BTNode *b) //求二叉树b的叶子结点个数
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

int Level(BTNode *b, ElemType x, int h) //求二叉树b中结点值为x的结点的层次
{
    int l;
    if (b == NULL)
        return (0);
    else if (b->data == x)
        return (h);
    else
    {
        l = Level(b->lchild, x, h + 1); //在左子树中查找
        if (l != 0)
            return (l);
        else //在左子树中未找到,再在右子树中查找
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

void DispBTree(BTNode *b) //输出二叉树所有结点
{
    if (b != NULL)
    {
        printf("%c ", b->data);
        if (b->lchild != NULL || b->rchild != NULL)
        {
            DispBTree(b->lchild); //递归处理左子树
            DispBTree(b->rchild); //递归处理右子树
        }
    }
}

void DisLeafNodes(BTNode *b) //输出二叉树b的叶子结点
{
    if (b != NULL)
    {
        if ((b->lchild == NULL) && (b->rchild == NULL))
            printf("%c ", b->data);
        DisLeafNodes(b->lchild);
        DisLeafNodes(b->rchild);
    }
}

bool DispAncestor(BTNode *b, ElemType c) //输出二叉树b中值为c的所有祖先结点
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
    printf("二叉树b的所有结点:");
    DispBTree(b);
    printf("\n二叉树b的总的结点个数:%d\n", Nodes(b));
    printf("二叉树b的所有叶子结点:");
    DisLeafNodes(b);
    printf("\n二叉树b的总的叶子结点个数:%d\n", LeafNodes(b));
    printf("二叉树b中值为%c的结点的层次:%d\n", 'E', Level(b, 'E', 1));
    printf("二叉树b第3层的结点个数:%d\n", LevelK(b, 3));
    printf("二叉树b中值为%c的所有祖先结点为:", 'E');
    DispAncestor(b, 'E');
    DestroyBTree(b);
    return 0;
}
