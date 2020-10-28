#include<iostream>
#include<string>
using namespace std;

template <typename T>
class SqList{
    T *pelem;
    int length;
    public:
    SqList(int n){
        pelem=new T[n];
        length=0;
    }
    ~SqList(){
        delete pelem;
    }
    int ListLength(){
        return length;
    }
    void DispList(){
        int i;
        if(ListEmpty()) return;
        cout<<"˳���:";
        for(i=0;i<length;i++)
            cout<<pelem[i]<<" ";
        cout<<endl;
    }

    bool ListEmpty(){
        return length==0;
    }
    bool GetElem(int i,T &e){
        if(i<1||i>length)
            return false;
        e=pelem[i-1];
        return true;
    }
    int LocateElem(T e){
        int i=0;
        while(i<length&&pelem[i]!=e)
            i++;
        if(i>=length)
            return 0;
        else
            return i+1;
    }

    bool ListInsert(int i,T e){
        int j;
        if(i<1||i>length+1)
            return false;
        i--;
        for(j=length;j>i;j--)
            pelem[j]=pelem[j-1];
        pelem[i]=e;
        length++;
        return true;
    }

    bool ListDelete(int i,T &e){
        int j;
        if(i<1||i>length)
            return false;
        i--;
        e=pelem[i];
        for(j=i;j<length-1;j++)
            pelem[j]=pelem[j+1];
        length--;
        return true;
    }
};

int main()
{
    char e;int i;
    SqList<char> s(10);
    s.ListInsert(1,'a');
    s.ListInsert(2, 'b');
    s.ListInsert(3, 'c');
    s.ListInsert(4, 'd');
    s.DispList();
    s.GetElem(2,e);
    cout<<"��2�����ֵ:"<<e<<endl;
    i=s.LocateElem('d');
    cout<<"����Ϊd�Ľ�����Ϊ:"<<i<<endl;
    cout<<"ɾ����2�����"<<endl;
    s.ListDelete(2,e);
    s.DispList();
    cout<<"ɾ����3�����"<<endl;
    s.ListDelete(3,e);
    s.DispList();
    cout<<"����e��Ϊ��1�����"<<endl;
    s.ListInsert(1,'e');
    s.DispList();
    cout<<"����f��Ϊ��3�����"<<endl;
    s.ListInsert(3,'f');
    s.DispList();
    return 0;
}
