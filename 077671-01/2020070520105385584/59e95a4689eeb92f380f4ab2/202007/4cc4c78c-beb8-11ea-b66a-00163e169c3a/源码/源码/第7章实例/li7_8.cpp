//����Li7_8.cpp
//ʹ��Ĭ�ϲ�������ģ��
#include <iostream>
#include <cstdlib>
using namespace std;
template <typename AType=int,int size=10> class atype //ʹ��Ĭ�ϲ�����ģ����
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
template <typename AType,int size> AType &atype<AType,size>::operator[] (int n)
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
    // 12��Ԫ�ص�integer�����࣬intobΪ�����һ������
	atype<int,12> intob;
	//double�����࣬�����СΪĬ��ֵ10��doubleobΪ�����һ������
    atype<double> doubleob;
	//�����࣬����ΪĬ��ֵint�������СΪĬ��ֵ10��defaultobΪ�����һ������
    atype<> defaultob;
    int i;
    cout << "Integer ���� : ";
    for(i=0;i<12;i++)intob[i]=i;
    for(i=0;i<12;i++)
		cout<<intob[i]<<"  ";
    cout<<endl;
    cout<<"Double ����: ";
    for(i=0;  i<10;  i++)  
		doubleob[i]=(double)i/2;
    for(i=0;  i<10;  i++)  
		cout<<doubleob[i]  <<"  ";
    cout<<endl;
    cout<<"Ĭ�ϲ�������: ";
    for(i=0;i<10;i++)
		cout<<defaultob[i]<<"  ";
    cout<<endl;
    return 0;
}