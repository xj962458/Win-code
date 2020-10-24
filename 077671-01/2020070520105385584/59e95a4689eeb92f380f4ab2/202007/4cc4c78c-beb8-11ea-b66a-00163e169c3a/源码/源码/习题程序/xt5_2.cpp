//xt5_2.cpp
#include <iostream>
#include <string>
using namespace std;
class Shape//���������Shape
{
	public: 
		Shape();//���캯��������ͼ�����
		void show();//������
		virtual double area()=0; //���麯�����������
        virtual string shapename()=0; //���麯�����õ���ʾͼ�ε�����
	protected:
		string name;
		static int count; //��¼ͼ�����
};
Shape::Shape()
{
	cout<<"������";
	count=count+1;
}
void Shape::show()
{
	 cout<<"��"<<count<<"��ͼ����"<<shapename();
     cout<<"�����Ϊ"<<area()<<endl;
}
double total(Shape *s[],int n) //ȫ�ֺ�������������ͼ�ε������
{
	double sum=0;
	for(int i=0;i<n;i++)
	{
		sum+=s[i]->area();
		delete s[i];
    }
	return sum;
}
class Triangle:public Shape//����������Triangle
{
	public:
        Triangle();//���캯�����õ������εĵ׺͸�
		double area(){return h*w*0.5;} //���麯���ľ���ʵ�֣����������ε����
        string shapename(){name="������";return name;}//�õ������ε�����
    protected:
		double h, w;
};
Triangle::Triangle()
{   
	double myw,myh;
	cout<<"�����εĵ׺͸ߣ�";
	cin >>myw>>myh;
	w=myw;
	h=myh;
	}
class Rectangle:public Shape//����������Rectangle 
{
	public:
		Rectangle();//���캯�����õ����εĳ��Ϳ�
		double area(){return l*w;} //���麯���ľ���ʵ�֣�������ε����
        string shapename(){name="����";return name;} //�õ����ε�����
    protected:
		double l, w;
};
Rectangle::Rectangle()
{
	double myl,myw;
	cout<<"���εĳ��Ϳ�";
	cin>>myl>>myw;
	l=myl;w=myw;
}
class Circle:public Shape//����������Circle
{
	public:
		Circle();//���캯�����õ�Բ�İ뾶
        double area(){return radius*radius*3.14;}// ʵ�ִ��麯��������Բ�����
        string shapename(){name="Բ";return name;} //�õ�Բ������
    protected:
		double radius;
};
Circle::Circle()
{
	double r;
	cout<<"Բ�İ뾶��";
	cin>>r;
	radius=r;}
int Shape::count=0;
int main()
{
	Shape *s[4];
    s[0]=new Triangle();
	s[0]->show();
    s[1]=new Rectangle();
    s[1]->show();
    s[2]=new Circle();
    s[2]->show();
	s[3]=new Circle();
	s[3]->show();
    double sum=total(s,4);
	cout<<"����ͼ�ε������Ϊ��";
    cout<<sum<<endl;
	return 0;
}
