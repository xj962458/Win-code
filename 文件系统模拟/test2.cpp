#include <iostream>
#include <cstring>
#include <windows.h>
using namespace std;
typedef struct node
{
    string filename;
    int isdir;
    int isopen;
    string content;
    struct node *parent, *child, *prev, *next;
} fnode;

class Fnode
{
public:
    void CreateRoot();
    bool Run();
    bool Mkdir();
    bool Create();
    bool Read();
    bool Write();
    bool Del();
    bool Cd();
    bool Dir();
    void Help();

private:
    fnode *root, *recent, *temp, *ttemp;
    string para, command, temppara, recentpara;
    fnode *Initfile(string filename, int isdir);
    bool FindPara(string topara);
};

// �����ļ���Ŀ¼���
fnode *Fnode::Initfile(string filename, int isdir)
{
    fnode *node = new fnode;
    node->filename = filename;
    node->isdir = isdir;
    node->isopen = 0;
    node->parent = NULL;
    node->child = NULL;
    node->prev = NULL;
    node->next = NULL;
    return node;
}

bool Fnode::FindPara(string topara)
{
    int i = 0;
    int sign = 1;
    if (topara == "/")
    {
        recent = root;
        para = "/";
        return 1;
    }
    temp = recent;
    temppara = para;
    if (topara[0] == '/')
    {
        recent = root->child;
        i++;
        para = "/";
    }
    else
    {
        if (recent != NULL && recent != root)
            para += "/";
        if (recent && recent->child)
        {
            if (recent->isdir)
                recent = recent->child;
            else
            {
                cout << " ·������ \n";
                return 1;
            }
        }
    }
    while (i <= signed(topara.length()) && recent)
    {
        int j = 0;
        if (topara[i] == '/' && recent->child)
        {
            i++;
            if (recent->isdir)
                recent = recent->child;
            else
            {
                cout << " ·������\n";
                return 0;
            }
            para += "/";
        }
        while (topara[i] != '/' && i <= signed(topara.length()))
        {
            recentpara[j] = topara[i];
            i++;
            j++;
        }
        recentpara[j] = '\0';
        while ((recent->filename != recentpara || (recent->isdir != 1)) && (recent->next != NULL))
        {
            recent = recent->next;
        }
        if (recent->filename == recentpara)
        {
            if (recent->isdir == 0)
            {
                para = temppara;
                recent = temp;
                cout << " ���ļ�����Ŀ¼��\n";
                return 0;
            }
            para += recent->filename;
        }
        if (recent->filename!= recentpara || recent == NULL)
        {
            para = temppara;
            recent = temp;
            cout << " ����·������\n";
            return 0;
        }
    }
    return 1;
}

// �������ڵ�
void Fnode::CreateRoot()
{
    recent = root = Initfile("/", 1);
    root->parent = NULL;
    root->child = NULL;
    root->prev = root->next = NULL;
    para = "/";
}

// ����Ŀ¼
bool Fnode::Mkdir()
{
    temp = Initfile(" ", 1);
    cin >> temp->filename;
    if (recent->child == NULL)
    {
        temp->parent = recent;
        temp->child = NULL;
        recent->child = temp;
        temp->prev = temp->next = NULL;
        cout << "Ŀ¼�����ɹ�"<<endl;
    }
    else
    {
        ttemp = recent->child;
        while (ttemp->next)
        {
            ttemp = ttemp->next;
            if (ttemp->filename == temp->filename && ttemp->isdir == 1)
            {
                cout << " �Բ���, Ŀ¼�Ѵ���!";
                return 1;
            }
        }
        ttemp->next = temp;
        temp->parent = NULL;
        temp->child = NULL;
        temp->prev = ttemp;
        temp->next = NULL;
    }
    return 1;
}

// �����ļ�
bool Fnode::Create()
{
    temp = Initfile(" ", 0);
    cin >> temp->filename;
    cin >> temp->content;
    if (recent->child == NULL)
    {
        temp->parent = recent;
        temp->child = NULL;
        recent->child = temp;
        temp->prev = temp->next = NULL;
        cout << " �ļ������ɹ�!" << endl;
    }
    else
    {
        ttemp = recent->child;
        while (ttemp->next)
        {
            ttemp = ttemp->next;
            if (ttemp->filename == temp->filename && ttemp->isdir == 0)
            {
                cout << " �Բ���, �ļ��Ѵ���!";
                return 1;
            }
        }
        ttemp->next = temp;
        temp->parent = NULL;
        temp->child = NULL;
        temp->prev = ttemp;
        temp->next = NULL;
        cout << " �ļ������ɹ�!" << endl;
    }
    return 1;
}

//��ʾĿ¼���ļ�
bool Fnode::Dir()
{
    int i = 0, j = 0;
    temp = new fnode;
    temp = recent;
    if (temp != root)
    {
        cout << " <Ŀ¼> "
             << ".." << endl;
        i++;
    }
    if (temp->child == NULL)
    {
        cout << "�ܼ�: "
             << " Ŀ¼:" << i << "\t�ļ�:" << j << endl;
        return 1;
    }
    temp = temp->child;
    while (temp)
    {
        if (temp->isdir)
        {
            cout << " <Ŀ¼> " << temp->filename << endl;
            i++;
        }
        else
        {
            cout << " <�ļ�> " << temp->filename << endl;
            j++;
        }
        temp = temp->next;
    }
    cout << "�ܼ�: "
         << " Ŀ¼:" << i << "\t�ļ�:" << j << endl;
    return 1;
}

// ��ȡ�ļ�����
bool Fnode::Read()
{
    string filename;
    cin >> filename;
    if (recent->child == NULL)
    {
        cout << " �ļ�������!" << endl;
        return 1;
    }
    if (recent->child->filename == filename)
    {
        cout << recent->child->content << endl;
        return 1;
    }
    else
    {
        temp = recent->child;
        while (temp->next)
        {
            if (temp->next->filename == filename)
            {
                cout << temp->next->content << endl;
                return 1;
            }
        }
        cout << " �ļ�������!" << endl;
    }
    return 1;
}

// ���ļ���д������
bool Fnode::Write()
{
    string filename;
    cin >> filename;
    if (recent->child == NULL)
    {
        cout << " �ļ������� !" << endl;
        return 1;
    }
    if (recent->child->filename == filename)
    {
        recent->child->isopen = 1; // �����ļ����Ϊ��
        cin >> recent->child->content;
        recent->child->isopen = 0; // �����ļ����Ϊ�ر�
        cout << " �ļ�д��ɹ� !" << endl;
        return 1;
    }
    else
    {
        temp = recent->child;
        while (temp->next)
        {
            if (temp->next->filename == filename)
            {
                recent->child->isopen = 1; // �����ļ����Ϊ��
                cin >> temp->next->content;
                recent->child->isopen = 0; // �����ļ����Ϊ�ر�
                cout << " �ļ�д��ɹ� !" << endl;
                return 1;
            }
        }
        cout << " �ļ������� !" << endl;
    }
    return 1;
}

// �л�Ŀ¼
bool Fnode::Cd()
{
    string topara;
    cin >> topara;
    if (topara == "..")
    {
        int i;
        while (recent->prev)
            recent = recent->prev;
        if (recent->parent)
        {
            recent = recent->parent;
        }
        i = para.length();
        while (para[i] != '/' && i > 0)
            i--;
        if (i != 0)
            para[i] = '\0';
        else
            para[i + 1] = '\0';
    }
    else
    {
        FindPara(topara);
    }
    return 1;
}

//ɾ�����
bool Fnode::Del()
{
    string filename;
    cin >> filename;
    temp = new fnode;
    if (recent->child)
    {
        temp = recent->child;
        while (temp->next && (temp->filename != filename || temp->isdir != 0))
            temp = temp->next;
        if (temp->filename != filename)
        {
            cout << " �����ڸ��ļ��� " << endl;
            return 0;
        }
    }
    else
    {
        cout << " �����ڸ��ļ��� " << endl;
        return 0;
    }
    if (temp->parent == NULL)
    {
        temp->prev->next = temp->next;
        if (temp->next)
            temp->next->prev = temp->prev;
        temp->prev = temp->next = NULL;
    }
    else
    {
        if (temp->next)
            temp->next->parent = temp->parent;
        temp->parent->child = temp->next;
    }
    delete temp;
    cout << " �ļ���ɾ��!" << endl;
    return 1;
}

// ���к���
bool Fnode::Run()
{
    cout << "root" << para << ">";
    cin >> command;
    if (command == "mkdir")
        Mkdir();
    else if (command == "dir")
        Dir();
    else if (command == "cd")
        Cd();
    else if (command == "create")
        Create();
    else if (command == "read")
        Read();
    else if (command == "write")
        Write();
    else if (command == "del")
        Del();
    else if (command == "help")
        Help();
    else if (command == "exit")
        return 0;
    else
        cout << " ��ο�help �ṩ�������б�!" << endl;
    return 1;
}

// ��������
void Fnode::Help()
{
    cout << "\t\t\t=====================��������һ��====================\n";
    cout << "\t\t\t*                                                   *\n";
    cout << "\t\t\t*          1>. create: �����ļ�                     *\n";
    cout << "\t\t\t*          2>. read: ��ȡ�ļ�                       *\n";
    cout << "\t\t\t*          3>. write: д���ļ�                      *\n";
    cout << "\t\t\t*          4>. del : ɾ���ļ�                       *\n";
    cout << "\t\t\t*          5>. mkdir: ����Ŀ¼                      *\n";
    cout << "\t\t\t*          6>. cd: �л�Ŀ¼                         *\n";
    cout << "\t\t\t*          7>. exit: �˳���¼                       *\n";
    cout << "\t\t\t*                                    ��ӭʹ�ñ�ϵͳ!*\n";
    cout << "\t\t\t=====================================================\n";
}

// ������
int main()
{
    int i = 0;
    bool in = false;
    string users, pwd;
    Fnode f;
    cout << "\t\t\t=====================�ļ�ϵͳģ��====================\n";
    cout << "\t\t\t*                                                   *\n";
    cout << "\t\t\t*         1>. ��ֻ�����λ����������˺�              *\n";
    cout << "\t\t\t*         2>. ����help ���Ի�ȡ����                 *\n";
    cout << "\t\t\t*                                    ��ӭʹ�ñ�ϵͳ!*\n";
    cout << "\t\t\t=====================================================\n"
         << endl;
    while (i < 3)
    {
        cout << "�������û���:";
        cin >> users;
        cout << "����������:";
        cin >> pwd;
        if ((users == "root") && (pwd == "root"))
        {
            in = true;
            break;
        }
        else
        {
            cout << "�˺Ż����벻��ȷ,����������!" << endl;
        }
        i++;
    }
    f.CreateRoot();
    while (in)
    {
        if (!f.Run())
            break;
    }
    return 0;
}
