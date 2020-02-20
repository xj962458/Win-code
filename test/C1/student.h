#ifndef SHAPE_H	
#define SHAPE_H		
struct credit		//�γ�_ѧ�ֽṹ�嶨��
{
	char course[20];	//�γ���
	int hour;			//ѧ��
	char type[5];		//�γ�����
};
class Student			//����Student�Ķ���
{
	protected:
	 char *name;				//����
	 int student_ID;			//���˱��
	 credit credit_hour[10];	//ѡ�޵Ŀγ̺�ѧ��
	 int num;					//ѡ������
	public:
	 Student();					//���캯��
	 virtual~Student(){};		//����������
	 char *getname();			//��ʾ��������
	 virtual void InputInfor();			//����ѧ��������Ϣ
	 virtual void input_credit()=0;		//����γ̺�ѧ��
	 virtual void displayInfor()=0;		//��ʾѧ����Ϣ
	 virtual int GetStuNum()=0;			//ѧ������
};
class UnderGraduate:public Student		//������UnderGraduate�Ķ���		
{
	public:
	 virtual void InputInfor();				//����ѧ��������Ϣ
	 virtual void input_credit();			//����γ̺�ѧ��
	 virtual void displayInfor();			//��ʾѧ����Ϣ
	 int GetStuNum();						//ѧ������
	private:
	 static int StuNum;						//����ѧ������	
};											//������UnderGraduate�Ķ������
class Graduate:public Student				//������UnderGraduate�Ķ���
{
	public:
	 virtual void InputInfor();				//����ѧ��������Ϣ
	 virtual void input_credit();			//����γ̺�ѧ��
	 virtual void displayInfor();			//��ʾѧ����Ϣ
	 int GetStuNum();
	private:
	 static int StuNum;						//�о�������
	 char *tutor;							//��ʦ����
};											//������Graduate�������			
#endif								


	
