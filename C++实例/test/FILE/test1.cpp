#include<fstream>
#include<iostream>
using namespace std;
struct student
{
    long num;
    char name[20];
    char sex;
    int age;
};

int main()
{
    student stu;
    ifstream ifile("student.dat",ios::binary);
    if(ifile)
    {
        ifile.read((char*)&stu,sizeof(stu));
        cout<<stu.num<<' '<<stu.name<<' '<<stu.sex<<' '<<stu.age<<endl;
    }
    else 
        cout<<"Can't open file!"<<endl;
    return 0;

}
