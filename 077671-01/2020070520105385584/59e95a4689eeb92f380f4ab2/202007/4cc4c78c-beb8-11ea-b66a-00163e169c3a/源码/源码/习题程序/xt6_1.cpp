#include<math.h>
#include<iostream.h>
#include <stdlib.h>
class  Fraction
{
	public:
		Fraction(int x=0,int y=1);  //������Ĭ��ֵ�Ĺ��캯��
		void  print();
		friend  Fraction operator+(Fraction&num1,Fraction&num2);//���������"+"
		friend  Fraction operator-(Fraction&num1,Fraction&num2);//���������"-"
		friend  Fraction operator*(Fraction&num1,Fraction&num2);//���������"*"
		friend  Fraction operator/(Fraction&num1,Fraction&num2);//���������"/"
	private:	
		int numerator,denominator;
		void optimization();
};
void Fraction::optimization()
{
	int gcd,min,max;
	if(denominator==0)//��ĸΪ0
		{
		cout<<"A zero denominator is invalid"<<endl; 
	    exit(1);
		}
	gcd=(abs(numerator)>abs(denominator)?abs(denominator):abs(numerator));
	if(gcd==0) return;
	//������շת����������Լ��
	if(abs(numerator)>abs(denominator))
		{
		max=numerator;
		min=denominator;
		}
	else
		{
		min=numerator;
		max=denominator;
		}
	do
	{
		gcd=max%min;
		max=min;
		min=gcd;
	}while(gcd!=0);
	numerator/=max;
	denominator/=max;
	if(denominator<0)
    {
		numerator=-numerator;
		denominator=-denominator;
	}
}
Fraction::Fraction(int x,int y)
{
	numerator=x;
    denominator=y;
    optimization();
}
void Fraction::print()
{
	if(denominator==1)//������ʽ
		cout<<numerator<<endl;
	else if(numerator==0)//��ֵΪ�� 
		cout<<numerator<<endl;
	else
		cout<<numerator<<"/"<<denominator<<endl;
}
Fraction operator+(Fraction&num1,Fraction&num2)
{
	Fraction temp;
    //��ĸΪ���������ķ����ķ�ĸ�˻�
    //����Ϊ��һ�����ķ��ӳ��Եڶ������ķ�ĸ���ϵ�һ�����ķ�ĸ���Եڶ������ķ���
    temp.denominator=num1.denominator*num2.denominator; 
    temp.numerator=num1.numerator*num2.denominator+num1.denominator*num2.numerator; 
	temp.optimization();  
    return temp;
}
Fraction operator-(Fraction&num1,Fraction&num2)
{
	Fraction temp;
    //��ĸΪ���������ķ����ķ�ĸ�˻�
	//����Ϊ��һ�����ķ��ӳ��Եڶ������ķ�ĸ��ȥ��һ���ֵķ�ĸ���Եڶ������ķ���
	temp.denominator=num1.denominator*num2.denominator;                            
    temp.numerator=num1.numerator*num2.denominator-num1.denominator*num2.numerator; 
    temp.optimization(); 
	return temp;
}
Fraction operator*(Fraction&num1,Fraction&num2)
{
	Fraction temp;
    //��ĸΪ���������ķ����ķ�ĸ�˻�
    //����Ϊ���������ķ����ķ��ӳ˻�
    temp.denominator=num1.denominator*num2.denominator; 
    temp.numerator=num1.numerator*num2.numerator;  
    temp.optimization();
    return temp;
}
Fraction operator/(Fraction&num1,Fraction&num2)
{
	Fraction temp;
	//��ĸΪ��һ�������ķ�ĸ���Եڶ��������ķ���
	//����Ϊ��һ�������ķ��ӳ��Եڶ��������ķ�ĸ
	temp.denominator=num1.denominator*num2.numerator; 
    temp.numerator=num1.numerator*num2.denominator; 
	temp.optimization();
	return temp;
}
int main()
{
	cout<<"������һ���������:"<<endl;
	Fraction r1(2,8),r2(23,45),r3,r4(-63,789),r5(3),r6(56,-894),r7(0,3),r8(-12,-48);
    cout<<"ԭʼ���ݣ�  r1(2,8)"<<endl;
    cout<<"��������ݣ�r1=",r1.print();
    cout<<"ԭʼ���ݣ�  r2(23,45)"<<endl;
    cout<<"��������ݣ�r2=",r2.print();
    cout<<"ԭʼ���ݣ�  r3"<<endl;
    cout<<"��������ݣ�r3=",r3.print();
    cout<<"ԭʼ���ݣ�  r4(-63,789)"<<endl;
    cout<<"��������ݣ�r4=",r4.print();
    cout<<"ԭʼ���ݣ�  r5(3)"<<endl;
    cout<<"��������ݣ�r5=",r5.print();
    cout<<"ԭʼ���ݣ�  r6(56,-894)"<<endl;
    cout<<"��������ݣ�r6=",r6.print();
    cout<<"ԭʼ���ݣ�  r7(0,3)"<<endl;
    cout<<"��������ݣ�r7=",r7.print();
    cout<<"ԭʼ���ݣ�  r8(-12,-48)"<<endl;
    cout<<"��������ݣ�r8=",r8.print();
    cout<<"������һ��������:"<<endl;
    r3=r1+r2;
    cout<<"r1+r2=";r3.print();
    r3=r1-r2;
    cout<<"r1-r2=";r3.print();
    r3=r1*r2;
    cout<<"r1*r2=";r3.print();
    r3=r1/r2;
    cout<<"r1/r2=";r3.print();
    return 0;
}
