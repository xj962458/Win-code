//�����嵥Li1_2
//���������
#include <iostream>
using namespace std;
class RectangleArea
{
	
    public:
		void SetData(float L,float W);//���볤����ֵ
        float CompueterArea();//�������
        void OutputArea();//������
	private: 
		float length,width,area; //���峤�������
};
void RectangleArea::SetData(float L,float W)
{
	length=L;
	width=W;
}
float RectangleArea::CompueterArea()
{
    area=length*width;
	return area;
}
void RectangleArea::OutputArea()
{
	cout<<"area="<<area<<endl;
}
int main()
{
	RectangleArea Rectangl;//��������
	Rectangl.SetData(8,9);//
    Rectangl.CompueterArea();
    Rectangl.OutputArea();
	return 0;
}
