#include <iostream>
using namespace std;
int main()
{
    int *p, a[9];
    //p=&a;
    p = new int; //����һ���µĸ�ֵ��ʽ
    *p = 30;
    cout << p << "  " << *p << endl;
    delete p;
    cout << p << "  " << *p << endl;
    return 0;
}
