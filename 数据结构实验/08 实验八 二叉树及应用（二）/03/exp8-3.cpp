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
BTNode *CreateBT2(char *post, char *in, int n)
{
    BTNode *b;
    char r, *p;
    int k;
    if (n <= 0)
        return NULL;
    r = *(post + n - 1);                  //根结点值
    b = (BTNode *)malloc(sizeof(BTNode)); //创建二叉树结点*b
    b->data = r;
    for (p = in; p < in + n; p++) //在in中查找根结点
        if (*p == r)
            break;
    k = p - in;                                        //k为根结点在in中的下标
    b->lchild = CreateBT2(post, in, k);                //递归构造左子树
    b->rchild = CreateBT2(post + k, p + 1, n - k - 1); //递归构造右子树
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
    ElemType in[] = "DGBAECF";
    ElemType post[] = "GDBEFCA";
    int n = 7;
    printf("中序序列:%s\n", in);
    printf("后序序列:%s\n", post);
    b = CreateBT2(post, in, n);
    printf("构造一棵二叉树b:\n");
    printf(" 括号表示法:");
    DispBTree(b);
    DestroyBTree(b);
    printf("\n");
    return 0;
}
