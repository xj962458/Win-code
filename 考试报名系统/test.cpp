#include<iostream>
#include<string>
#include"1.h"
#include"2.h"
using namespace std;
int main(){
	int amount, order;  //amount为考生人数 order为选择的命令
	linkedList STUlist;  //STUlist为考生链表
	STU testStudent = { 0, "", "", 0, "", NULL, NULL };
	cout << "首先请建立考生信息系统！" << endl << "请输入考生人数：";
	cin >> amount;
	while (amount < 1){
		cout << "考生人数必须大于1，请重新输入：";
		cin >> amount;
	}
	cout << "请依次输入考生的考号、姓名、性别、年龄及报考类别！" << endl;
	for (int iX = 0; iX < amount; iX++){  //获得考生的信息
		cin >> testStudent.stuTestNum >> testStudent.stuName >> testStudent.stuSex >> testStudent.stuAge >> testStudent.stuCategory;
		STUlist.addStu(testStudent);
	}
	cout << endl;
	STUlist.showStu();    //展示考生信息后选择操作
	cout << "请选择您要进行的操作：（1为插入，2为删除，3为查找，4为修改，5为统计，0为取消操作）" << endl;
	cout << endl << "请选择您要进行的操作:";
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
		STUlist.showStu();    //每次操作完后展示操作后的考生信息
		cout << "请选择您要进行的操作：";
		cin >> order;
	}
}