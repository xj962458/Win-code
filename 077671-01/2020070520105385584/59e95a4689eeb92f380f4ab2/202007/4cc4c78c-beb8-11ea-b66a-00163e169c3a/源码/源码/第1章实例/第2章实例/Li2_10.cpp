//����Li2_10.cpp
//���÷��غ���
#include <iostream>
using  namespace std;
int a[]={1,6,11,12};
int &index(int i);

int main()
{
   cout<<index(3)<<endl;    // ���12
   index(3)=10;              //��a[3]��Ϊ10
   cout<<index(3)<<endl;   // ���10
   return 0;
}
int& index(int i)
{  
	return a[i]; 
}
