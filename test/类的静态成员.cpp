#include<iostream>
using namespace std;
class student{
    public:
        void GetInfo(string, int ,float);
        void PrintInfo();
        static void PrintC(student);
        
    private:
        string name;
        int age;
        float score;
        static int count;
};
int student::count=0;
void student::GetInfo(string n,int a,float s)
{
    name=n;
    age=a;
    score=s;
}

void student::PrintInfo()
{
    cout<<"姓名:"<<name<<"\t年龄:"<<age<<"\t分数:"<<score<<endl;
    count++;
}
void student::PrintC(student s)
{
    cout<<"学生数:"<<count<<endl;
    cout<<s.age;
}

int main()
{
    student s1,s2,s3,s4;
    s1.GetInfo("武新纪",20,99);
    s2.GetInfo("张宇轩",19,99);
    s3.GetInfo("汪恒",18,99);
    s4.GetInfo("张诗然",19,99);
    s1.PrintInfo();
    s2.PrintInfo();
    s3.PrintInfo();
    s4.PrintInfo();
    student::PrintC(s1);
    return 0;
}