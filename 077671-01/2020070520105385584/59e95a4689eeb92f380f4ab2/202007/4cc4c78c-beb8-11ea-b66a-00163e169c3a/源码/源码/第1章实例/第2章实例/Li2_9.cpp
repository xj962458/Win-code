//����Li2_9.cpp
//����һ�������������������ϴ�ֵ������
#include <iostream>
using  namespace std;
int maxab;
int & maxRef(int x,int y) //�����ķ�������������
{
	if(x>y) maxab=x;
	else maxab=y;
     return maxab;
}

int main()
{
	int a,b;
    cout<<"Input a and b:";
    cin>>a>>b;
    cout<<maxRef(a,b)<<endl;
	return 0;
}
