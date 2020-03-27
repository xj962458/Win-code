#include<iostream>
#include<iomanip>
#include<string.h>
using namespace std;
#include"student.h"             //包含头文件

int UnderGraduate::StuNum=0;        //静态数据成员初始化
int Graduate::StuNum=0;             //静态数据成员初始化
Student::Student()                  //Student类构造函数
{
    num=0;                          //选课数初始化为0
}

void Student::InputInfo()           //Student类InputInfo函数
{
    char namestr[20];               //输入学生姓名存放在namestr中
    cout<<"请输入下一个学生的姓名:";
    cin>>namestr;
    name=new char[strlen(namestr)+1];       //为指针存放的姓名申请地址
    strcpy(name,namestr);                   //将临时存放的姓名复制到name
    cout<<"输入学生的学号:";
    cin>>student_ID;
}

char *Student::getname()                    //Student类显示姓名函数
{
    return name;
}

void UnderGraduate::InputInfo()             //输入本科生信息的函数
{
    Student::InputInfo();                   
    StuNum++;                               //本科生总数加1
}

void UnderGraduate::input_credit()          //输入本科生选修的课程和学分
{
    char answer;
    do{
        cout<<"输入课程名称、学分、课程类别:必修/选修:\n";
        cin>>credit_hour[num].course>>credit_hour[num].hour>>credit_hour[num].type;
        num++;
        cout<<"继续输入课程？\n";
        cin>>answer;
    }while(answer=='y');
}
int UnderGraduate::GetStuNum()          //取得本科生人数
{
    return StuNum;
}

void UnderGraduate::displayInfo()           //显示本科生信息
{
    cout<<"本科生姓名:"<<name;
    cout<<"     学号:"<<student_ID<<endl;
    for(int i=0;i<num;i++)
    cout<<left<<setw(10)<<credit_hour[i].course
        <<setw(10)<<credit_hour[i].hour
        <<setw(10)<<credit_hour[i].type<<endl;
}

void Graduate::InputInfo()
{
    char namestr[20];               //输入考试姓名临时存放在namestr中
    Student::InputInfo();
    StuNum++;
    cout<<"请输入导师姓名:";
    cin>>namestr;
    tutor=new char[strlen(namestr)+1];      //为指针tutor申请地址
    strcpy(tutor,namestr);                  //将临时存放的姓名复制到turtor   
}

void Graduate::input_credit()               //输入研究生选修课程和学分
{
    char answer;
    do{
        cout<<"输入课程名称、学分、课程类别:学位/任选\n";
        cin>>credit_hour[num].course>>credit_hour[num].hour>>credit_hour[num].type;
        num++;
        cout<<"还有课程输入?";
        cin>>answer;
    }while(answer=='y');
}
int Graduate::GetStuNum()
{
    return StuNum;
}

void Graduate::displayInfo()
{
    cout<<"研究生姓名:"<<name;
    cout<<"     学号:"<<student_ID<<endl;
    cout<<"     导师姓名:"<<tutor<<endl;
    cout<<"课程名称     学分        课程类别\n";
    for(int i=0;i<num;i++)
    cout<<left<<setw(10)<<credit_hour[i].course
       <<setw(10)<<credit_hour[i].hour
       <<setw(10)<<credit_hour[i].type<<endl;
}