#include <stdio.h>
#include <stdlib.h>
#define MaxSize 20
typedef char ElemType; //�궨�����ṹ����������
typedef struct Snode
{ //���ṹ
    ElemType data;
    int parent;
} PNode;
typedef struct
{ //���ṹ
    PNode tnode[MaxSize];
    int n; //������
} PTree;
PTree CreatePNode(PTree tree)
{ //�����ڵ�
    int i, j;
    char ch;
    printf("������ڵ����:\n");
    scanf("%d", &(tree.n));

    printf("���������ֵ��˫��λ�������е�λ���±�:\n");
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
{ //����ÿ���ڵ�
    char a;
    int isfind = 0, i;
    printf("������Ҫ��ѯ�Ľ��ֵ:\n");
    getchar();
    scanf("%c", &a);
    for (i = 0; i < tree.n; i++)
    {
        if (tree.tnode[i].data == a)
        {
            isfind = 1;
            int ad = tree.tnode[i].parent;
            printf("%c�ĸ��ڵ�Ϊ%c,�洢λ���±�Ϊ%d\n", a, tree.tnode[ad].data, ad);
            break;
        }
    }
    if (isfind == 0)
    {
        printf("�����޴˽ڵ�\n");
    }
}
void DispTree(PTree tree)
{ //��ʾ��
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
    printf("��������:\n");
    DispTree(tree);
    for (i = 0; i < 4; i++)
        FindParent(tree);
    return 0;
}
