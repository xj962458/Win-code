//����Li7_6.cpp
//ͨ��������
#include <iostream>
#include <cstdlib>
using namespace std;
const int size = 10;
template <typename AType> class atype //ģ����
{
    
	public:
		atype() 
		{
			int i;
			for(i=0;i<size;i++)array[i]=i;
		}
		AType &operator[] (int n);
    private:
        AType array[size];
};
template <typename AType> AType &atype<AType>::operator[] (int n)
{
    //�±�Խ����
    if(n< 0 || n>=size)
		{  cout<<"�±�"<<n<<"������Χ!"<<endl; 
	       exit(1);  
		}
	return array[n];   
}
int main()
{
    atype<int> intob;  // integer �����࣬intobΪ�����һ������
    atype<double> doubleob;  // double �����࣬doubleobΪ�����һ������
    int i;
    cout << "Integer ����: ";
    for(i=0;i<size;i++)intob[i]=i;
    for(i=0;i<size;i++)
		cout<<intob[i]<<"   ";
    cout<<endl;
    cout<<"Double ����: ";
    for(i=0;  i<size;  i++)  
		doubleob[i]=(double)i/2;
    for(i=0;  i<size;  i++)  
		cout<<doubleob[i]  <<"   ";
    cout<<endl;
    intob[12] = 100;  // �±�Խ��
	return 0;
}