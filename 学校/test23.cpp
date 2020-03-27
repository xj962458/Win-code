//程序Li4_12.cpp
//基类有构造函数时，派生类构造函数的规则。
#include <iostream>
using namespace std;
class Baseclass
{
public:
    Baseclass() //不能不定义
    {
        cout << "default constructor Baseclass" << endl;
    }
    Baseclass(int i) //可以不要
    {
        a = i;
        cout << "constructing Baseclass a=" << a << endl;
    }

private:
    int a;
};
class Derivedclass : public Baseclass
{

private:
    int b;
};
int main()
{
    Derivedclass x;
    return 0;
}