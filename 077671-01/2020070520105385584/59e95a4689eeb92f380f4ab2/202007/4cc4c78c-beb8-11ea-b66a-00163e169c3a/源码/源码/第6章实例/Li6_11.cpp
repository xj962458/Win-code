//�ȶ���һ��������Rtype�����ݳ�Ա�Ƿ���data1�ͷ�ĸdata2��
//Ҫ������������ת����������ѷ�����Rtype����ת����double�����ݡ�
//����Li6_11.cpp
//ʾ������������ת�������
#include <iostream>
using namespace std;
class Rtype
{  
	public:
        Rtype(int a,int b=1);//ֻ��һ����Ĭ�ϲ����Ĺ��캯��
		operator double();
    private:
		int data1,data2;
};
Rtype::Rtype(int a,int b)
{
	data1=a;
	data2=b;
}
Rtype::operator double()//����������ת�������
{
	return double(data1)/double(data2);
}

int main()
{
	Rtype r1(2,4),r2(3,8);
	cout<<"r1="<<r1<<",r2="<<r2<<endl;
    return 0;
}
