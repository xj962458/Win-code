#include <iostream>
#include <string.h>
using namespace std;
class student       //����һ��ѧ������
{
public:
    student(int, char *, int, float);   //���������๹�캯�������ڶ���ĳ�ʼ����ֵ
    student(student &);                 //�������캯��
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
    cout << "ѧ��:" << id << "����:" << name;
    cout << "����:" << age << "�ɼ�:" << score << endl;
}
int main()
{
    char a[]="wang";
    student s1(10,a, 18, 86);
    student s3(s1);     //ֱ�ӵ��ÿ������캯�����и���
    student s2 = s1;    //���������ʵ�ָ��ƣ�ϵͳ�Զ����ÿ������캯��
    s1.printstu();
    s2.printstu();
    s3.printstu();
}