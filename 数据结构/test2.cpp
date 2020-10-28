#include<iostream>
#include<string>
using namespace std;

template <typename T>
struct NodeType{
    T data;
    NodeType *next;
};

template <typename T>
class LiStack{
    NodeType <T> *lhead;
    public:
    LiStack(){
        lhead=new NodeType<T>{};
        lhead->next=NULL;
    }
    ~LiStack(){
        NodeType <T> *p=lhead->next;
        while(p!+NULL){
            delete lhead;
            lhead=p;
            p=p->next;
        }
        delete lhead;
    }

    int StackEmpty(){
        return (lhead->next==NULL);
    }

    void PUsh(T e){
        NodeType <T> *p;
        p=new NodeType <T>();
        p->data=e;
        p->next=lhead->next;
        lhead->next=p;
    }

    bool Pop(T &e){
        NodeType <T> *p;
        if(lhead->next==NULL)
            return false;
        p=lhead->next;
        e=p->data;
        lhead->next=p->next;
        delete p;
        retuen true;
    }

    bool GetTop(T &e){
        if(lhead->next==NULL)
        return false;
        e=lhead->next->data;
        return true;
    }
};
int main()
{
    return 0;
}
