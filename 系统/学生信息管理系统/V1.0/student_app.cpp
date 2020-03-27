#include<iostream>
using namespace std;
#include"student.h"

Student **SelectStuType(Student *Arraay_ptr[][10]);
void cret_object(Student *Array_ptr[][10]);
void DisplayStu(Student *Array_ptr[][10]);
void InputCredit(Student *Array_ptr[][10]);

int main()
{
    UnderGraduate UnderStu[10];
    Graduate GraduateStu[10];
    Student *Stu_ptr[2][10];        //指针数组
    for(int i=0;i<10;i++)
        Stu_ptr[0][i]=&UnderStu[i];        //第0行存放UnderStu各元素地址
    for(int i=0;i<10;i++)
        Stu_ptr[1][i]=&GraduateStu[i];             //第1行存放Graduate各元素地址
    cret_object(Stu_ptr);
    InputCredit(Stu_ptr);
    DisplayStu(Stu_ptr);
    return 0;
}

Student **SelectStuType(Student *Arraay_ptr[][10])
{
    char type;
    Student **ptr=NULL;
    do{
        cout<<"请选择学生类型；";
        cout<<"U:本科生；G:研究生:";
        cin>>type;
        switch(type)
        {
            case 'U':
                ptr=Arraay_ptr[0];          //指针数组第0行地址
                break;
            case 'G':
                ptr=Arraay_ptr[1];          //指针数组第一行地址
                break;
            default:
                cout<<"类型错误，请重新选择\n";
        }
    }while(ptr==NULL);
    return ptr;                             //返回指针数组的行地址
}

void cret_object(Student *Array_ptr[][10])
{
    char answer;
    Student **row_ptr;                      //从指针数组的行地址
    Student *ptr=NULL;                      //存放指针数组的元素值
    cout<<"输入学生的基本信息\n";
    do{
        row_ptr=SelectStuType(Array_ptr);
        ptr=*(row_ptr+(row_ptr[0]->GetStuNum()));
        ptr->InputInfo();                    //调用虚函数InputInfo
        cout<<"继续输入学生的基本信息(y/n)";
        cin>>answer;
    }while(answer=='y');
}

void DisplayStu(Student *Array_ptr[][10])
{
    char answer;
    Student **row_ptr;
    Student *ptr=NULL;
    int StuNum;
    cout<<"显示学生最基本信息\n";
    do{
        row_ptr=SelectStuType(Array_ptr);
        ptr=*row_ptr;
        StuNum=ptr->GetStuNum();            //取得本科生或研究生人数
        for(int i=0;i<StuNum;i++)
            row_ptr[i]->displayInfo();      //调用虚函数displayInfo
        cout<<"继续显示学生信息（y/n)？";
        cin>>answer;
    }while(answer=='y');
}

void InputCredit(Student *Array_ptr[][10])
{
    char answer;
    Student **row_ptr;
    Student *ptr=NULL;
    int StuNum;
    cout<<"输入已选课程、学分、课程类型\n";
    do{
        row_ptr=SelectStuType(Array_ptr);
        ptr=*row_ptr;
        StuNum=ptr->GetStuNum();
        for(int i=0;i<StuNum;i++)
        {
            cout<<"输入"<<row_ptr[i]->getname()<<"的课程学分:\n";
            row_ptr[i]->input_credit();
        }
        cout<<"继续输入其他类别学生的课程和学分（y/n)？";
        cin>>answer;
    }while(answer=='y');
}