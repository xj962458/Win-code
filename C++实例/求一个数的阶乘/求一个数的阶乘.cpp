#include <iostream>
using namespace std;
 
int main()
{
    unsigned int n;
    unsigned long factorial = 1;
 
    cout << "����һ������: ";
    cin >> n;
 
    for(int i = 1; i <=n; ++i)
    {
        factorial *= i;
    }
 
    cout << n << " �Ľ׳�Ϊ��"<< " = " << factorial;    
    return 0;
}