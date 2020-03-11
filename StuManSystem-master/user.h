#pragma once
#ifndef USER_H
#define USER_H
#include <string>

using namespace std;

typedef struct user
{
	string m_name;  //�û���
	string m_password;  //����
	user* next_user;  //����
}user;

class User
{
public:
	User();
	~User();
	user* findByName(const string& name) const;  //�����ļ��е��û���
	//�Ǿ�̬��Ա���������const����thisָ�룬��ʾ�������޸ĳ�Ա����
	void readFile();  //��ȡ�ļ�
	void saveFile();  //�����ļ�
	void login();  //ע�ắ��
	bool logon();  //��½����
	unsigned headCount();  //�ṹ��������
	bool insert(const user& astu);  //���뺯��
	void deleteByName();  //ɾ������
	void show();   //��ʾ����
private:
	user* head;
};

#endif
