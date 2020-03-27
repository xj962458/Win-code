#include<iostream>
#include<cstdio>
using namespace std;
int main()
{
    int a,*p;
    float f;
    double d;
    char c;
    int &ra=a;
    cin>>a;
    cin>>ra;
    cout<<ra<<' '<<a<<endl;
}
