#pragma once
#include "1.h"
#include <iostream>
using namespace std;
STU *head = NULL;           //ͷָ��
STU *endp = NULL;             //βָ��
linkedList::linkedList(){
	stuNum = 0;          //ѧ�ų�ʼ��Ϊ0
}
linkedList::~linkedList(){//����������ɾ������ÿһ���ڵ�
	STU * p = head;
	STU *temp;
	while (p != head)
	{
		temp = p;
		p = p->next;
		delete temp;
	}
	delete p;
}
/*�û��������λ�ã����뷽ʽΪ�����෽��findStu(int pos)�ҵ���λ�ã�
�жϸ�λ���ǵ�һ�������һ�������м��λ�á�Ȼ�����ǰ��ָ����в��룬
ͬʱ��̬������Ҫ��������ݣ���������ȼ�һ��*/
void linkedList::insertStu(){
	int pos;
	STU *insertStu = new STU;				//���뿼����Ϣ���Ȼ�ÿ�����λ��
	cout << "��������Ҫ����Ŀ�����λ�ã�";
	cin >> pos;

	if (pos != stuNum + 1){
		STU *temp = findStu(pos);
		//�ݴ����
		while (!temp){
			cout << "�Բ���û���ҵ�����Ҫ������λ�ã�����������λ��, ���߰�0ȡ����";
			int pos2;
			cin >> pos2;
			if (pos2 == 0)
				return;
			temp = findStu(pos2);
		}
		cout << "����������Ҫ����Ŀ����Ŀ��ţ��������Ա����估�������" << endl;
		cin >> insertStu->stuTestNum >> insertStu->stuName >> insertStu->stuSex >> insertStu->stuAge >> insertStu->stuCategory;
		//�ڻ�ÿ����ĸ�����Ϣ�󣬽��в������
		if (temp->pre != NULL){
			temp->pre->next = insertStu;
			insertStu->pre = temp->pre;
			insertStu->next = temp;
			temp->pre = insertStu;
		}

		else{
			insertStu->next = temp;
			insertStu->pre = NULL;
			temp->pre = insertStu;
			head = insertStu;
		}
	}
	else{
		cout << endl << "����������Ҫ����Ŀ����Ŀ��ţ��������Ա����估�������" << endl;
		cin >> insertStu->stuTestNum >> insertStu->stuName >> insertStu->stuSex >> insertStu->stuAge >> insertStu->stuCategory;
		//ͷָ��Ϊ��
		if (!head){
			head = insertStu;
			endp = insertStu;
		}
		//ͷָ�벻Ϊ��
		else{
			endp->next = insertStu;
			insertStu->pre = endp;
			insertStu->next = NULL;
			endp = insertStu;
		}
	}
	stuNum++;

}
/*���ƿ�������Ϣ,student1���Ƶģ�student2Ϊ�����Ƶ�*/
void linkedList::copyStu(STU *student1, STU &student2){
	student1->stuAge = student2.stuAge;
	student1->stuCategory = student2.stuCategory;
	student1->stuName = student2.stuName;
	student1->stuSex = student2.stuSex;
	student1->stuTestNum = student2.stuTestNum;
}
void linkedList::addStu(STU &item){
	STU *student = new STU;
	if (!student){	//�ݴ����
		cout << "����" << endl;
		return;
	}
	copyStu(student, item);//�ȸ��ƿ�������Ϣ��student
	stuNum++;
	if (!head){
		head = student;
		endp = student;
	}
	//�������Ϊ��
	else{
		endp->next = student;
		student->pre = endp;
		student->next = NULL;
		endp = student;
	}
}
/*��������Ŀ����Ŀ��ţ����ж���λ�ã��ҵ���Ҫɾ���Ľṹ��֮��
����ǰ��ָ����в�����
��������������������Ȼ�����ڴ��ͷš�*/
void linkedList::deleteStu(){
	int deleteNum;
	STU *deleteStu;
	cout << "������Ҫɾ���Ŀ����Ŀ��ţ�";//ͨ���û������ѧ��Ѱ�ҿ�������Ϣ
	cin >> deleteNum;
	deleteStu = findStu(deleteNum);
	cout << "��ɾ���Ŀ�����Ϣ�ǣ�";
	cout << deleteStu->stuTestNum << "       " << deleteStu->stuName << "    " << deleteStu->stuSex << "      "
		<< deleteStu->stuAge << "        " << deleteStu->stuCategory << endl;
	if (deleteStu->pre != NULL && deleteStu->next != NULL){
		deleteStu->pre->next = deleteStu->next;
		deleteStu->next->pre = deleteStu->pre;
		delete deleteStu;
	}
	//ɾ������λ�ڶ���
	if (deleteStu->pre == NULL && deleteStu->next != NULL){
		deleteStu->next->pre = NULL;
		head = deleteStu->next;
		delete deleteStu;
	}
	//ɾ������λ�ڶ�β
	if (deleteStu->pre != NULL && deleteStu->next == NULL){
		deleteStu->pre->next = NULL;
		endp = deleteStu->pre;
		delete deleteStu;
	}
	stuNum--;
}
void linkedList::editStu(){
	STU *editStu;
	int pos;   //�����û�����Ŀ����Ŀ��Ž����޸�
	cout << "����������Ҫ�޸Ŀ����Ŀ��ţ��������Ա������Լ��������" << endl;
	cin >> pos;
	editStu = findStu(pos);
	editStu->stuTestNum = pos;
	cin >> editStu->stuName >> editStu->stuSex >> editStu->stuAge >> editStu->stuCategory;
}
/*�����û������λ�ã�����һ��ͷָ�룬
���δ�ͷѰ�ҵ���λ�ã�����λ�ÿ�������Ϣ�����*/
void linkedList::findStu(){
	int searchNum;
	STU *searchStu = head;
	cout << "������Ҫ���ҵĿ����Ŀ��ţ�";
	cin >> searchNum;
	for (int iX = 0; iX < stuNum; iX++){
		if (searchStu->stuTestNum == searchNum){
			cout << "����    ����    �Ա�    ����      ���" << endl;
			cout << searchStu->stuTestNum << "       " << searchStu->stuName << "    " << searchStu->stuSex << "      "
				<< searchStu->stuAge << "        " << searchStu->stuCategory << endl;
			break;
		}
		else
			searchStu = searchStu->next;
	}
}
STU *linkedList::findStu(int item){
	STU *searchStu = head;
	for (int iX = 0; iX < stuNum; iX++){
		if (searchStu->stuTestNum == item)
			return searchStu;
		else
			searchStu = searchStu->next;
	}
	return NULL;
}
/*������Ѱ�Һ������ƣ�����һ��ͷָ��֮�󲻶ϱ���ÿ���ڵ������Ϣ*/
void linkedList::showStu(){
	STU *showStu = head;

	cout << "����    ����    �Ա�    ����      ���" << endl;
	for (int iX = 0; iX < stuNum; iX++){
		cout << showStu->stuTestNum << "       " << showStu->stuName << "    " << showStu->stuSex << "      "
			<< showStu->stuAge << "        " << showStu->stuCategory << endl;
		showStu = showStu->next;
	}
	cout << endl;
}
void linkedList::staStu(){
	string category;
	int count = 0;
	STU *staStu = head;		//����ͳ���˱�������������
	cout << "һ���п�����" << stuNum << "��" << endl;
	cout << "������Ҫͳ�Ƶı������";
	cin >> category;			//���ͳ���˱�����������
	for (int iX = 0; iX < stuNum; iX++){
		if (staStu->stuCategory == category){
			count++;
			staStu = staStu->next;
		}
		else
			staStu = staStu->next;
	}
	cout << "����" << category << "�Ŀ�������" << count << "��" << endl;
}
