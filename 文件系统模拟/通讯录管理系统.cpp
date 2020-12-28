#include <iostream>
#include <string>
#include <cstring>
#include <fstream>
using namespace std;

//�Զ���һ����ϵ�˽������
typedef struct node1
{
    string name;        //����
    string tel;         //�ֻ���
    string email;       //����
    string address;     //��ַ
    struct node1 *next; //ָ����һ�ڵ��ָ��
} Node;

//�Զ���һ�������������������
typedef struct node2
{
    Node data;
    struct node2 *lchild, *rchild;
} BSTNode;

//������ͨѶ¼��
class Fnode
{
public:
    Fnode();                                //���캯�������ڳ�ʼ��һЩ����
    ~Fnode();                               //�������������ڳ������֮��Է�����ڴ��������
    void CreateInfo();                      //¼����ϵ����Ϣ
    void InsertInfo();                      //������ϵ����Ϣ
    void FindInfoName();                    //������������ϵ����Ϣ
    void FindInfoTel();                     //���ֻ��Ų�����ϵ����Ϣ
    void DeleteInfoTel();                   //���ֻ���ɾ����ϵ����Ϣ
    void DispInfo();                        //��ӡ������ϵ����Ϣ
    void DispInfoSort();                    //���������������ϵ����Ϣ
    void SaveInfoToFile();                  //������ϵ����Ϣ���ļ�
    void ReadInfoFromFile();                //���ļ���ȡ��ϵ����Ϣ
    void Run();                             //���ܺ����������˵�����غ��������
    bool InsertBST(BSTNode *&bt, Node key); //����������������,�ݹ�ʵ��
    void CreateBST();                       //������������������
    void InOrder(BSTNode *b);               //�����������������������ݹ�ʵ��
    void DestroyBST(BSTNode *&b);           //�ͷŶ���������,�ݹ�ʵ��

private:
    bool opened;     //���ڱ����ļ��Ƿ񱻶�ȡ����δ��Ϊ0,�Ѷ�Ϊ1
    Node *L, *p, *q; //����ͨѶ¼����ͷָ���������Ա�����п����õ���ָ��
    BSTNode *btree;  //����������ͷ�ڵ�
};

//���캯�������ڳ�ʼ��һЩ����
Fnode::Fnode()
{
    L = new Node;
    L->next = NULL;
    p = q = NULL;
    btree = NULL;
    opened = 0;
}

//�������������ڳ������֮��Է�����ڴ��������
Fnode::~Fnode()
{
    p = L;
    while (p != NULL)
    {
        delete p;
        p = p->next;
    }
}

void Fnode::CreateInfo() //�������
{
    int n;
    q = L, p = NULL;
    while (q->next != NULL)
        q = q->next;
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

//������ϵ����Ϣ
void Fnode::InsertInfo()
{
    q = L, p = NULL;
    while (q->next != NULL)
        q = q->next;
    p = new Node;
    cout << "��������Ҫ�������ϵ�˵��������ֻ��š�����͵�ַ(�ÿո����):" << endl;
    cin >> p->name >> p->tel >> p->email >> p->address;
    p->next = q->next;
    q->next = p;
    cout << "����ɹ�!" << endl;
}

//��ӡ������ϵ����Ϣ
void Fnode::DispInfo()
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

//������������ϵ����Ϣ
void Fnode::FindInfoName()
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

//���ֻ��Ų�����ϵ����Ϣ
void Fnode::FindInfoTel()
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

//���ֻ���ɾ����ϵ����Ϣ
void Fnode::DeleteInfoTel()
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

//���������������ϵ����Ϣ
void Fnode::DispInfoSort()
{
    CreateBST();
    cout << "����  \t\t"
         << "�ֻ���       \t\t"
         << "����             \t\t"
         << "��ַ" << endl;
    InOrder(btree);
    DestroyBST(btree);
}

//������ϵ����Ϣ���ļ�
void Fnode::SaveInfoToFile()
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
        while (p->next != NULL)
        {
            outfile << p->name << "," << p->tel << "," << p->email << "," << p->address << endl;
            p = p->next;
        }
        outfile << p->name << "," << p->tel << "," << p->email << "," << p->address;
        outfile.close();
        cout << "������ϵ����Ϣ�ɹ�����鿴��ǰĿ¼�µġ���ϵ��.csv�ļ���" << endl;
    }
}

//���ļ���ȡ��ϵ����Ϣ
void Fnode::ReadInfoFromFile()
{
    ifstream infile("./��ϵ��.csv");
    if (!infile)
    {
        cout << "�޷����ļ�!";
        return;
    }
    else if (opened == 1)
    {
        cout << "�ļ��Ѿ�����ȡ�����ܹ��ظ���ȡ!" << endl;
        return;
    }
    else
    {
        char str[500];
        q = L, p = NULL;
        while (q->next != NULL)
            q = q->next;
        infile.getline(str, sizeof(str));
        while (!infile.eof())
        {
            p = new Node;
            infile.getline(str, sizeof(str));
            p->name = strtok(str, ",");
            p->tel = strtok(NULL, ",");
            p->email = strtok(NULL, ",");
            p->address = strtok(NULL, ",");
            p->next = q->next;
            q->next = p;
            q = p;
        }
        infile.close();
        cout << "��ȡ���ݳɹ���" << endl;
        opened = 1;
    }
}

//����������������
bool Fnode::InsertBST(BSTNode *&bt, Node key)
{
    if (bt == NULL)
    {
        bt = new BSTNode;
        bt->data = key;
        bt->lchild = bt->rchild = NULL;
        return true;
    }
    else if (key.name == bt->data.name)
        return false;
    else if (key.name < bt->data.name)
        return InsertBST(bt->lchild, key);
    else
        return InsertBST(bt->rchild, key);
}

//������������������
void Fnode::CreateBST()
{
    btree = NULL;
    p = L->next;
    while (p != NULL)
    {
        InsertBST(btree, *p);
        p = p->next;
    }
}

//��������������������
void Fnode::InOrder(BSTNode *b)
{
    if (b != NULL)
    {
        InOrder(b->lchild);
        cout << b->data.name << "\t\t" << b->data.tel << "\t\t" << b->data.email << "\t\t" << b->data.address << endl;
        InOrder(b->rchild);
    }
}

//�ͷŶ���������
void Fnode::DestroyBST(BSTNode *&b)
{
    if (b != NULL)
    {
        DestroyBST(b->lchild);
        DestroyBST(b->rchild);
        delete b;
    }
}

//�˵�
void Fnode::Run()
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

//������
int main()
{
    Fnode f;
    system("cls");
    f.Run();
    return 0;
}