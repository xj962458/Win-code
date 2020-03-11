#include <iostream>
#include "student.h"
#include "user.h"

using namespace std;

void menu()
{
	cout << "+-----------------------------------------------+\n";
	cout << "|              ѧ��ѧ����Ϣ����ϵͳ             |\n";
	cout << "+-----------------------------------------------+\n";
	cout << "|   1��ע���¹���Ա�˺�  |  6�������ѧ����Ϣ   |\n";
	cout << "|   2���鿴����Ա�˺�    |  7���޸�ѧ����Ϣ     |\n";
	cout << "|   3��ɾ������Ա�˺�    |  8����ʾѧ����Ϣ     |\n";
	cout << "|   4����ȡѧ����Ϣ      |  9����ѯѧ����Ϣ     |\n";
	cout << "|   5������ѧ����Ϣ      | 10��ɾ��ѧ����Ϣ     |\n";
	cout << "+-----------------------------------------------+\n";
	cout << "|                     0���˳�                   |\n";
	cout << "+-----------------------------------------------+\n";
}
int main(int argc, char* argv[])
{
	User u1;
	u1.readFile();
	if (u1.logon())
	{
		Student m_stu;
		int choice;
		char str[20];
		menu();
		do
		{
			cout << "������ָ�";
			cin >> choice;
			while (!cin)  //�ж�cin������Ƿ����������������ȷ���ͣ�cin = 0
			{
				cin.clear();  //���cin��
				cin >> str;   //��ֵ�������뵽str����
				cout << "��������ȷ��ָ�" << endl;
				cin >> choice;
			}
			switch (choice)
			{
			case 1:
				u1.login();
				break;
			case 2:
				u1.show();
				break;
			case 3:
				u1.deleteByName();
			case 4:
				m_stu.readFile();
				break;
			case 5:
				m_stu.saveToFile();
				break;
			case 6:
				m_stu.logon();
				break;
			case 7:
				m_stu.modify();
				break;
			case 8:
				m_stu.Show();
				break;
			case 9:
				m_stu.Query();
				break;
			case 10:
				m_stu.deleteBy();
				break;
			case 0:
				break;
			default:
				cout << "��������ȷ��ѡ��!" << endl;
				menu();
				break;
			}
		} while (choice);
	}
	return 0;
}