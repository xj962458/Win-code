#include <iostream>
using namespace std;
 
int main()
{    
    int divisor, dividend, quotient, remainder;
 
    cout << "���뱻����: ";
    cin >> dividend;
 
    cout << "�������: ";
    cin >> divisor;
 
    quotient = dividend / divisor;
    remainder = dividend % divisor;
 
    cout << "�� = " << quotient << endl;
    cout << "���� = " << remainder;
 
    return 0;
}