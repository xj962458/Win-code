//��3_10.cpp
//�þ�̬���ݳ�Ա���Ƶ���
#include <iostream>  
using namespace std;
class Point	 
{
	public:
		int getresource(  );
		void freeresource(  )  {resource = 0;}
	private:
		static  int  resource;
 };
int Point::resource=0;  // ����̬��Ա����ֵ0����ʾ�㲻���Ա����� 
int Point::getresource( )
{
	if(resource)  return 0;  
	else 
	{
		resource=1;
		return 1;  
	}
}
int main( )
{
   Point obj1, obj2;
   if(obj1.getresource(  ))  
	   cout << "objl�ڷ��ʵ�����Դ"<<endl;
   if(!obj2.getresource()) 
	   cout << "obj2���ڲ����ܷ��ʵ�����Դ"<<endl;
  obj1.freeresource() ;// objl��ɷ��ʵ�����Դ
  if (obj2.getresource())
     cout << "obj2�ڷ��ʵ�����Դ "<<endl;
  return 0;
}