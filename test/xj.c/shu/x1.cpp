#include<iostream>
using namespace std;
class student{
    public:
        void GetInfo(string,int,float);
        void PirntInfo();
    private:
        string name;
        int age;
        float score;
};

void student::GetInfo(string n,int a,float s){
    name=n;
    age=a;
    score=s;
}

void student::PirntInfo(){
    cout<<"����\t"<<"����\t"<<"����\t"<<endl;
    cout<<name<<"\t"<<age<<"\t"<<score<<"\t"<<endl;
}

int main()
{
    int i,j;
    student *stu=new student();

    stu->GetInfo("���¼�",20,99);
    stu->PirntInfo();
    return 0;
}