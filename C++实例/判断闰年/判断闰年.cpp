#include <iostream>
using namespace std;
 
int main()
{
    int year;
 
    cout << "�������: ";
    cin >> year;
 
    if (year % 4 == 0)
    {
        if (year % 100 == 0)
        {
            // // ��������� 400 ����������
            if (year % 400 == 0)
                cout << year << " ������";
            else
                cout << year << " ��������";
        }
        else
            cout << year << " ������";
    }
    else
        cout << year << " ��������";
 
    return 0;
}