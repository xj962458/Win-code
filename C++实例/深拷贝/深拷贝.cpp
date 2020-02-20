#include<iostream>
#include<string.h>
using namespace std;
class student
{
    public:
        student(int,char*,int,float);
        student(student&);
        ~student();
        void printstu();
    private:
        int id;
        char* name;
        int age;
        float score;
};
student::student(int i,char* c,int a,float s)
{
    cout<<"Constructing..."<<endl;
    id=i;
    age=a;
    score=s;
    name=new char[strlen(c )+1];
    if(name!=0)
        strcpy(name,c);
}
student::student(student& s)
{
    cout<<"Copy Constructing..."<<endl;
    id=s.id;
    age=s.age;
    score=s.score;
    name=new char[strlen(s.name)+1];
    if(name!=0)
        strcpy(name,s.name);
}
student::~student()
{
    cout<<"Destructing..."<<endl;
    name[0]='\0';
    delete name;
}
void student::printstu()
{
    cout<<"学号:"<<id<<"    姓名："<<name;
    cout<<"年龄："<<age<<"成绩："<<score<<endl;
}
int main()
{
    student s1(10,"wang",18,86);
    student s2=s1;
    s1.printstu();
    s2.printstu();
    return 0;
    getchar();
}
