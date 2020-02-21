#include <iostream>
using namespace std;
int main()
{
    int *p, a[9];
    //p=&a;
    // p=a;
    // p=&a[3];
    p = new int[9]; //动态分配一个数组 ，int 9
    p[0] = 8;
    cout << p << "  " << *p << endl;

    return 0;
}