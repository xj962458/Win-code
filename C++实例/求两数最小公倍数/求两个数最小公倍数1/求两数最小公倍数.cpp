#include <iostream>
using namespace std;
 
int main()
{
    int n1, n2, max;
 
    cout << "输入两个数: ";
    cin >> n1 >> n2;
    
    // 获取最大的数
    max = (n1 > n2) ? n1 : n2;
 
    do
    {
        if (max % n1 == 0 && max % n2 == 0)
        {
            cout << "LCM = " << max;
            break;
        }
        else
            ++max;
    } while (true);
    
    return 0;
}
