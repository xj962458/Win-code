#include <iostream>
using namespace std;
 
int main()
{
    int space, rows = 5;
 
    for(int i = 1; i <= rows; ++i)
    {
        for(space = 1; space <= rows-i; ++space)
        {
            cout <<"  ";
        }
     int k = 2*(i-1)+1;
        while(k>0)
        {
            cout << "* ";
            --k;
        }
        cout << endl;
    }    
    return 0;
}




