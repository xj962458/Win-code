//����Li3_16.cpp
//��Ԫ���ʹ�á�
#include <iostream>
#include <cmath>
using namespace std;
class student
{
	public:
		friend class teacher;//teacher��student����Ԫ��
        student(){};
	private:
        int number,score;//ѧ��,�ɼ�
		 
};
class teacher
{
	public:
      teacher(int i,int j);
      void display();
    private:
		student a;
};
teacher::teacher(int i,int j)
{
    a.number=i;
	a.score=j;
}
void teacher::display()
{
    cout<<"No="<<a.number<<" ";
	cout<<"score="<<a.score<<endl;
}

int main()
{  
    student s;
	teacher t1(1001,89),t2(1002,78);
	cout<<"��һ��ѧ������Ϣ  ";
	t1.display();
    cout<<"�ڶ���ѧ������Ϣ  ";
	t2.display();
	return 0;
}
