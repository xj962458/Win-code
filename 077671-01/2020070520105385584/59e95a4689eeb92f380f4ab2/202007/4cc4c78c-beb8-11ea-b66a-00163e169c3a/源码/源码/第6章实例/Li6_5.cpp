//����Li6_5.cpp
//�����д��ڵ�����
#include <iostream>
using namespace std;
class Namelist
{
	char *name;
    public:
        Namelist (int size)
		{
         name= new char[ size] ;
		}
        ~ Namelist ()
		{
         delete [] name ;
		}
};
int main()
{
	Namelist n1(10),n2(10);
	n2=n1;
	return 0;
}

