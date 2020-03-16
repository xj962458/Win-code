#include <iostream>
using namespace std;
int main()
{
    int *p, a[9];
    //p=&a;
    p = new int; //这是一种新的赋值形式
    *p = 30;
    cout << p << "  " << *p << endl;
    delete p;
    cout << p << "  " << *p << endl;
    return 0;
}

