//����Li6_2.cpp
//��Ԫ�������������++��--
#include <iostream>
using namespace std;
class Counter
{
	public:
		Counter(){value=0;}
		Counter(int i){value=i;}
		friend Counter operator++(Counter&);      //ǰ׺++�����
        friend Counter operator++(Counter&,int);  //��׺++�����
        friend Counter operator--(Counter&);      //ǰ׺--�����
        friend Counter operator--(Counter&,int);  //��׺--�����
        void display(){cout<<value<<endl;}
    private:
        unsigned value;
};
Counter operator++(Counter& p)
{ 
	p.value++;
    return p;
}
Counter operator++(Counter& p,int)
{
	Counter temp;
    temp.value=p.value++;
    return temp; 
}
Counter operator--(Counter& p)
{
	p.value--;
    return p;
}
Counter operator--(Counter& p,int)
{
	Counter temp;
    temp.value=p.value--;
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
