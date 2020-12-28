#include <iostream>
#include <string>
#include <fstream>
#include <windows.h>
using namespace std;
typedef struct node
{
    string name;       //����
    string tel;        //�ֻ���
    string email;      //����
    string address;    //��ַ
    struct node *next; //ָ����һ�ڵ��ָ��
} Node;

class Fnode
{
public:
    ~Fnode();                //�������������ڳ������֮��Է�����ڴ��������
    void CreateInfo();       //¼����ϵ����Ϣ
    void InsertInfo();       //������ϵ����Ϣ
    void FindInfoName();     //������������ϵ����Ϣ
    void FindInfoTel();      //���ֻ��Ų�����ϵ����Ϣ
    void DeleteInfoTel();    //���ֻ���ɾ����ϵ����Ϣ
    void DispInfo();         //��ӡ������ϵ����Ϣ
    void DispInfoSort();     //���������������ϵ����Ϣ
    void SaveInfoToFile();   //������ϵ����Ϣ���ļ�
    void ReadInfoFromFile(); //���ļ���ȡ��ϵ����Ϣ
    void Menu();             //�˵�
private:
    Node *L, *p, *q;
};

Fnode::~Fnode() //�������������ڳ������֮��Է�����ڴ��������
{
    p = L->next;
    while (p != NULL)
    {
        delete p;
        p = p->next;
    }
    delete L;
}

void Fnode::CreateInfo() //�������
{
    int n;
    L = new Node, q = L;
    cout << "��������Ҫ¼�����ϵ�˸���:";
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        p = new Node;
        cout << "�������" << i + 1 << "λ��ϵ�˵��������ֻ��š�����͵�ַ(�ÿո����):" << endl;
        cin >> p->name >> p->tel >> p->email >> p->address;
        p->next = q->next;
        q->next = p;
        q = p;
    }
}

void Fnode::InsertInfo()
{
    q = L->next;
    while (q->next != NULL)
        q = q->next;
    p = new Node;
    cout << "��������Ҫ�������ϵ�˵��������ֻ��š�����͵�ַ(�ÿո����):" << endl;
    cin >> p->name >> p->tel >> p->email >> p->address;
    p->next = q->next;
    q->next = p;
    cout << "����ɹ�!" << endl;
}

void Fnode::DispInfo() //��ӡ������ϵ����Ϣ
{
    p = L->next;
    if (p == NULL)
        cout << "����Ϊ�գ��޷���ӡ" << endl;
    else
    {
        cout << "����  \t\t"
             << "�ֻ���       \t\t"
             << "����             \t\t"
             << "��ַ" << endl;
        while (p != NULL)
        {
            cout << p->name << "\t\t" << p->tel << "\t\t" << p->email << "\t\t" << p->address << endl;
            p = p->next;
        }
    }
}

void Fnode::FindInfoName() //������������ϵ����Ϣ
{
    string name;
    p = L->next;
    if (p == NULL)
        cout << "����Ϊ�գ��޷�����" << endl;
    else
    {
        cout << "������Ҫ���ҵ���ϵ�˵�����:";
        cin >> name;
        while (p->name != name)
        {
            p = p->next;
            if (p == NULL)
            {
                cout << "û���ҵ������ϵ����Ϣ" << endl;
                return;
            }
        }
        cout << "����ϵ�˵���Ϣ����" << endl;
        cout << "����  \t\t"
             << "�ֻ���       \t\t"
             << "����             \t\t"
             << "��ַ" << endl;
        cout << p->name << "\t\t" << p->tel << "\t\t" << p->email << "\t\t" << p->address << endl;
    }
}

void Fnode::FindInfoTel() //���ֻ��Ų�����ϵ����Ϣ
{
    string tel;
    p = L->next;
    if (p == NULL)
        cout << "����Ϊ�գ��޷�����" << endl;
    else
    {
        cout << "������Ҫ���ҵ���ϵ�˵��ֻ���:";
        cin >> tel;
        while (p->tel != tel)
        {
            p = p->next;
            if (p == NULL)
            {
                cout << "û���ҵ������Ϣ" << endl;
                return;
            }
        }
        cout << "����ϵ�˵���Ϣ����" << endl;
        cout << "����  \t\t"
             << "�ֻ���       \t\t"
             << "����             \t\t"
             << "��ַ" << endl;
        cout << p->name << "\t\t" << p->tel << "\t\t" << p->email << "\t\t" << p->address << endl;
    }
}

void Fnode::DeleteInfoTel() //���ֻ���ɾ����ϵ����Ϣ
{
    string tel;
    p = L->next, q = L;
    if (p == NULL)
        cout << "����Ϊ�գ��޷�ɾ��" << endl;
    else
    {
        cout << "������Ҫɾ������ϵ�˵��ֻ���" << endl;
        cin >> tel;
        while (p->tel != tel)
        {
            p = p->next;
            q = q->next;
            if (p == NULL)
            {
                cout << "û���ҵ������Ϣ" << endl;
                return;
            }
        }
        q->next = p->next;
        delete p;
        cout << "�ֻ���Ϊ" << tel << "����ϵ��ɾ���ɹ�!" << endl;
    }
}
void Fnode::DispInfoSort() //���������������ϵ����Ϣ
{
}
void Fnode::SaveInfoToFile() //������ϵ����Ϣ���ļ�
{
    p = L->next;
    if (p == NULL)
        cout << "����Ϊ�գ��޷�д��!" << endl;
    else
    {
        ofstream outfile("./��ϵ��.csv");
        if (!outfile)
        {
            cout << "�޷����ļ�!";
            return;
        }
        outfile << "����,"
                << "�ֻ���,"
                << "����,"
                << "��ַ" << endl;
        while (p != NULL)
        {
            outfile << p->name << "," << p->tel << "," << p->email << "," << p->address << endl;
            p = p->next;
        }
        outfile.close();
        cout << "������ϵ����Ϣ�ɹ�����鿴��ǰĿ¼�µġ���ϵ��.csv�ļ���" << endl;
    }
}

void Fnode::ReadInfoFromFile() //���ļ���ȡ��ϵ����Ϣ
{
    char str[100];
    q = L->next;
    while (q->next != NULL)
        q = q->next;
    ifstream infile("./��ϵ��1.csv");
    if (!infile)
    {
        cout << "�޷����ļ�!";
        return;
    }
    while (!infile.eof())
    {
        p = new Node;
        infile.getline(str, sizeof(str));
        cout << strtok(str, ",") << " " << strtok(NULL, ",") << " " << strtok(NULL, ",") << " " << strtok(NULL, ",");
        p->name = strtok(str, ",");
        p->tel = strtok(NULL, ",");
        p->email = strtok(NULL, ",");
        p->address = strtok(NULL, ",");
        p->next = q->next;
        q->next = p;
        q = p;
    }
    infile.close();
}

void Fnode::Menu() //�˵�
{
    int item;
    do
    {
        cout << "\t\t\t==================ͨѶ¼����ϵͳ==================" << endl;
        cout << "\t\t\t# \t                                         #" << endl;
        cout << "\t\t\t# \t1)��ϵ����Ϣ������¼�롣                 #" << endl;
        cout << "\t\t\t# \t2)����ĳ����ϵ�˵���Ϣ��                 #" << endl;
        cout << "\t\t\t# \t3)���ֻ��Ų���ĳ����ϵ�˵��š�           #" << endl;
        cout << "\t\t\t# \t4)��������ѯĳ����ϵ�ˡ�                 #" << endl;
        cout << "\t\t\t# \t5)���ֻ���ɾ��ĳ����ϵ�˵���Ϣ           #" << endl;
        cout << "\t\t\t# \t6)������ϵ����Ϣ�������ʾ��             #" << endl;
        cout << "\t\t\t# \t7)������ϵ�˰��������������ʾ��       #" << endl;
        cout << "\t\t\t# \t8)������ϵ����Ϣ���ļ����档             #" << endl;
        cout << "\t\t\t# \t9)������ϵ����Ϣ���ļ���ȡ��             #" << endl;
        cout << "\t\t\t# \t0)�˳�����ϵͳ��                         #" << endl;
        cout << "\t\t\t==================================================" << endl;
        cout << "��������Ӧ�����ִ����Ӧ�Ĺ���:";
        cin >> item;
        system("cls");
        switch (item)
        {
        case 1:
            CreateInfo();
            getchar();
            cout << "\n��������������˵�" << endl;
            getchar();
            system("cls");
            break;
        case 2:
            InsertInfo();
            getchar();
            cout << "\n��������������˵�" << endl;
            getchar();
            system("cls");
            break;
        case 3:
            FindInfoTel();
            getchar();
            cout << "\n��������������˵�" << endl;
            getchar();
            system("cls");
            break;
        case 4:
            FindInfoName();
            getchar();
            cout << "\n��������������˵�" << endl;
            getchar();
            system("cls");
            break;
        case 5:
            DeleteInfoTel();
            getchar();
            cout << "\n��������������˵�" << endl;
            getchar();
            system("cls");
            break;
        case 6:
            DispInfo();
            getchar();
            cout << "\n��������������˵�" << endl;
            getchar();
            system("cls");
            break;
        case 7:
            DispInfoSort();
            getchar();
            cout << "\n��������������˵�" << endl;
            getchar();
            system("cls");
            break;
        case 8:
            SaveInfoToFile();
            getchar();
            cout << "\n��������������˵�" << endl;
            getchar();
            system("cls");
            break;
        case 9:
            ReadInfoFromFile();
            getchar();
            cout << "\n��������������˵�" << endl;
            getchar();
            system("cls");
            break;
        case 0:
            cout << "�����˳�ͨѶ¼����ϵͳ......" << endl;
            cout << "лл����ʹ��!";
            exit(0);
            break;
        default:
            cout << "�������ָ���������������!" << endl;
            getchar();
            cout << "\n��������������˵�" << endl;
            getchar();
            system("cls");
        }
    } while (item);
}

int main()
{
    Fnode f;
    system("cls");
    f.Menu();
    return 0;
}