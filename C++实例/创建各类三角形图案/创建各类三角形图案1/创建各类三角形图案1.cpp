#include <iostream>
using namespace std;
 
int main()
{
    int rows;
 
    cout << "请输入您要打印的行数: ";
    cin >> rows;
 
    for(int i = 1; i <= rows; ++i)
    {
        for(int j = 1; j <= i; ++j)
        {
            cout << "* ";
        }
        cout << "\n";
    }
    return 0;
}