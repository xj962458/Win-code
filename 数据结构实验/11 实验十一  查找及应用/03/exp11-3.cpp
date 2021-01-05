//文件exp11-3.cpp
#include "bst.cpp"
int main()
{
    BSTNode *bt;
    int path[MaxSize];
    KeyType k = 6;
    int a[] = {4, 9, 0, 1, 8, 6, 3, 5, 2, 7}, n = 10;
    printf("(1)创建一棵BST树:");
    printf("\n");
    bt = CreateBST(a, n);
    printf("(2)BST:");
    DispBST(bt);
    printf("\n");
    printf("(3)查找关键字为%d的节点的逆序路径:", k);
    SearchBST(bt, k);
    printf("\n(4)删除操作:\n");
    printf("   原BST:");
    DispBST(bt);
    printf("\n");
    printf("   删除节点4:");
    DeleteBST(bt, 4);
    DispBST(bt);
    printf("\n");
    printf("   删除节点5:");
    DeleteBST(bt, 5);
    DispBST(bt);
    printf("\n");
    printf("(5)销毁BST\n");
    DestroyBST(bt);
    return 0;
}
