#pragma once
#include<string>
#include<iostream>

using namespace std;
struct STU
{
	int stuTestNum;		    //����
	string stuName; 		//����
	string stuSex;          //�Ա�
	int stuAge;             //����
	string stuCategory;     //�������

	STU *pre;               //ǰָ��
	STU *next;              //��ָ��
};

class linkedList{
private:
	int stuNum;             //��������
public:
	linkedList();
	~linkedList();

	void addStu(STU &item);									   	 //��ӿ�����Ϣ
	void deleteStu();											 //ɾ��������Ϣ
	void insertStu();											 //���뿼����Ϣ
	void editStu();												 //�޸Ŀ�����Ϣ
	void staStu();												 //ͳ�ƿ�����Ϣ
	void copyStu(STU *student1, STU &student2);                  //���ƿ�����Ϣ
	void showStu();												 //չʾ���п�����Ϣ
	STU *findStu(int item);										 //���ҿ�����Ϣ
	void findStu();
};