#include <iostream>
using namespace std;
int c;
int &sum(int a,int b=5){
	c=a+b;
   return c;
}
int main()
{
	int a,b,ans;
    cin>>a>>b;
	ans=sum(a);
	//ans+=3;
	//sum(a,b)=0;
	cout<<c<<endl;
   return 0;
}

