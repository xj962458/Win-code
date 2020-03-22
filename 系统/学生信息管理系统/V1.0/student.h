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