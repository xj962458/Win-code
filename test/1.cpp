
#include<iostream>
#include<string>
using namespace std;

typedef struct btree{
    int data;
    struct btree *lchild,*rchild;
    btree():lchild(NULL),rchild(NULL){};
}Btree;

class Tree{
    public:
        void CreateBt();
        void FindPath(Btree *p);
    private:
        Btree *root,*b,*p;
};

void Tree::CreateBt(){
    root=new Btree;
    cout<<"��������ڵ��ֵ"<<endl;
    cin>>root->data;
    cout<<"���������Ӻ��Һ���"<<endl;
    root->lchild=new Btree,root->rchild=new Btree;
    cin>>root->lchild->data>>root->rchild->data;
    root->lchild->lchild=new Btree,root->lchild->rchild=new Btree;
    cout<<"���������ӵ����Һ���:"<<endl;
    cin>>root->lchild->lchild->data>>root->lchild->rchild->data;
    root->rchild->lchild = new Btree, root->rchild->rchild = new Btree;
    cout << "�������Һ��ӵ����Һ���:" << endl;
    cin >> root->rchild->lchild->data >> root->rchild->rchild->data;
    cout<<"�������"<<endl;
    FindPath(root);
}
void Tree::FindPath(Btree *p){
    if(p==NULL)
        return;
    else
    {
        cout << p->data << " ";
        FindPath(p->lchild);
        FindPath(p->rchild);
    }
}
int main()
{
    Tree b;
    b.CreateBt();
    return 0;
}
