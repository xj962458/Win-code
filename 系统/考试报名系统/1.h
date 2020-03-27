#pragma once
#include<string>
#include<iostream>

using namespace std;
struct STU
{
	int stuTestNum;		    //考号
	string stuName; 		//姓名
	string stuSex;          //性别
	int stuAge;             //年龄
	string stuCategory;     //报考类别

	STU *pre;               //前指针
	STU *next;              //后指针
};

class linkedList{
private:
	int stuNum;             //考生人数
public:
	linkedList();
	~linkedList();

	void addStu(STU &item);									   	 //添加考生信息
	void deleteStu();											 //删除考生信息
	void insertStu();											 //插入考生信息
	void editStu();												 //修改考生信息
	void staStu();												 //统计考生信息
	void copyStu(STU *student1, STU &student2);                  //复制考生信息
	void showStu();												 //展示所有考生信息
	STU *findStu(int item);										 //查找考生信息
	void findStu();
};
