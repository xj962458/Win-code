//����Li3_12.cpp
//�����new[ ]��delete[ ]���÷�
#include <iostream>
using namespace std;
class Heapclass
{
   int i;
   public:
   Heapclass(); 
   ~Heapclass();
};
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
	Heapclass *ptr;
	ptr=new Heapclass[2];//����ռ�
	if (!ptr)//���ռ�
	{
		cout<<"Out of Memory!"<<endl;
		return ;
	}	
	cout<<"Exit main"<<endl;
	delete[ ]ptr; 
	return 0;
}
