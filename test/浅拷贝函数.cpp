#include<iostream>
using namespace std;

//浅拷贝不能进行指针和堆内存中的对象进行拷贝，但不用定义，不用声明，也不用调用，都是系统自动执行
class Person
{
    private:
        string name;
        int age;
    public:
        Person(string n,int a)
        {
            name=n;
            age=a;
        }
        void Prnt()
        {
            cout<<"姓名:"<<name<<endl;
            cout<<"年龄:"<<age<<endl;
        }
};

int main()
{
    Person s1("武新纪",20);
    s1.Prnt();
    Person s2=s1;
    s2.Prnt();
}

