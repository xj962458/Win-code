//�ļ�exp11-3.cpp
#include "bst.cpp"
int main()
{
    BSTNode *bt;
    int path[MaxSize];
    KeyType k = 6;
    int a[] = {4, 9, 0, 1, 8, 6, 3, 5, 2, 7}, n = 10;
    printf("(1)����һ��BST��:");
    printf("\n");
    bt = CreateBST(a, n);
    printf("(2)BST:");
    DispBST(bt);
    printf("\n");
    printf("(3)���ҹؼ���Ϊ%d�Ľڵ������·��:", k);
    SearchBST(bt, k);
    printf("\n(4)ɾ������:\n");
    printf("   ԭBST:");
    DispBST(bt);
    printf("\n");
    printf("   ɾ���ڵ�4:");
    DeleteBST(bt, 4);
    DispBST(bt);
    printf("\n");
    printf("   ɾ���ڵ�5:");
    DeleteBST(bt, 5);
    DispBST(bt);
    printf("\n");
    printf("(5)����BST\n");
    DestroyBST(bt);
    return 0;
}
