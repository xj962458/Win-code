#include <iostream>
#include <string>
#include <windows.h>
using namespace std;

// ����ͼ����Ϣ���
typedef struct node
{
    string no;         //���
    string bookname;   //����
    string author;     //����
    string publishers; //������
    int time;          //�����Ĵ���
    struct node *next; //ָ����һ�ڵ��ָ��
} Node;

// ¼��ͼ����Ϣ��β�巨������
void CreateNode(Node *&L)
{
    int n;
    L = new Node;
    L->next = NULL;
    Node *p, *tail = L;
    cout << "��������Ҫ�����ͼ�鱾��:";
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        p = new Node;
        p->next = tail->next;
        tail->next = p;
        cout << "�������" << i + 1 << "��ͼ��ı�š����ơ����ߡ�������ͽ��Ĵ���(�ÿո����):\n";
        cin >> p->no >> p->bookname >> p->author >> p->publishers >> p->time;
        tail = p;
    }
}

// ɾ��ͼ����Ϣ
void Del(Node *&L)
{
    Node *p = L->next, *q = L;
    string name;
    if (p == NULL)
    {
        cout << "����Ϊ�գ��޷�ɾ��";
        return;
    }
    cout << "��������Ҫɾ��������:";
    cin >> name;
    while (p != NULL)
    {
        if (p->bookname == name)
        {
            q->next = p->next;
            delete p;
            cout << "ɾ���ɹ�!" << endl;
            return;
        }
        p = p->next;
        q = q->next;
    }
    if (p == NULL && p->bookname == name)
        cout << "δ�ҵ������Ϣ";
}

// ����ͼ����Ϣ��β�巨���룩
void Insert(Node *&L)
{
    Node *p, *tail = L->next;
    while (tail->next != NULL)
        tail = tail->next;
    p = new Node;
    p->next = tail->next;
    tail->next = p;
    cout << "������ͼ��ı�š����ơ����ߡ�������ͽ��Ĵ���(�ÿո����):\n";
    cin >> p->no >> p->bookname >> p->author >> p->publishers >> p->time;
    cout << "����ɹ�!\n";
}

// ����ͼ����Ĵ����������������ң�
void FindTime(Node *L)
{
    Node *p = L->next;
    string name;
    if (p == NULL)
    {
        cout << "����Ϊ�գ��޷����ҡ�\n";
        return;
    }
    cout << "��������Ҫ���ҵ�ͼ������:";
    cin >> name;
    while (p != NULL)
    {
        if (p->bookname == name)
        {
            cout << "ͼ�顶" << p->bookname << "���Ľ��Ĵ���Ϊ" << p->time << endl;
            return;
        }
        p = p->next;
    }
    if (p == NULL && p->bookname != name)
        cout << "δ�ҵ������Ϣ\n";
}

// �޸�ͼ����Ĵ������������������޸�)
void ChangeTime(Node *L)
{
    Node *p = L->next;
    string name;
    if (p == NULL)
    {
        cout << "����Ϊ�գ��޷����ҡ�\n";
        return;
    }
    cout << "��������Ҫ���ҵ�ͼ������\n";
    cin >> name;
    while (p != NULL)
    {
        if (p->bookname == name)
        {
            cout << p->bookname << "�ĵ�ǰ���Ĵ���Ϊ" << p->time << endl;
            cout << "��������Ҫ�޸ĺ�Ľ��Ĵ���:";
            cin >> p->time;
            cout << "�޸ĳɹ�����ǰͼ�顶" << p->bookname << "���Ľ��Ĵ���Ϊ" << p->time << endl;
            return;
        }
        p = p->next;
    }
    if (p == NULL && p->bookname != name)
        cout << "δ�ҵ������Ϣ\n";
}

// Ѱ��������С��ͼ����Ĵ���
void FindMost(Node *L)
{
    Node *p = L->next;
    int max, min;
    string maxname = p->bookname, minname = p->bookname;
    max = p->time;
    min = p->time;
    while (p != NULL)
    {
        if (p->time > max)
        {
            max = p->time;
            maxname = p->bookname;
        }
        if (p->time < min)
        {
            min = p->time;
            minname = p->bookname;
        }
        p = p->next;
    }
    cout << "���Ĵ�������ͼ���ǡ�" << maxname << "��,���Ĵ���Ϊ:" << max << "��" << endl;
    cout << "���Ĵ������ٵ�ͼ���ǡ�" << minname << "��,���Ĵ���Ϊ:" << min << "��" << endl;
}

// ����˵�
void Menu()
{
    int item;
    Node *L;
    do
    {
        cout << "\t\t    ͼ����Ĺ���ϵͳ               " << endl;
        cout << "\t\t1).¼��ĳ��ͼ�������Ϣ��           " << endl;
        cout << "\t\t2).ɾ��ĳ��ͼ��������Ϣ��         " << endl;
        cout << "\t\t3).����ĳ��ͼ��������Ϣ��         " << endl;
        cout << "\t\t4).����ĳ��ͼ��Ľ��Ĵ�����         " << endl;
        cout << "\t\t5).�޸�ĳ��ͼ��Ľ��Ĵ�����         " << endl;
        cout << "\t\t6).���ҽ��Ĵ����������ٵ�ͼ���¼��" << endl;
        cout << "\t\t0).�˳�ͼ�����ϵͳ!               " << endl;
        cout << "��������Ӧ�ı�ţ�ִ����Ӧ�Ĳ���:       " << endl;

        cin >> item;
        system("cls");
        switch (item)
        {
        case 1:
            CreateNode(L);
            getchar();
            cout << "\n�밴������������˵�" << endl;
            getchar();
            system("cls");
            break;
        case 2:
            Del(L);
            getchar();
            cout << "\n�밴������������˵�" << endl;
            getchar();
            system("cls");
            break;
        case 3:
            Insert(L);
            getchar();
            cout << "\n�밴������������˵�" << endl;
            getchar();
            system("cls");
            break;
        case 4:
            FindTime(L);
            getchar();
            cout << "\n�밴������������˵�" << endl;
            getchar();
            system("cls");
            break;
        case 5:
            ChangeTime(L);
            getchar();
            cout << "\n�밴������������˵�" << endl;
            getchar();
            system("cls");
            break;
        case 6:
            FindMost(L);
            getchar();
            cout << "\n�밴������������˵�" << endl;
            getchar();
            system("cls");
            break;
        case 0:
            cout << "\nлл����ʹ�ã����򼴽��˳�!" << endl;
            exit(0);
            break;
        default:
            cout << "�������ָ���������������\n";
            getchar();
            cout << "�밴������������˵�" << endl;
            getchar();
            system("cls");
            break;
        }
    } while (item);
}

// ������
int main()
{
    Menu();
    return 0;
}
