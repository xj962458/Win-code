#include<iostream>
using namespace std;
class Clock
{
    public:
        void SetTime(int newH=0,int newM=0,int newS=0);
        void ShowTime();
        void ShowTime(int n);
    private:
        int Hour;
        int Minute;
        int Second;
};