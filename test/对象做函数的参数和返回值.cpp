#include<iostream>
using namespace std;
class Trate{
    public:
        void Set(int,int,int);
        int IsLeapYear();
        void Print();
    private:
        int month;
        int day;
        int year;
};
void Trate::Set(int m,int d,int y)
{
    month=m;
    day=d;
    year=y;
}
int Trate::IsLeapYear()
{
    return (year%4==0&&year%100!=0)||(year%400==0);
}
void Trate::Print()
{
    cout<<month<<"/"<<day<<"/"<<year<<endl;
}

void someFunc(Trate someday)
{
    someday.Print();
    if(someday.IsLeapYear())
        cout<<"leap year\n";
    else
        cout<<"not leap year\n";
}

int main()
{
    Trate s;
    s.Set(3,21,2020);
    someFunc(s);
}