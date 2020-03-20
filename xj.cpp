#include<iostream>
using namespace std;
class Person
{
    public:
        void GetInfo(string name,int age,float score);
        void PrintInfo();
    private:
        string name;
        int age;
        float score;
};
void Person::GetInfo(string name,int age,float score)
{
    this->name=name;
    this->age=age;
    this->score=score;
}
class student:public Person
{
    public:
        void Display();
    private:
       Person p1;
};

void student::Display()
{
    GetInfo("武新纪",20,99);
    printf("%s",name);

}