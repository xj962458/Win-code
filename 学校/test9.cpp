#include<iostream>
using namespace std;
inline int sum(int a,int b)
{
    return a+b;
}
int main()
{
    int a=3,b=4;
    string s1(10,'x');
    string s2(100,'x');
    if(s1>s2)
        cout<<s1<<endl;
    else
    {
        cout<<s2<<endl;
    }
    
    cout<<sum(a,b)<<endl;
    return 0;
}