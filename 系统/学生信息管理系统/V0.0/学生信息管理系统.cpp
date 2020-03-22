#include<iostream>
#include<iomanip>
#include<string.h>
using namespace std;

//一些函数声明
Student **SelectStuType(Student *Arraay_ptr[][10]);
void cret_object(Student *Array_ptr[][10]);
void DisplayStu(Student *Array_ptr[][10]);
void InputCredit(Student *Array_ptr[][10]);

#ifndef SHAPE_H
#define SHAPE_H
struct credit           //课程学分结构体定义
{                       
    char course[20];    //课程名   
    int hour;           //学分
    char type[5];       //课程类型
};

class Student       //基类Student
{
    protected:
        char *name;                 //姓名
        int student_ID;             //个人编号
        credit credit_hour[10];     //选修的课程和学分
        int num;                    //修课门数
    public:
        Student();                      //构造函数
        virtual~Student(){};            //虚析构函数
        char *getname();                //显示姓名函数
        virtual void InputInfo();       //输入学生基本信息
        virtual void input_credit()=0;  //输入课程和学分
        virtual void displayInfo()=0;   //显示学生信息
        virtual int GetStuNum()=0;      //学生人数
};

class UnderGraduate:public Student          //派生类UnderGraduate
{
    public:
        virtual void InputInfo();           //输入学生基本信息
        virtual void input_credit();        //输入课程和学分
        virtual void displayInfo();         //显示学生信息
        int GetStuNum();
    private:
        static int StuNum;                  //本科学生数
};

class Graduate:public Student
{
    public:
        virtual void InputInfo();           //输入学生基本信息
        virtual void input_credit();        //输入课程和学分
        virtual void displayInfo();         //显示学生信息
        int GetStuNum();
    private:
        static int StuNum;                  //研究生学生数
        char *tutor;                        //导师姓名
};                                          //派生类Graduate定义结束
#endif

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