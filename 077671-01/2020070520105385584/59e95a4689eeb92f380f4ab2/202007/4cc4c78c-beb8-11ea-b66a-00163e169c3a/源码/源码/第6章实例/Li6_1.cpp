//����Li6_1.cpp
//��Ա�������������++��--
#include <iostream>
using namespace std;
class Counter
{  
	public:
		Counter(){value=0;}
		Counter(int i){value=i;}
        Counter operator++();     //ǰ׺++�����
        Counter operator++(int);  //��׺++�����
        Counter operator--();     //ǰ׺--�����
        Counter operator--(int);  //��׺--�����
        void display(){cout<<value<<endl;}
    private:
		unsigned value;
};
Counter Counter::operator++()
{
	value++;
    return *this;
}
Counter Counter::operator++(int)
{
	Counter temp;
    temp.value=value++;
    return temp; 
}
Counter Counter::operator--()
{ 
	value--;
    return *this;
}
Counter Counter::operator--(int)
{
    Counter temp;
    temp.value=value--;
    return temp; 
}
int main()
{
	Counter n(10),c;
    c=++n;
    cout<<"ǰ׺++�������������"<<endl;
    cout<<"n= ",n.display();
	cout<<"c= ",c.display();
	c=n++; 
	cout<<"��׺++�������������"<<endl;
    cout<<"n= ",n.display();  
	cout<<"c= ",c.display();
    c=--n;
    cout<<"ǰ׺--�������������"<<endl;
	cout<<"n= ",n.display();
	cout<<"c= ",c.display();
	c=n--; 
	cout<<"��׺--�������������"<<endl;
    cout<<"n= ",n.display();
	cout<<"c= ",c.display();
    return 0;
}
