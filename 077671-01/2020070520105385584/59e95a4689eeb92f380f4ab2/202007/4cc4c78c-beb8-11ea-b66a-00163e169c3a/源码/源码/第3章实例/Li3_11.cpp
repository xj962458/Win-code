//����Li3_11.cpp
//new��delete���÷�
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
int main()
{
	Heapclass *pa1,*pa2;
	pa1=new Heapclass(4);//����ռ�
	pa2=new Heapclass;//����ռ�
	if (!pa1||!pa2)//���ռ�
	{
		cout<<"Out of Memory!"<<endl;
		return 0;
	}	
	cout<<"Exit main"<<endl;
	delete pa1;
	delete pa2;
	return 0;
}

