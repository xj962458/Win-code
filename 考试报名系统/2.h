#pragma once
#include "1.h"
#include <iostream>
using namespace std;
STU *head = NULL;           //头指针
STU *endp = NULL;             //尾指针
linkedList::linkedList(){
	stuNum = 0;          //学号初始化为0
}
linkedList::~linkedList(){//析构函数，删除链表每一个节点
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
/*用户输入插入位置，插入方式为调用类方法findStu(int pos)找到该位置，
判断该位置是第一个、最后一个还是中间的位置。然后操作前后指针进行插入，
同时动态生成需要插入的数据，最后链表长度加一。*/
void linkedList::insertStu(){
	int pos;
	STU *insertStu = new STU;				//插入考生信息，先获得考生的位置
	cout << "请输入你要插入的考生的位置：";
	cin >> pos;

	if (pos != stuNum + 1){
		STU *temp = findStu(pos);
		//容错操作
		while (!temp){
			cout << "对不起，没有找到您所要求插入的位置，请重新输入位置, 或者按0取消：";
			int pos2;
			cin >> pos2;
			if (pos2 == 0)
				return;
			temp = findStu(pos2);
		}
		cout << "请依次输入要插入的考生的考号，姓名，性别，年龄及报考类别！" << endl;
		cin >> insertStu->stuTestNum >> insertStu->stuName >> insertStu->stuSex >> insertStu->stuAge >> insertStu->stuCategory;
		//在获得考生的各项信息后，进行插入操作
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
		cout << endl << "请依次输入要插入的考生的考号，姓名，性别，年龄及报考类别！" << endl;
		cin >> insertStu->stuTestNum >> insertStu->stuName >> insertStu->stuSex >> insertStu->stuAge >> insertStu->stuCategory;
		//头指针为空
		if (!head){
			head = insertStu;
			endp = insertStu;
		}
		//头指针不为空
		else{
			endp->next = insertStu;
			insertStu->pre = endp;
			insertStu->next = NULL;
			endp = insertStu;
		}
	}
	stuNum++;

}
/*复制考生的信息,student1复制的，student2为被复制的*/
void linkedList::copyStu(STU *student1, STU &student2){
	student1->stuAge = student2.stuAge;
	student1->stuCategory = student2.stuCategory;
	student1->stuName = student2.stuName;
	student1->stuSex = student2.stuSex;
	student1->stuTestNum = student2.stuTestNum;
}
void linkedList::addStu(STU &item){
	STU *student = new STU;
	if (!student){	//容错操作
		cout << "错误" << endl;
		return;
	}
	copyStu(student, item);//先复制考生的信息到student
	stuNum++;
	if (!head){
		head = student;
		endp = student;
	}
	//如果链表不为空
	else{
		endp->next = student;
		student->pre = endp;
		student->next = NULL;
		endp = student;
	}
}
/*根据输入的考生的考号，先判断其位置，找到需要删除的结构体之后，
对其前后指针进行操作，
将其从链表中脱离出来，然后将其内存释放。*/
void linkedList::deleteStu(){
	int deleteNum;
	STU *deleteStu;
	cout << "请输入要删除的考生的考号：";//通过用户输入的学号寻找考生的信息
	cin >> deleteNum;
	deleteStu = findStu(deleteNum);
	cout << "你删除的考生信息是：";
	cout << deleteStu->stuTestNum << "       " << deleteStu->stuName << "    " << deleteStu->stuSex << "      "
		<< deleteStu->stuAge << "        " << deleteStu->stuCategory << endl;
	if (deleteStu->pre != NULL && deleteStu->next != NULL){
		deleteStu->pre->next = deleteStu->next;
		deleteStu->next->pre = deleteStu->pre;
		delete deleteStu;
	}
	//删除考试位于队首
	if (deleteStu->pre == NULL && deleteStu->next != NULL){
		deleteStu->next->pre = NULL;
		head = deleteStu->next;
		delete deleteStu;
	}
	//删除考生位于队尾
	if (deleteStu->pre != NULL && deleteStu->next == NULL){
		deleteStu->pre->next = NULL;
		endp = deleteStu->pre;
		delete deleteStu;
	}
	stuNum--;
}
void linkedList::editStu(){
	STU *editStu;
	int pos;   //根据用户输入的考生的考号进行修改
	cout << "请依次输入要修改考生的考号，姓名，性别，年龄以及报考类别！" << endl;
	cin >> pos;
	editStu = findStu(pos);
	editStu->stuTestNum = pos;
	cin >> editStu->stuName >> editStu->stuSex >> editStu->stuAge >> editStu->stuCategory;
}
/*根据用户插入的位置，建立一个头指针，
依次从头寻找到该位置，将该位置考生的信息输出。*/
void linkedList::findStu(){
	int searchNum;
	STU *searchStu = head;
	cout << "请输入要查找的考生的考号：";
	cin >> searchNum;
	for (int iX = 0; iX < stuNum; iX++){
		if (searchStu->stuTestNum == searchNum){
			cout << "考号    姓名    性别    年龄      类别" << endl;
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
/*方法与寻找函数类似，建立一个头指针之后不断遍历每个节点输出信息*/
void linkedList::showStu(){
	STU *showStu = head;

	cout << "考号    姓名    性别    年龄      类别" << endl;
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
	STU *staStu = head;		//首先统计了报考考生的人数
	cout << "一共有考生：" << stuNum << "人" << endl;
	cout << "请输入要统计的报考类别：";
	cin >> category;			//其次统计了报考类别的人数
	for (int iX = 0; iX < stuNum; iX++){
		if (staStu->stuCategory == category){
			count++;
			staStu = staStu->next;
		}
		else
			staStu = staStu->next;
	}
	cout << "报考" << category << "的考生共有" << count << "人" << endl;
}
