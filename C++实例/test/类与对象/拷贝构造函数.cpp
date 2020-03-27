#include <iostream>
#include <string.h>
using namespace std;
class student       //定义一个学生的类
{
public:
    student(int, char *, int, float);   //含参数的类构造函数，用于对象的初始化赋值
    student(student &);                 //拷贝构造函数
    ~student();
    void printstu();

private:
    int id;
    char *name;
    int age;
    float score;
};
student::student(int i, char *c, int a, float s)
{
    cout << "Constructing..." << endl;
    id = i;
    age = a;
    score = s;
    name = new char[strlen(c) + 1];
    if (name != 0)
        strcpy(name, c);
}
student::student(student &s)
{
    cout << "Copy COnstructing..." << endl;
    id = s.id;
    age = s.age;
    score = s.score;
    name = new char[strlen(s.name) + 1];
    if (name != 0)
        strcpy(name, s.name);
}
student::~student()
{
    cout << "Destructing..." << endl;
    name[0] = '\0';
    delete name;
}
void student::printstu()
{
    cout << "学号:" << id << "姓名:" << name;
    cout << "年龄:" << age << "成绩:" << score << endl;
}
int main()
{
    char a[]="wang";
    student s1(10,a, 18, 86);
    student s3(s1);     //直接调用拷贝构造函数进行复制
    student s2 = s1;    //复制运算符实现复制，系统自动调用拷贝构造函数
    s1.printstu();
    s2.printstu();
    s3.printstu();
}
