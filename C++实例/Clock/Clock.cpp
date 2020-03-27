#include"Clock.h"
void Clock::SetTime(int newH,int newM,int newS)
{
    Hour=newH;
    Minute=newM;
    Second=newS;
}

void Clock::ShowTime()
{
    cout<<Hour<<":"<<Minute<<":"<<Second<<endl;
}

void Clock::ShowTime(int n)
{
    cout<<Hour<<"时"<<Minute<<"分"<<Second<<"秒"<<endl;
}

