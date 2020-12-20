//exp7-1.cpp
#include "btree.cpp"
int main()
{
    BTNode *b, *p, *lp, *rp;
    printf("�������Ļ�����������:\n");
    printf("  (1)����������\n");
    CreateBTree(b, "A(B(D(,G)),C(E,F))");
    printf("  (2)���������:");
    DispBTree(b);
    printf("\n");
    printf("  (3)C���:");
    p = FindNode(b, 'C');
    if (p != NULL)
    {
        lp = LchildNode(p);
        if (lp != NULL)
            printf("����Ϊ%c ", lp->data);
        else
            printf("������ ");
        rp = RchildNode(p);
        if (rp != NULL)
            printf("�Һ���Ϊ%c", rp->data);
        else
            printf("���Һ��� ");
    }
    printf("\n");
    printf("  (4)������b�ĸ߶�:%d\n", BTHeight(b));
    printf("  (5)�ͷŶ�����b\n");
    DestroyBTree(b);
    return 0;
}
