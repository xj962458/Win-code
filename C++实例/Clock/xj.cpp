#include"Clock.h"
int main()
{
    Clock myclock;
    myclock.SetTime(12,5,0);
    myclock.ShowTime();
    myclock.ShowTime(1);
    return 0;
}
