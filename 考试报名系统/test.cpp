#include<iostream>
#include<string>
#include"1.h"
#include"2.h"
using namespace std;
int main(){
	int amount, order;  //amountΪ�������� orderΪѡ�������
	linkedList STUlist;  //STUlistΪ��������
	STU testStudent = { 0, "", "", 0, "", NULL, NULL };
	cout << "�����뽨��������Ϣϵͳ��" << endl << "�����뿼��������";
	cin >> amount;
	while (amount < 1){
		cout << "���������������1�����������룺";
		cin >> amount;
	}
	cout << "���������뿼���Ŀ��š��������Ա����估�������" << endl;
	for (int iX = 0; iX < amount; iX++){  //��ÿ�������Ϣ
		cin >> testStudent.stuTestNum >> testStudent.stuName >> testStudent.stuSex >> testStudent.stuAge >> testStudent.stuCategory;
		STUlist.addStu(testStudent);
	}
	cout << endl;
	STUlist.showStu();    //չʾ������Ϣ��ѡ�����
	cout << "��ѡ����Ҫ���еĲ�������1Ϊ���룬2Ϊɾ����3Ϊ���ң�4Ϊ�޸ģ�5Ϊͳ�ƣ�0Ϊȡ��������" << endl;
	cout << endl << "��ѡ����Ҫ���еĲ���:";
	cin >> order;
	while (order != 0){
		switch (order)
		{
		case 1:
			STUlist.insertStu();
			break;
		case 2:
			STUlist.deleteStu();
			break;
		case 3:
			STUlist.findStu();
			break;
		case 4:
			STUlist.editStu();
			break;
		case 5:
			STUlist.staStu();
			break;
		default:
			break;
		}
		cout << endl;
		STUlist.showStu();    //ÿ�β������չʾ������Ŀ�����Ϣ
		cout << "��ѡ����Ҫ���еĲ�����";
		cin >> order;
	}
}