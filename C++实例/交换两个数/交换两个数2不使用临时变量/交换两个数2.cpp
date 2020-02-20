#include <iostream>
#include <iostream>
using namespace std;
 
int main()
{
    
    int a = 5, b = 10;
 
    cout << "交换之前：" << endl;
    cout << "a = " << a << ", b = " << b << endl;
 
    a = a + b;
    b = a - b;
    a = a - b;
 
    cout << "\n交换之后：" << endl;
    cout << "a = " << a << ", b = " << b << endl;
 
    return 0;
}
