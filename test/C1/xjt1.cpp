#include<iostream>
#include<iomanip>
using namespace::std;
#include"student.h"	
#include<string.h>	//����ͷ�ļ�

int UnderGraduate::StuNum=0;	//��̬���ݳ�Ա��ʼ��
int Graduate::StuNum=0;			//��̬���ݳ�Ա��ʼ��
Student::Student()		//Student�๹�캯��
{
	num=0;				//ѡ������ʼ��Ϊ0
}
void Student::InputInfo()		//Student��InputInfo����
{
	char namestr[20];			//����ѧ��������ʱ�����namestr��
	cout<<"��������һ��ͬѧ������";
	cin>>namestr;
	name=new char[strlen(namestr)+1];	//Ϊָ��name�����ַ
	strcpy(name,namestr);				//����ʱ��ŵ��������Ƶ�name
	cout<<"����ѧ����ѧ��";
	cin>>student_ID;
}
	
char *Student::getname()		//Student����ʾ��������
{
	return name;
}
void UnderGraduate::InputInfo()	//���뱾������Ϣ����
{
	Student::InputInfo();
	stuNum++;					//������������1
}
void UnderGraduate::input_credit()		//���뱾����ѡ�޵Ŀγ̺�ѧ��
{
	char answer;
	do{
		cout<<"����γ����ơ�ѧ�֡��γ���𣺱���/ѡ��\n";
		cin>>credit_hour[num].course>>credit_hour[num].hour>>credit_hour[num].type;
		num++;
		cout<<"��������γ�?\n";
		cin>>answer;
	}while(answer=='y');
}
int	UnderGraduate::GetStuNum()	//ȡ�ñ���������
{
	return StuNum;
}
void UnderGraduate::displayInfo()		//��ʾ��������Ϣ
{
	cout<<"����������:"<<name;
	cout<<"		ѧ�ţ�"<<student_ID<<endl;
	cout<<"�γ�����	ѧ��		�γ���� \n";
	for(int i=0;i<num;i++)
		cout<<left<<setw(10)<<credit_hour[i].course
		<<setw(10)<<credit_hour[i].hour
		<<setw(10)<<credit_hour[i].type<<endl;
}
void Graduate::InputInfor()		
{
	char namestr[20];		//���뵼ʦ������ʱ�����namestr��
	Student::InputInfo();
	StuNum++;
	cout<<"�����뵼ʦ����:";
	cin>>namestr;
	tutor=new char[strlen(namestr)+1];	//Ϊָ��tutor�����ַ
	strcpy(tutor,namestr);			//����ʱ��ŵ��������Ƶ�tutor
}
void Graduate::input_credit()		//�����о���ѡ�޿γ̺�ѧ��
{
	char answer;
	do{
		cout<<"����γ����ơ�ѧ�֡��γ����	ѧλ/��ѡ\n";
		cin>>credit_hour[num].course>>credit_hour[num].hour>>credit_hour.type;
		num++;
		cout<<"���пγ�Ҫ���룿 ";
		cin>>answer;
	}while(answer=='y');
}
int Graduate::GetStuNum()		//��ʾ�о�����Ϣ
{
	return StuNum;
}
void Graduate::displayInfo()
{
	cout<<"�о���������"<<name;
	cout<<"		ѧ�ţ�"<<student_ID<<endl;
	cout<<"		��ʦ������"<<tutor<<endl;
	cout<<"�γ�����	ѧ��		�γ����	\n";
	for(int i=0;i<num;i++)
	cout<<left<<setw(10)<<credit_hour[i].course
		<<setw(10)<<credit_hour[i].hour
		<<stew(10)<<credit_hour[i].type<<endl;
}
