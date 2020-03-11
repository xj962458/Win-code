#include "student.h"
#include <iostream>

using namespace std;

string filename("untitled");
void show(student *p);

Student::Student()
{
	head = new student;
	head->stu_id = 0;
	head->stu_name = "No name";
	head->stu_next = nullptr;
}

Student::~Student()
{
	student *p = head;
	student *q = nullptr;
	while (p)
	{
		q = p;
		p = q->stu_next;
		delete q;
	}
}

//ע�ắ��
void Student::logon()
{
	student tmp;
	cout << "ѧ��(0��������)��";
	cin >> tmp.stu_id;

	while (tmp.stu_id)
	{
		if (findById(tmp.stu_id) == nullptr)
		{
			cout << "������";
			cin >> tmp.stu_name;
			cout << "���䣺";
			cin >> tmp.stu_age;
			cout << "�Ա�";
			cin >> tmp.stu_sex;
			cout << "���᣺";
			cin >> tmp.stu_birth;
			cout << "ϵ��";
			cin >> tmp.stu_department;
			cout << "רҵ��";
			cin >> tmp.stu_major;
			cout << "�༶��";
			cin >> tmp.stu_class;
			cout << "�绰��";
			cin >> tmp.stu_tel;
			cout << "�������䣺";
			cin >> tmp.stu_email;
			insert(tmp);
		}
		else
		{
			cout << "�ظ���ѧ�ţ�" << tmp.stu_id << endl;
		}
		cout << "ѧ��(0��������)��";
		cin >> tmp.stu_id;
	}
}

//���Һ���
void Student::Query() const
{
	int select;
	unsigned id;
	string name;
	string sex;
	string email;
	student *p;
	cout << "1.��ѧ�Ų�ѯ\n2.��������ѯ\n3.���Ա��ѯ\n4.��email��ѯ\n0.����\n";
	cin >> select;
	switch (select)
	{
	case 1:
		cout << "������Ҫ���ҵ�ѧ�ţ�";
		cin >> id;
		if ((p = findById(id)))
		{
			show(p->stu_next);
		}
		break;
	case 2:
		cout << "������Ҫ���ҵ�������";
		cin >> name;
		if ((p = findByName(name)))
		{
			show(p->stu_next);
		}
		break;
	case 3:
		cout << "������Ҫ���ҵ��Ա�";
		cin >> sex;
		if ((p = findBySex(sex)))
		{
			show(p->stu_next);
		}
		break;
	case 4:
		cout << "������Ҫ���ҵ�email��";
		cin >> email;
		if ((p = findByEmail(email)))
		{
			show(p->stu_next);
		}
		break;
	case 0:
		return;
	default:
		cout << "����ʧ�ܣ�������ѡ����ҵķ�ʽ��" << endl;
	}
}

student *Student::findByEmail(const string &email) const
{
	student *p;
	for (p = head; p->stu_next; p = p->stu_next)
	{
		if (p->stu_next->stu_email == email)
		{
			return p;
		}
	}
	cout << "û���ҵ������email!" << endl;
	return nullptr;
}

student *Student::findBySex(const string &sex) const
{
	student *p;
	for (p = head; p->stu_next; p = p->stu_next)
	{
		if (p->stu_next->stu_sex == sex)
		{
			return p;
		}
	}
	cout << "û���ҵ�������Ա���û���" << endl;
	return nullptr;
}

student *Student::findByName(const string &name) const
{
	student *p;
	for (p = head; p->stu_next; p = p->stu_next)
	{
		if (p->stu_next->stu_name == name)
		{
			return p;
		}
	}
	cout << "û���ҵ������������" << endl;
	return nullptr;
}

student *Student::findById(unsigned id) const
{
	student *p;
	for (p = head; p->stu_next; p = p->stu_next)
	{
		if (p->stu_next->stu_id == id)
		{
			return p;
		}
	}
	cout << "û���ҵ������ID��" << endl;
	return nullptr;
}

//ɾ������
void Student::deleteBy()
{
	int select;
	unsigned id;
	string name;
	cout << "1.��ѧ��ɾ��\n2.������ɾ��\n0.����\n";
	cin >> select;
	switch (select)
	{
	case 1:
		cout << "��������Ҫɾ����ѧ�ţ�";
		cin >> id;
		deleteById(id);
		break;
	case 2:
		cout << "����������Ҫɾ����������";
		cin >> name;
		deleteByName(name);
		break;
	case 0:
		return;
	default:
		cout << "ɾ��ʧ�ܣ�������ѡ��ɾ���ķ�ʽ��" << endl;
	}
}

bool Student::deleteById(unsigned &id)
{
	student *p = nullptr;
	student *q = nullptr;
	p = findById(id);
	if (p == nullptr)
	{
		cout << "û���ҵ�ѧ���ǣ�\"" << id << "\"��ѧ����ɾ��ʧ�ܣ�" << endl;
		return false;
	}
	q = p->stu_next;
	p->stu_next = q->stu_next;
	delete q;
	cout << "�ɹ�ɾ��ѧ��Ϊ��\"" << id << "\"��ѧ������Ϣ" << endl;
	return true;
}

bool Student::deleteByName(string &name)
{
	student *p = nullptr;
	student *q = nullptr;
	p = findByName(name);
	if (p == nullptr)
	{
		cout << "û���ҵ�����Ϊ��\"" << name << "\"��ѧ����ɾ��ʧ�ܣ�" << endl;
		return false;
	}
	q = p->stu_next;
	p->stu_next = q->stu_next;
	delete q;
	cout << "�ɹ�ɾ������Ϊ��\"" << name << "\"����Ϣ\n";
	return true;
}

//�޸ĺ���
void Student::modify()
{
	int select;
	cout << "1.��ѧ���޸�\n2.�������޸�\n0.����\n";
	cin >> select;
	switch (select)
	{
	case 1:
		if (modifyById())
		{
			cout << "�޸ĳɹ���\n";
		}
		break;
	case 2:
		if (modifyByName())
		{
			cout << "�޸ĳɹ���\n";
		}
		break;
	case 0:
		return;
	default:
		cout << "�޸�ʧ�ܣ�������ѡ���޸ĵķ�ʽ��" << endl;
		break;
	}
}

bool Student::modifyById()
{
	student *p = nullptr;
	unsigned id;
	cout << "������Ҫ�޸ĵ�ѧ�ţ�" << endl;
	cin >> id;
	p = findById(id);
	if (p == nullptr)
	{
		cout << "û���ҵ�ѧ���ǣ�\"" << id << "\"��ѧ�����޸�ʧ�ܣ�\n";
		return false;
	}
	createByStdin(1, *(p->stu_next));
	return true;
}

bool Student::modifyByName()
{
	student *p;
	string name;
	cout << "��������Ҫ�޸ĵ�������";
	cin >> name;
	p = findByName(name);
	if (p == nullptr)
	{
		cout << "û���ҵ�����Ϊ��\"" << name << "\"��ѧ�����޸�ʧ�ܣ�\n";
		return false;
	}
	createByStdin(2, *(p->stu_next));
	return true;
}

student *Student::createByStdin(int model, student &tmp)
{
	if (model == 1)
	{
		cout << "ѧ�ţ�";
		cin >> tmp.stu_id;
	}
	if (model == 2)
	{
		cout << "������";
		cin >> tmp.stu_name;
	}
	cout << "���䣺";
	cin >> tmp.stu_age;
	cout << "�Ա�";
	cin >> tmp.stu_sex;
	cout << "���᣺";
	cin >> tmp.stu_birth;
	cout << "ϵ��";
	cin >> tmp.stu_department;
	cout << "רҵ��";
	cin >> tmp.stu_major;
	cout << "�༶��";
	cin >> tmp.stu_class;
	cout << "�ֻ���";
	cin >> tmp.stu_tel;
	cout << "�������䣺";
	cin >> tmp.stu_email;
	return &tmp;
}

//�ļ���������
void Student::saveToFile()
{
	string new_file;
	cout << "������Ҫ������ļ�����";
	cin >> new_file;
	fstream file;
	file.open(new_file.c_str(), ios::out);
	if (file.bad())
	{
		cout << "�ļ���ʧ�ܣ�" << endl;
		return;
	}
	int len = headCount();
	file << len << endl;
	student *pHead = head->stu_next;
	while (pHead != nullptr)
	{
		file << pHead->stu_id << endl;
		file << pHead->stu_name << endl;
		file << pHead->stu_sex << endl;
		file << pHead->stu_age << endl;
		file << pHead->stu_birth << endl;
		file << pHead->stu_department << endl;
		file << pHead->stu_major << endl;
		file << pHead->stu_class << endl;
		file << pHead->stu_email << endl;
		file << pHead->stu_tel << endl;
		pHead = pHead->stu_next;
	}
	file.close();
	cout << "����ɹ���" << endl;
	filename = new_file;
	return;
}

void Student::readFile()
{
	string new_file;
	cout << "������Ҫ��ȡ���ļ�����";
	cin >> new_file;
	fstream file;
	file.open(new_file.c_str(), ios::in);
	if (file.bad())
	{
		cout << "�ļ���ʧ�ܣ�" << endl;
		return;
	}
	int len = 0;
	file >> len;
	while (!len)
	{
		cout << "�ļ������쳣��" << endl;
		return;
	}
	student pHead;
	file.get();
	while (len--)
	{
		file >> pHead.stu_id;
		file >> pHead.stu_name;
		file >> pHead.stu_sex;
		file >> pHead.stu_age;
		file >> pHead.stu_birth;
		file >> pHead.stu_department;
		file >> pHead.stu_major;
		file >> pHead.stu_class;
		file >> pHead.stu_email;
		file >> pHead.stu_tel;
		insert(pHead);
	}
	file.close();
	cout << "�ļ�����ɹ���" << endl;
	filename = new_file;
	return;
}

bool Student::insert(const student &astu)
{
	student *newnode = nullptr;
	student *p = head;
	if (p->stu_next == nullptr) //��û����һ���ѣ����½�һ�������洢����
	{
		p->stu_next = new student(astu); //�ô�������޸Ľṹ��ʼ��
		p->stu_next->stu_next = nullptr; //nullptr��������һ����
		return true;
	}
	while (p->stu_next) //��������һ����
	{
		if (p->stu_next->stu_id == astu.stu_id) //����
		{
			cout << "ѧ���ظ�������ʧ�ܣ�" << endl;
			return false;
		}
		if (p->stu_next->stu_id > astu.stu_id) //�����һ���ѵ�id���ڴ����id
		{
			newnode = new student(astu); //newnodeָ���ʼ�޸Ľṹ
			newnode->stu_next = p->stu_next;
			p->stu_next = newnode;
			return true;
		}
		p = p->stu_next;
	}
	p->stu_next = new student(astu);
	p->stu_next->stu_next = nullptr;
	return true;
}

//��ʾ����
void Student::Show() const
{
	student *p = nullptr;
	cout << "--------------------------------------------" << endl;
	for (p = head->stu_next; p; p = p->stu_next)
	{
		show(p);
	}
	cout << "--------------------------------------------" << endl;
}

void show(student *p)
{
	cout << "  ѧ�ţ�" << p->stu_id << "  ������ " << p->stu_name << "  ���䣺 " << p->stu_age << "  �Ա� ";
	cout << p->stu_sex << "  ���᣺ " << p->stu_birth << "  ϵ�� " << p->stu_department << endl;
	cout << "  רҵ�� " << p->stu_major << "  �༶�� " << p->stu_class << "  �ֻ��� " << p->stu_tel << "  Email�� " << p->stu_email << endl;
}

//�ṹ�������㺯��
unsigned Student::headCount() const
{
	unsigned cnt = 0;
	student *p;
	for (p = head->stu_next; p; p = p->stu_next, ++cnt)
		;
	return cnt;
}