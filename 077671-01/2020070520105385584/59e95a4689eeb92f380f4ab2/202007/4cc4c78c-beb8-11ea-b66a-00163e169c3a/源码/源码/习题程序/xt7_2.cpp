//xt7_2.cpp
#include <iostream>
using  namespace std;
template <typename numtype>
class Classtemple
{
	public:
		void setdata(numtype x, numtype y)
		{
			a=x;b=y;
		}
        void dispdata()
		{
			cout<<"first number is "<<a<<endl;
            cout<<"second number is "<<b<<endl;
        }
    private:
		numtype a,b;
};
int main( )
{
	Classtemple<int> intobj;
	intobj.setdata(23,24);
	cout<<"��������������ݳ�ԱΪ��"<<endl;
    intobj.dispdata();
    Classtemple<char> charobj;
	charobj.setdata('3','4');
    cout<<"�ַ�����������ݳ�ԱΪ��"<<endl;
    charobj.dispdata();
    return 0;
}
