#pragma once
#ifndef STUDENT_H
#define STUDENT_H

#include <string>
#include <fstream>
using namespace std;

typedef struct student
{
	//unsigned��ʡ�Ժ�һ���ؼ��֣��������������Ĭ��Ϊunsigned int
	unsigned stu_id;	   //ѧ��
	string stu_name;	   //����
	unsigned stu_age;	  //����
	string stu_sex;		   //�Ա�
	string stu_birth;	  //����
	string stu_tel;		   //�绰
	string stu_email;	  //�����ʼ�
	string stu_department; //ϵ��
	string stu_major;	  //רҵ
	string stu_class;	  //�༶
	student *stu_next;	 //���߽ṹ����
} student;

class Student
{
public:
	Student();  //���캯��
	~Student(); //��������

	//¼��ѧ����Ϣ
	//�ӱ�׼�����д���ѧ����model = 1:����ȡѧ�ţ�2������ȡ��������������ȡ������Ϣ
	student *createByStdin(int model, student &tmp);
	void logon(); //����¼��ѧ����Ϣ

	//����
	void Query() const;								 //��ѯѧ����Ϣ
	student *findById(unsigned id) const;			 //����ѧ�Ų���
	student *findByName(const string &name) const;   //������������
	student *findBySex(const string &sex) const;	 //�����Ա����
	student *findByEmail(const string &email) const; //���ݵ����ʼ�����

	//ɾ��
	void deleteBy();				 //ɾ��
	bool deleteById(unsigned &id);   //����ѧ��ɾ��
	bool deleteByName(string &name); //��������ɾ��

	//�޸�
	void modify();		 //�޸�
	bool modifyById();   //����ѧ���޸�
	bool modifyByName(); //���������޸�

	//��ʾ
	void Show() const; //�г�ѧ����Ϣ

	//�ļ�����
	void saveToFile(); //���浽�ļ�
	void readFile();   //��ȡ�ļ�
	bool insert(const student &astu);

	unsigned headCount() const;

private:
	student *head; //ȫ�ֵ��������������ָ��
};

#endif