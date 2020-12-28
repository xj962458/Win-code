#include<iostream>
#include<string>
#include<cstring>
using namespace std;

int main()
{
    char a[]="Hello ";
    char b[]="World";
    char c[20];
    strcat(a,b);
    cout<<a<<endl;
    cout<<b<<endl;
    // cout<<c<<endl;
    return 0;
}
