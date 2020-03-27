#include<iostream>
using namespace std;
class Tdate{
    public:
        Tdate(int m=2,int d=21,int y=2020)
        {
            month=m;
            day=d;
            year=y;
        }
    private:
        int month;
        int day;
        int year;
};

int main()
{
    Tdate aday;
    Tdate bday(2);
    Tdate cday(3,12);
    Tdate dday(1,2,2020);
}