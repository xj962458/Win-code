#include<iostream>
#include<string>
using namespace std;

union test
{
    int data;
    char ch;
};

int main()
{
    test test1;
    test1.data=10;
    test1.ch='w';
    cout<<test1.data<<endl;
    test1.data=90;
    cout<<test1.ch<<endl;
    printf("%d\n",'w');
    return 0;
}
