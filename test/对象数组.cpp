#include<iostream>
#include<string.h>
using namespace std;
class student
{
    private:
        int id;
        char name[20];
        int age;
        float score;
    public:
        void set(int, char *,int ,float);
        void printstu()
        {
            cout<<"\t学号:"<<id<<"\t姓名:"<<name;
            cout<<"\t年龄:"<<age<<"\t成绩:"<<score;
            cout<<endl;
        }
};
void student::set(int i,char *c,int a,float s)
{
    id=i;
    strcpy(name,c);
    age=a;
    score=s;
}
int main()
{
    student stu[5];
    stu[0].set(1,"wang",18,86);
    stu[1].set(2,"Liao",18,72);
    stu[2].set(3,"zhao",20,99);
    stu[3].set(4,"zhang",20,100);
    stu[4].set(5,"wuli",20,100);
    for(int i=0;i<5;i++)
        stu[i].printstu();
    return 0;
}