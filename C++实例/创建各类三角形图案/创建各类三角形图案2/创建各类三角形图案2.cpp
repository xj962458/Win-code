#include <iostream>
using namespace std;
 
int main()
{
    int rows;
 
    cout << "输入行数: ";
    cin >> rows;
 
    for(int i = 1; i <= rows; ++i)
    {
        for(int j = 1; j <= i; ++j)
        {
            cout << j << " ";
        }
        cout << "\n";
    }
    return 0;
}
