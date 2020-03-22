#include<iostream>
#include<string.h>
using namespace std;
class student
{
    public:
        student(int,char *,int,float);
        ~student();
        void printstu();
    private:
        int id;
        char *name;
        int age;
        float score;
};
student::student(int i,char *c,int a,float s)
{
    cout<<"构造中....."<<endl;
    id=i;
    age=i;
    score=s;
    name=new char[strlen(c)+1];
    if(name!=0)
        strcpy(name,c);
}
student::~student()
{
    cout<<"删除中..."<<endl;
    delete []name;
}
void student::printstu()
{
    cout<<"学号:"<<id<<"  姓名:"<<name<<"  年龄:"<<age<<" 成绩:"<<score<<endl;
}
int main()
{
    student stu(1,"wu",18,86);
    stu.printstu();
    return 0;
}