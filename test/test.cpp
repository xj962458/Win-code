#include<iostream>
#include<string>
using namespace std;
typedef int ElemType; 
typedef struct list{
    ElemType data;
    struct list *next;
}List;

class SList{
    public:
        SList(){};
        SList(ElemType a[],int n);
        ~SList();
        void Insert(ElemType e);
        void Print();
        bool ListEmpty();
        int ListLength();
    private:
        List *L;
};

SList::SList(ElemType a[], int n)
{
    List *p;
    L = new List;
    L->next == NULL;
    for (int i = 0; i < n; i++)
    {
        p = new List;
        p->next = L->next;
        p->data = a[i];
        L->next = p;
    }
}
SList::~SList()
{
    List *p = L->next;
    while (p != NULL)
    {
        delete p;
        p = p->next;
    }
    delete L;
}
void SList::Insert(ElemType e){
    List *p=new List;
    p->next=L->next;
    L->next=p;
    p->data=e;
}

void SList::Print(){
    List *p=L->next;
    while(p!=NULL){
        cout<<p->data<<"->";
        p=p->next;
    }
}

bool SList::ListEmpty(){
    return L->next==NULL;
}
int SList::ListLength(){
    int n=0;
    List *p=L->next;
    while(p!=NULL){
        n++;
        p=p->next;
    }
    return n;
}

int main()
{
    int a[10]={12,34,56,54,23,435,67,86,97,56};
    SList l(a,10);
    cout << l.ListEmpty();
    l.Print();
    return 0;
}
