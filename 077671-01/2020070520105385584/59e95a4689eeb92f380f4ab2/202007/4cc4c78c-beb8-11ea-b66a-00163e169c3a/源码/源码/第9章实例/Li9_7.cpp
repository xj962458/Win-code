//����Li9_7.cpp
//Ӧ��ʵ��
#include <iostream>
using namespace std;
class Heapclass
{
	public:
		Heapclass(int x); 
        Heapclass(); 
        ~Heapclass();
    private:
        int i;
};
Heapclass::Heapclass(int x) 
{
	i=x;
	cout<<"Constructor called."<<i<<endl;
}
Heapclass::Heapclass() 
{
	cout<<"Default Constructor called."<<endl;
}
Heapclass::~Heapclass() 
{
	cout<<"Destructor called."<<endl;
}
class Heapexception//�Զ���new�����쳣��
{
	public:
		Heapexception():message("Out of Memory!"){}
	    const char* what() const{return message;}
    private:
        const char*message;
};
int main()
{
	Heapclass *pa1,*pa2;
	try//����쳣
	{
	pa1=new Heapclass(4);//����ռ�
	pa2=new Heapclass;//����ռ�
	if (!pa1||!pa2)//���ռ�
		throw Heapexception();//�׳��쳣
	}
	catch(Heapexception e)//��׽�쳣
	{
         cout<<e.what()<<endl;
         return 0;
    }
	cout<<"Exit main"<<endl;
	delete pa1;
	delete pa2;
	return 0;
}

