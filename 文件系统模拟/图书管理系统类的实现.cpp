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

class Fnode
{
public:
    Fnode();           //���캯��,������ʼ��Ա����
    ~Fnode();          //��������,�ڳ�����������������ڴ�
    void CreateNode(); //����ͼ����Ϣ
    void Del();        //ɾ��ͼ������Ϣ
    void Insert();     //����ͼ����Ϣ
    void FindTime();   //������������ͼ����Ĵ���
    void ChangeTime(); //�޸�ͼ����Ĵ���
    void FindMost();   //�ҳ�������С�Ľ��Ĵ���
    void Menu();       //�˵�
private:
    int max, min;            //������С���Ĵ���
    Node *L, *p, *q;         //Node���͵�ָ�룬ͷ�ڵ�ָ��L�����������п����õ���ָ��p,q
    string maxname, minname; //�洢������С���Ĵ���������
};

//��������,������ʼ��Ա����
Fnode::Fnode()
{
    L->next == NULL;
    p = q = NULL;
}

//��������,�ڳ�����������������ڴ�
Fnode::~Fnode()
{
    p = L;
    while (p != NULL)
    {
        delete p;
    }
}
// ¼��ͼ����Ϣ��β�巨������
void Fnode::CreateNode()
{
    int n;
    L = new Node;
    L->next = NULL;
    q = L;
    cout << "��������Ҫ�����ͼ�鱾��:";
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        p = new Node;
        p->next = q->next;
        q->next = p;
        cout << "�������" << i + 1 << "��ͼ��ı�š����ơ����ߡ�������ͽ��Ĵ���(�ÿո����):\n";
        cin >> p->no >> p->bookname >> p->author >> p->publishers >> p->time;
        q = p;
    }
}

// ɾ��ͼ����Ϣ
void Fnode::Del()
{
    p = L->next, q = L;
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
void Fnode::Insert()
{
    p, q = L->next;
    while (q->next != NULL)
        q = q->next;
    p = new Node;
    p->next = q->next;
    q->next = p;
    cout << "������ͼ��ı�š����ơ����ߡ�������ͽ��Ĵ���(�ÿո����):" << endl;
    cin >> p->no >> p->bookname >> p->author >> p->publishers >> p->time;
    cout << "����ɹ�!\n";
}

// ����ͼ����Ĵ����������������ң�
void Fnode::FindTime()
{
    p = L->next;
    string name;
    if (p == NULL)
    {
        cout << "����Ϊ�գ��޷����ҡ�\n";
        return;
    }
    cout << "��������Ҫ���ҵ�ͼ������:";
    cin >> name;
    while (p->bookname != name)
    {
        p = p->next;
        if (p == NULL)
        {
            cout << "û���ҵ������Ϣ" << endl;
            return;
        }
    }
    cout << "ͼ�顶" << p->bookname << "���Ľ��Ĵ���Ϊ" << p->time << endl;
}

// �޸�ͼ����Ĵ������������������޸�)
void Fnode::ChangeTime()
{
    p = L->next;
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
void Fnode::FindMost()
{
    p = L->next;
    maxname = p->bookname;
    minname = p->bookname;
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
void Fnode::Menu()
{
    int item;
    do
    {
        cout << "\t\t\t===================================================" << endl;
        cout << "\t\t\t#             *|ͼ����Ĺ���ϵͳ|*                #" << endl;
        cout << "\t\t\t#\t1).¼��ĳ��ͼ�������Ϣ��                 #" << endl;
        cout << "\t\t\t#\t2).ɾ��ĳ��ͼ��������Ϣ��               #" << endl;
        cout << "\t\t\t#\t3).����ĳ��ͼ��������Ϣ��               #" << endl;
        cout << "\t\t\t#\t4).����ĳ��ͼ��Ľ��Ĵ�����               #" << endl;
        cout << "\t\t\t#\t5).�޸�ĳ��ͼ��Ľ��Ĵ�����               #" << endl;
        cout << "\t\t\t#\t6).���ҽ��Ĵ����������ٵ�ͼ��ǡ�       #" << endl;
        cout << "\t\t\t#\t0).�˳�ͼ�����ϵͳ!                      #" << endl;
        cout << "\t\t\t===================================================" << endl;
        cout << "��������Ӧ�ı�ţ�ִ����Ӧ�Ĳ���:";
        cin >> item;
        system("cls");
        switch (item)
        {
        case 1:
            CreateNode();
            getchar();
            cout << "\n�밴������������˵�" << endl;
            getchar();
            system("cls");
            break;
        case 2:
            Del();
            getchar();
            cout << "\n�밴������������˵�" << endl;
            getchar();
            system("cls");
            break;
        case 3:
            Insert();
            getchar();
            cout << "\n�밴������������˵�" << endl;
            getchar();
            system("cls");
            break;
        case 4:
            FindTime();
            getchar();
            cout << "\n�밴������������˵�" << endl;
            getchar();
            system("cls");
            break;
        case 5:
            ChangeTime();
            getchar();
            cout << "\n�밴������������˵�" << endl;
            getchar();
            system("cls");
            break;
        case 6:
            FindMost();
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
    Fnode f;
    f.Menu();
    return 0;
}
