//�ļ���:bst.cpp
#include <stdio.h>
#include <malloc.h>
#define MaxSize 100
typedef int KeyType; //����ؼ�������
typedef char InfoType;
typedef struct node //��¼����
{
    KeyType key;                  //�ؼ�����
    InfoType data;                //����������
    struct node *lchild, *rchild; //���Һ���ָ��
} BSTNode;
void DispBST(BSTNode *b);               //����˵��
bool InsertBST(BSTNode *&bt, KeyType k) //����btΪ���ڵ��BST�в���һ���ؼ���Ϊk�Ľڵ�
{
    if (bt == NULL) //ԭ��Ϊ��, �²���ļ�¼Ϊ���ڵ�
    {
        bt = (BSTNode *)malloc(sizeof(BSTNode));
        bt->key = k;
        bt->lchild = bt->rchild = NULL;
        return true;
    }
    else if (k == bt->key)
        return false;
    else if (k < bt->key)
        return InsertBST(bt->lchild, k); //���뵽bt�ڵ����������
    else
        return InsertBST(bt->rchild, k); //���뵽bt�ڵ����������
}

//������A�еĹؼ��ֽ���һ�ö���������
BSTNode *CreateBST(KeyType A[], int n)
{
    BSTNode *bt = NULL; //��ʼʱbtΪ����
    int i = 0;
    while (i < n)
        if (InsertBST(bt, A[i]) == 1) //��A[i]�������������T��
        {
            printf("    ��%d��,����%d:", i + 1, A[i]);
            DispBST(bt);
            printf("\n");
            i++;
        }
    return bt; //���ؽ����Ķ����������ĸ�ָ��
}

void Delete1(BSTNode *p, BSTNode *&r) //��ɾ�ڵ�p������������rָ��������
{
    BSTNode *q;
    if (r->rchild != NULL) //�ݹ��ҽڵ�r�������½ڵ�
        Delete1(p, r->rchild);
    else //�ҵ��������½ڵ�r����û����������
    {
        p->key = r->key; //���ڵ�r��ֵ��ŵ��ڵ�p�У��ڵ�ֵ�����
        p->data = r->data;
        q = r;         //ɾ���ڵ�r
        r = r->lchild; //���ýڵ�r�����������
        free(q);       //�ͷŽڵ�r�Ŀռ�
    }
}

void Delete(BSTNode *&p) //�Ӷ�����������ɾ��p�ڵ�
{
    BSTNode *q;
    if (p->rchild == NULL) //p�ڵ�û�������������
    {
        q = p;
        p = p->lchild;
        free(q);
    }
    else if (p->lchild == NULL) //p�ڵ�û�������������
    {
        q = p;
        p = p->rchild;
        free(q);
    }
    else
        Delete1(p, p->lchild); //p�ڵ�������������������������
}

//��bt��ɾ���ؼ���Ϊk�Ľڵ�
bool DeleteBST(BSTNode *&bt, KeyType k)

{
    if (bt == NULL)
        return false; //����ɾ��ʧ��
    else
    {
        if (k < bt->key)
            return DeleteBST(bt->lchild, k); //�ݹ�����������ɾ���ؼ���Ϊk�Ľڵ�
        else if (k > bt->key)
            return DeleteBST(bt->rchild, k); //�ݹ�����������ɾ���ؼ���Ϊk�Ľڵ�
        else                                 //k=bt->key�����
        {
            Delete(bt); //����Delete(bt)����ɾ��bt�ڵ�
            return true;
        }
    }
}

//�Եݹ鷽ʽ����Ӹ��ڵ㵽���ҵ��Ľڵ��·��
int SearchBST(BSTNode *bt, KeyType k)

{
    if (bt == NULL)
        return 0;
    else if (k == bt->key)
    {
        printf("%3d", bt->key);
        return 1;
    }
    else if (k < bt->key)
        SearchBST(bt->lchild, k); //���������еݹ����
    else
        SearchBST(bt->rchild, k); //���������еݹ����
    printf("%3d", bt->key);
}

//�����ű�ʾ���������������bt
void DispBST(BSTNode *bt)

{
    if (bt != NULL)
    {
        printf("%d", bt->key);
        if (bt->lchild != NULL || bt->rchild != NULL)
        {
            printf("(");
            DispBST(bt->lchild);
            if (bt->rchild != NULL)
                printf(",");
            DispBST(bt->rchild);
            printf(")");
        }
    }
}

//����һ��BST
void DestroyBST(BSTNode *bt)
{
    if (bt != NULL)
    {
        DestroyBST(bt->lchild);
        DestroyBST(bt->rchild);
        free(bt);
    }
}
