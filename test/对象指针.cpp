#include<iostream>
using namespace std;
class student
{
    public:
        student(string n,int a,float s);
        void PrintInfo();
    private:
        string name;
        int age;
        float score;
};

student::student(string n,int a,float s)
{
    name=n;
    age=a;
    score=s;
}

void student::PrintInfo()
{
    cout<<"姓名:"<<name<<endl;
    cout<<"年龄:"<<age<<endl;
    cout<<"成绩:"<<score<<endl;
}

int main()
{
    student  *stu=new student("武新纪",20,99);
    stu->PrintInfo();
}