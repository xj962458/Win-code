#include <stdio.h>
#include <malloc.h>
#define MaxSize 100
#define MaxWidth 40
typedef char ElemType;
typedef struct node
{
    ElemType data;       //数据元素
    struct node *lchild; //指向左孩子结点
    struct node *rchild; //指向右孩子结点
} BTNode;

BTNode *CreateBT(char *pre, char *in, int n)
{
    BTNode *b;
    char *p;
    int k;
    if (n <= 0)
        return NULL;
    b = (BTNode *)malloc(sizeof(BTNode)); //创建二叉树结点*b
    b->data = *pre;
    for (p = in; p < in + n; p++)                        //在中序序列中找等于*pre的位置k
        if (*p == *pre)                                  //pre指向根结点
            break;                                       //在in中找到后退出循环
    k = p - in;                                          //确定根结点在in中的位置
    b->lchild = CreateBT(pre + 1, in, k);                //递归构造左子树
    b->rchild = CreateBT(pre + k + 1, p + 1, n - k - 1); //递归构造右子树
    return b;
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
void DispBTree(BTNode *b) //以括号表示法输出二叉树
{
    if (b != NULL)
    {
        printf("%c", b->data);
        if (b->lchild != NULL || b->rchild != NULL)
        {
            printf("(");          //有孩子结点时才输出(
            DispBTree(b->lchild); //递归处理左子树
            if (b->rchild != NULL)
                printf(",");      //有右孩子结点时才输出,
            DispBTree(b->rchild); //递归处理右子树
            printf(")");          //有孩子结点时才输出)
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
    printf("先序序列:%s\n", pre);
    printf("中序序列:%s\n", in);
    printf("构造的二叉树b为:");
    DispBTree(b);
    DestroyBTree(b);
    printf("\n");
    return 0;
}
