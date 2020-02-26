#include<iostream>
using namespace std;
class student{
    public:
        void getinfo();
        void printinfo();
    private:
        string name;
        int age;
        float score;
};

void student::getinfo(){
    cout<<"请依次输入姓名，年龄和成绩（用空格隔开）";
    cin>>name>>age>>score;
}

void student::printinfo(){
    cout<<name<<' '<<age<<' '<<score<<endl;
}

void menu(){
    cout<<endl<<endl;
    cout<<"这里是考生信息管理系统，请输入相应的数字执行相应的操作"<<endl;
    cout<<"1、录入考生信息"<<endl;
    cout<<"2、输出全部考生信息"<<endl;
    cout<<"0、退出"<<endl;
}
int main()
{
    int item,i,j,n;
    student stu[20];
    
    while(1){
        menu();
        cin>>item;
        switch(item){
            case 1:
                cout<<"请输入您要录入的考生数："<<endl;
                cin>>n;
                for(i=0;i<n;i++)
                    stu[i].getinfo();
                break;
            case 2:
                cout<<"姓名"<<' '<<"年龄"<<' '<<"分数"<<endl;
                for(i=0;i<n;i++)
                    stu[i].printinfo();
                break;
            case 0:
                exit(0);
        }
    }


    return 0;
}

