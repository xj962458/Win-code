#include<iostream>
using namespace std;
int main()
{
    int a=10,b=9;
    int &c=a;
    c++;
    cout<<a<<endl<<c<<endl;
    c=b;
    cout<<c<<endl<<a;

}

/*
*引用
*内联函数
*重载函数
*inline
*链表
*线性表
*结构体
*Leetcode
*/