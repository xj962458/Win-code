#include <iostream>
using namespace std;
 
int main()
{
    char input, alphabet = 'A';
 
    cout << "�������һ����д��ĸ: ";
    cin >> input;
 
    for(int i = 1; i <= (input-'A'+1); ++i)
    {
        for(int j = 1; j <= i; ++j)
        {
            cout << alphabet << " ";
        }
        ++alphabet;
 
        cout << endl;
    }
    return 0;
}