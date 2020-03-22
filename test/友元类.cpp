#include<iostream>
#include<string.h>
using namespace std;
class Student;
class Teacher
{
    public:
        Teacher(int i,char *c);
        void show();
        void assignGrades(Student &s);
    private:
        char *name;
        int id;
};
class Student
{
    public:
        Student(int i,char *n,float s,Teacher *t);
        void printstu();
        friend class Teacher;
    private:
        Teacher *pT;
        int sid;
        char *name;
        float grade;
};
Student::Student(int i,char *c,float s,Teacher *t)
{
    sid=i;
    name=new char[strlen(c)+1];
    if(name!=0)
        strcpy(name,c);
    grade=s;
    pT=t;
}

void Student::printstu()
{
    cout<<"学号:"<<sid<<"   姓名:"<<name<<"     成绩"<<grade<<endl;
}

Teacher::Teacher(int i,char *c)
{
    id=i;
    name=new char[strlen(c)+1];
    if(name!=0)
        strcpy(name,c);
}

void Teacher::show()
{
    cout<<"工作证号:"<<id<<"    姓名:"<<name<<endl;
}
void Teacher::assignGrades(Student &s)
{
    if(s.pT->id==id)
        s.grade=4.0;
}
int main()
{
    Teacher wang(62,"wang yi");
    wang.show();
    Student s1(10,"张三",87.6,&wang);
    s1.printstu();
    wang.assignGrades(s1);
    s1.printstu();
    Student s2(12,"li si",80,&wang);
    s2.printstu();
    wang.assignGrades(s2);
    s2.printstu();
}