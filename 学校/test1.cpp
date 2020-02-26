#include<iostream>
using namespace std;
class boy
{
    public:
        void set(string n,int a,float s);
        void print();
        float xd;
        long id;
    private:
        string name;
        int age;
        float score;
};

void boy::set(string n,int a,float s)
{
    name=n;
    age=a;
    score=s;
}

void boy::print()
{
    cout<<"姓名:"<<name<<endl;
    cout<<"年龄:"<<age<<endl;
    cout<<"分数:"<<score<<endl;
}

int main()
{
    boy xj;
    xj.xd=90;
    xj.id=3190707121;
    cout<<xj.id<<endl;
    cout<<xj.xd<<endl;
    xj.set("wxj",20,99);
    xj.print();
    return 0;
}