//����Li6_12.cpp
//ʾ���������������ת�������
#include <iostream>
using namespace std;
class Rr
{  
	public:
        Rr(int a);
        operator int();
		operator double();
    private:
		int data;
};
Rr::Rr(int a)
{
	data=a;
}
Rr::operator int()//��һ������������ת�������
{
	return data;
}
Rr::operator double()//�ڶ�������������ת�������
{
	return double(data);
}

int main()
{
	Rr r1(2),r2(3);
	int x=int(r1)+int(r2);
	float y=double(r1)/double(r2);
	cout<<"x="<<x<<",y="<<y<<endl;
    return 0;
}
