//xt7_1.cpp
#include <iostream>
#include <cmath>
using  namespace std;
template <typename T>
T kaifang(T a)
{
	T c;
	c=sqrt(a);
	return c;
}
int main( )
{
	int x=kaifang(4);
    cout<<"����4��ƽ����Ϊ��"<<x<<endl;
    double y=kaifang(1.96);	   
    cout<<"ʵ��1.96��ƽ����Ϊ��" <<y<<endl;
    return 0;
}
