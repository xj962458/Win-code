//Li9_4.cpp
//�Զ����쳣���ʾ������
#include <iostream>
#include <string>
using  namespace  std;
class Negativenumber //�����쳣��1
{
public:
       Negativenumber();
Negativenumber(string s);
       string getmessage();
private:
       string message ;
};
Negativenumber::Negativenumber( ){ }
Negativenumber::Negativenumber(string s)
{  message=s; }
string Negativenumber::getmessage()
{return  message;}
class Dividebyzero{};     //�����쳣��2
void test() throw(Negativenumber,Dividebyzero);//����쳣�ĺ��������쳣�ӿ�����
void handler();//�����쳣�ĺ���
int main()
{
	handler();
	cout<<"End of program."<<endl;
    return 0;
}
void test() throw(Negativenumber,Dividebyzero)
{
	double totalmoney,averprice; 
	int booknumber;
	cout<<"Enter total money of your books: ";
    cin>>totalmoney;
    if (totalmoney<0)
	throw Negativenumber ("total money");
    cout<<"Enter book number:";
    cin>>booknumber;
    if(booknumber<0)
	    throw Negativenumber ("book number");
	if(booknumber!=0) averprice=totalmoney/booknumber;
	else throw Dividebyzero();
    cout<<"Average price of all books is:  "<<averprice<<endl;
}
void handler()
{
	try
	{
        test();//���ü���쳣����
    }
	catch(Negativenumber e)//��������Ϊ�쳣��1���쳣��������
		{cout<<e.getmessage()<<" cannot be a negative. "<<endl;}
    catch(Dividebyzero)//��������Ϊ�쳣��2���쳣��������
		{ cout<<"The number of book  is zero,error!!!"<<endl;}
}	