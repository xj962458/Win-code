#include "user.h"
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

User::User()
{
	head = new user;
	head->m_name = "admin";
	head->m_password = "123";
	head->next_user = nullptr;
}

User::~User()
{
	user* p = head;
	user* q = nullptr;
	while (p)
	{
		q = p;
		p = q->next_user;
		delete q;
	}
}

void User::readFile()
{
	string new_file = "user";
	fstream file;
	file.open(new_file.c_str(), ios::in);
	if (file.bad())
	{
		cout << "�ļ���ʧ��........." << endl;
		return;
	}
	int len = 0;
	file >> len;
	//cout << "len = " << len << endl;
	if (!len)
	{
		cout << "���½�����Ա�����ļ�����ע�����Ա�˺�....." << endl;
		login();
		return;
	}
	user pHead;
	file.get();
	while (len--)
	{
		file >> pHead.m_name;
		file >> pHead.m_password;
		insert(pHead);
	}
	file.close();
	
	cout << "���������Ա�˺��Ե�½......." << endl;
	return;
}

void User::saveFile()
{
	string new_file = "user";
	fstream file;
	file.open(new_file.c_str(), ios::out);
	if (file.bad())
	{
		cout << "�ļ���ʧ��.........." << endl;
		return;
	}
	int len = headCount() - 1;
	file << len << endl;
	user* pHead = head->next_user;
	while (pHead != nullptr)
	{
		file << pHead->m_name << endl;
		file << pHead->m_password << endl;
		pHead = pHead->next_user;
	}
	file.close();
	return;
}

bool User::insert(const user& astu)
{
	user* p = head;
	if (p->next_user == nullptr)  //��û����һ���ѣ����½�һ�����������޸�����
	{
		p->next_user = new user(astu);  //�ô�������޸Ľṹ��ʼ��
		p->next_user->next_user = nullptr;  //nullptr��������һ����
		return true;
	}
	while (p->next_user)  //��������һ����
	{
		if (p->next_user->m_name == astu.m_name)  //����
		{
			cout << "�û����ظ�������ʧ��......." << endl;
			return false;
		}
		p = p->next_user;  //�Ȳ�����Ҳ���ظ��ͺ������
	}
	p->next_user = new user(astu);
	p->next_user->next_user = nullptr;
	return true;
}

unsigned User::headCount()
{
	unsigned cnt = 0;
	user* p = nullptr;
	for (p = head; p; p = p->next_user, ++cnt);
	return cnt;
}

user* User::findByName(const string& name) const
{
	user* p = nullptr;
	for (p = head; p->next_user; p = p->next_user)
	{
		if (p->next_user->m_name == name)
		{
			return p;
		}
	}
	return nullptr;
}

void User::deleteByName()
{
	user* p = nullptr;
	user* q = nullptr;
	cout << "������Ҫɾ�����û�����" << endl;
	string name;
	cin >> name;
	p = findByName(name);
	if (p == nullptr)
	{
		cout << "û���ҵ��˺� \"" << name << "\", ɾ��ʧ��....." << endl;
	}
	q = p->next_user;
	p->next_user = nullptr;
	delete q;
	cout << "�ɹ�ɾ�� \"" << name << "\"���˺�......." << endl;
	saveFile();
}

void User::show()
{
	user* p = nullptr;
	cout << "------------------------------------\n" << endl;
	for (p = head->next_user; p; p = p->next_user)
	{
		cout << "�û�����" << p->m_name << "	���룺" << p->m_password << endl;
	}
	cout << "------------------------------------\n" << endl;
}

void User::login()
{
	user tmp;
	cout << "������ע���õ��û�����";
	cin >> tmp.m_name;
	if (findByName(tmp.m_name) == nullptr)
	{
		cout << "������ע���õ����룺";
		cin >> tmp.m_password;
		insert(tmp);
	}
	else
	{
		cout << "��������û�����" << tmp.m_name << "�Ѵ��ڣ������������û���" << endl;
		login();
	}
	saveFile();
}

bool User::logon()
{
	cout << "��½" << endl;
	cout << "�������½�û�����";
	string name;
	cin >> name;
	user* p = nullptr;
	if (findByName(name))
	{
		p = findByName(name);
		cout << "�������½���룺";
		string password;
		cin >> password;
		if (p->next_user->m_password == password)
		{
			cout << "��½�ɹ�.........." << endl;
			return true;
		}
		else
		{
			cout << "��½�����������������...." << endl;
			logon();
		}
	}
	else
	{
		cout << "û���ҵ����û�����" << endl;
		logon();
	}
	return false;
}