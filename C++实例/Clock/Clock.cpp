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
    cout<<Hour<<"ʱ"<<Minute<<"��"<<Second<<"��"<<endl;
}
