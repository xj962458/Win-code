
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
    cout<<"请输入根节点的值"<<endl;
    cin>>root->data;
    cout<<"请输入左孩子和右孩子"<<endl;
    root->lchild=new Btree,root->rchild=new Btree;
    cin>>root->lchild->data>>root->rchild->data;
    root->lchild->lchild=new Btree,root->lchild->rchild=new Btree;
    cout<<"请输入左孩子的左右孩子:"<<endl;
    cin>>root->lchild->lchild->data>>root->lchild->rchild->data;
    root->rchild->lchild = new Btree, root->rchild->rchild = new Btree;
    cout << "请输入右孩子的左右孩子:" << endl;
    cin >> root->rchild->lchild->data >> root->rchild->rchild->data;
    cout<<"输入结束"<<endl;
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
