#include <iostream>
using namespace std;
 
int main()
{
    float n1, n2, n3;
 
    cout << "������������: ";
    cin >> n1 >> n2 >> n3;
 
    if((n1 >= n2) && (n1 >= n3))
        cout << "�����Ϊ: " << n1;
    else if ((n2 >= n1) && (n2 >= n3))
        cout << "�����Ϊ: " << n2;
    else
        cout << "�����Ϊ: " << n3;
    
    return 0;
}