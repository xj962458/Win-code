#include <iostream>
using namespace std;
int c;
int &sum(int a, int b)
{
    c = a + b;
    return c;
}
int main()
{
    int a, b, ans;
    cin >> a >> b;
    //ans=sum(a,b);
    //ans+=3;
    sum(a, b) = 10;
    cout << c << endl;
    return 0;
}

