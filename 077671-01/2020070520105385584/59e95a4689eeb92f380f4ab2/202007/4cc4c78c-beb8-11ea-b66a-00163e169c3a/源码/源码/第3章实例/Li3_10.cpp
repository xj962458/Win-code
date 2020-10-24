//����Li3_10.cpp
//�Ӷ���ĳ�ʼ��
#include <iostream>
using namespace std;
class Part
{
    public:
        Part();          //Part���޲ι��캯��
        Part (int x);  // Part���вι��캯��
        ~Part();        //Part����������
    private:
        int val;};
Part::Part()
{
	val=0;
    cout<<"Default constructor of Part"<<endl;
}
Part::Part(int x)
{   
	val=x;
    cout<<"Constructor of Part"<<","<<val<<endl;
}
Part::~Part()
{
	cout<<"Destructor of Part"<<","<<val<<endl;
}
class Whole
{
    public:
        Whole(int i);  // Whole���вι��캯��
        Whole(){};     //Whole���޲ι��캯��
        ~Whole();      //Whole����������
        private:
        Part p1;  //�Ӷ���
        Part p2; //�Ӷ���
};
Whole::Whole(int i):p1(),p2(i)
{
	cout<<"Constructor of Whole"<<endl;
}
Whole::~Whole()
{
	cout<<"Destructor of Whole"<<endl;
}
int main()
{   Whole w(3);//�����вι��캯��
    return 0;
}




