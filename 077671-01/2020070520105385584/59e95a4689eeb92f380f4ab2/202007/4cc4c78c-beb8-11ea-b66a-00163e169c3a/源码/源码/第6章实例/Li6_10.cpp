//����Li6_10.cpp
//����()���ʶ�ά����Ԫ��
#include <iostream>
#include "process.h"
using namespace std;
const int LIMIT=100;
class  Intarray
{
	private:
        int size1;//����
		int size2;//����
		int *array;//������
    public:
		Intarray(int=1,int=1);//Ĭ��Ϊ1��1������
        int& operator()(int i,int j );
        ~Intarray();
};
Intarray::Intarray(int i,int j)
{
	//����Խ����
	if((i<0 || i>LIMIT)||(j<0 || j>LIMIT))
		{  
		   cout<<" out of array limit"<<endl; 
	       exit(1);  
		}
	size1=i;
	size2=j;
	array=new int[size1*size2]; 
}
int& Intarray::operator()(int m,int n)
{
	//�±�Խ����
	if((m< 0 || m>=size1)||(n< 0 || n>=size2))
		{  cout<<" out of range"<<endl; 
	       exit(1);  
		}
	return array[m*size1+n];   
} 
Intarray::~Intarray()
{
	delete[] array;
	size1=0;
	size2=0;
}
int main()
{
    int r,c,m,n,i,j;
	cout<<"please input row&&col of array(1��100):";
    cin>>r>>c;
    Intarray array(r,c);
    for(i=0; i<r; i++) 
		for(j=0; j<c; j++)
        array(i,j)=2*i+j; 
	cout<<"please input row&&col numbers of output array(1��100):";
	cin>>m>>n;
	for(i=0; i<m; i++)
        for(j=0; j<n; j++)
		{          
        int temp = array(i,j);               
        cout<<"Element " ;
		cout<<"array["<<i<<","<<j<<"]" <<"  is  "<<temp<<endl;
		}
    return  0;
}




