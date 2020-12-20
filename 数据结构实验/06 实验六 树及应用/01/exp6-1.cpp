#include <stdio.h>
#include <stdlib.h>
#define MaxSize 20
typedef char ElemType; //宏定义树结构中数据类型
typedef struct Snode
{ //结点结构
    ElemType data;
    int parent;
} PNode;
typedef struct
{ //树结构
    PNode tnode[MaxSize];
    int n; //结点个数
} PTree;
PTree CreatePNode(PTree tree)
{ //创建节点
    int i, j;
    char ch;
    printf("请输入节点个数:\n");
    scanf("%d", &(tree.n));

    printf("请输入结点的值其双亲位于数组中的位置下标:\n");
    for (i = 0; i < tree.n; i++)
    {
        getchar();
        scanf("%c %d", &ch, &j);
        tree.tnode[i].data = ch;
        tree.tnode[i].parent = j;
    }
    return tree;
}
void FindParent(PTree tree)
{ //查找每个节点
    char a;
    int isfind = 0, i;
    printf("请输入要查询的结点值:\n");
    getchar();
    scanf("%c", &a);
    for (i = 0; i < tree.n; i++)
    {
        if (tree.tnode[i].data == a)
        {
            isfind = 1;
            int ad = tree.tnode[i].parent;
            printf("%c的父节点为%c,存储位置下标为%d\n", a, tree.tnode[ad].data, ad);
            break;
        }
    }
    if (isfind == 0)
    {
        printf("树中无此节点\n");
    }
}
void DispTree(PTree tree)
{ //显示树
    int i;
    printf("index\tdata\tparent\n");
    for (i = 0; i < tree.n; i++)
        printf("%d\t%c\t%d\n", i, tree.tnode[i].data, tree.tnode[i].parent);
}
int main()
{
    int i;
    PTree tree;
    for (i = 0; i < MaxSize; i++)
    {
        tree.tnode[i].data = ' ';
        tree.tnode[i].parent = 0;
    }
    tree = CreatePNode(tree);
    printf("该树如下:\n");
    DispTree(tree);
    for (i = 0; i < 4; i++)
        FindParent(tree);
    return 0;
}
