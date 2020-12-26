#include <iostream>
#include <iomanip>
#include <cstring>
using namespace std;

#define FILENAME_LENGTH 10 // �ļ����Ƴ���
#define COMMAND_LENGTH 10  // �����г���
#define PARA_LENGTH 30     // ��������
// �˺Žṹ
typedef struct users
{
    char name[8];
    char pwd[10];
} users;
// �ļ��ṹ
struct fnode
{
    char filename[FILENAME_LENGTH];
    int isdir;
    int isopen;
    char content[255];
    fnode *parent;
    fnode *child;
    fnode *prev;
    fnode *next;
};
// �˺�
users usrarray[8] =
    {
        "usr1",
        "usr1",
        "usr2",
        "usr2",
        "usr3",
        "usr3",
        "usr4",
        "usr4",
        "usr5",
        "usr5",
        "usr6",
        "usr6",
        "usr7",
        "usr7",
        "usr8",
        "usr8",
};
fnode *initfile(char filename[], int isdir);
void createroot();
int run();
int findpara(char *topara);
bool chklogin(char *users, char *pwd);
void help();
int mkdir();
int create();
int read();
int write();
int del();
int cd();
int dir();
fnode *root, *recent, *temp, *ttemp;
char
    para[PARA_LENGTH],
    command[COMMAND_LENGTH], temppara[PARA_LENGTH], recentpara[PARA_LENGTH];
// �����ļ���Ŀ¼���
fnode *initfile(const char filename[], int isdir)
{
    fnode *node = new fnode;
    strcpy(node->filename, filename);
    node->isdir = isdir;
    node->isopen = 0;
    node->parent = NULL;
    node->child = NULL;
    node->prev = NULL;
    node->next = NULL;
    return node;
}
// �����ļ��洢���
void createroot()
{
    recent = root = initfile("/", 1);
    root->parent = NULL;
    root->child = NULL;
    root->prev = root->next = NULL;
    strcpy(para, "/");
}
int mkdir()
{
    temp = initfile(" ", 1);
    cin >> temp->filename;
    if (recent->child == NULL)
    {
        temp->parent = recent;
        temp->child = NULL;
        recent->child = temp;
        temp->prev = temp->next = NULL;
    }
    else
    {
        ttemp = recent->child;
        while (ttemp->next)
        {
            ttemp = ttemp->next;
            if (strcmp(ttemp->filename, temp->filename) == 0 && ttemp->isdir == 1)
            {
                printf(" �Բ���, Ŀ¼�Ѵ���!");
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
int create()
{
    temp = initfile(" ", 0);
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
            if (strcmp(ttemp->filename, temp->filename) == 0 && ttemp->isdir == 0)
            {
                printf(" �Բ���, �ļ��Ѵ���!");
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
int dir()
{
    int i = 0, j = 0;
    temp = new fnode;
    temp = recent;
    if (temp != root)
    {
        cout << " <DIR> "
             << ".." << endl;
        i++;
    }
    if (temp->child == NULL)
    {
        cout << "Total: "
             << " directors\t" << i << "\tfiles\t" << j << endl;
        return 1;
    }
    temp = temp->child;
    while (temp)
    {
        if (temp->isdir)
        {
            cout << " <DIR> " << temp->filename << endl;
            i++;
        }
        else
        {
            cout << " <FILE> " << temp->filename << endl;
            j++;
        }
        temp = temp->next;
    }
    cout << "Total: "
         << " directors\t" << i << "\tfiles\t" << j << endl;
    return 1;
}
int read()
{
    char filename[FILENAME_LENGTH];
    cin >> filename;
    if (recent->child == NULL)
    {
        cout << " �ļ�������!" << endl;
        return 1;
    }
    if (strcmp(recent->child->filename, filename) == 0)
    {
        cout << recent->child->content << endl;
        return 1;
    }
    else
    {
        temp = recent->child;
        while (temp->next)
        {
            if (strcmp(temp->next->filename, filename) == 0)
            {
                cout << temp->next->content << endl;
                return 1;
            }
        }
        cout << " �ļ�������!" << endl;
    }
    return 1;
}

int write()
{
    char filename[FILENAME_LENGTH];
    cin >> filename;
    if (recent->child == NULL)
    {
        cout << " �ļ������� !" << endl;
        return 1;
    }
    if (strcmp(recent->child->filename, filename) == 0)
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
            if (strcmp(temp->next->filename, filename) == 0)
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
int cd()
{
    char topara[PARA_LENGTH];
    cin >> topara;
    if (strcmp(topara, "..") == 0)
    {
        int i;
        while (recent->prev)
            recent = recent->prev;
        if (recent->parent)
        {
            recent = recent->parent;
        }
        i = strlen(para);
        while (para[i] != '/' && i > 0)
            i--;
        if (i != 0)
            para[i] = '\0';
        else
            para[i + 1] = '\0';
    }
    else
    {
        findpara(topara);
    }
    return 1;
}
int findpara(char *topara)
{
    int i = 0;
    int sign = 1;
    if (strcmp(topara, "/") == 0)
    {
        recent = root;
        strcpy(para, "/");
        return 1;
    }
    temp = recent;
    strcpy(temppara, para);
    if (topara[0] == '/')
    {
        recent = root->child;
        i++;
        strcpy(para, "/");
    }
    else
    {
        if (recent != NULL && recent != root)
            strcat(para, "/");
        if (recent && recent->child)
        {
            if (recent->isdir)
                recent = recent->child;
            else
            {
                printf(" ·������ \n");
                return 1;
            }
        }
    }
    while (i <= strlen(topara) && recent)
    {
        int j = 0;
        if (topara[i] == '/' && recent->child)
        {
            i++;
            if (recent->isdir)
                recent = recent->child;
            else
            {
                printf(" ·������\n");
                return 0;
            }
            strcat(para, "/");
        }
        while (topara[i] != '/' && i <= strlen(topara))
        {
            recentpara[j] = topara[i];
            i++;
            j++;
        }
        recentpara[j] = '\0';
        while ((strcmp(recent->filename, recentpara) != 0 || (recent->isdir != 1)) &&
               recent->next != NULL)
        {
            recent = recent->next;
        }
        if (strcmp(recent->filename, recentpara) == 0)
        {
            if (recent->isdir == 0)
            {
                strcpy(para, temppara);
                recent = temp;
                printf(" ���ļ�����Ŀ¼��\n");
                return 0;
            }
            strcat(para, recent->filename);
        }
        if (strcmp(recent->filename, recentpara) != 0 || recent == NULL)
        {
            strcpy(para, temppara);
            recent = temp;
            printf(" ����·������\n");
            return 0;
        }
    }
    return 1;
}
int del()
{
    char filename[FILENAME_LENGTH];
    cin >> filename;
    temp = new fnode;
    if (recent->child)
    {
        temp = recent->child;
        while (temp->next && (strcmp(temp->filename, filename) != 0 || temp->isdir != 0))
            temp = temp->next;
        if (strcmp(temp->filename, filename) != 0)
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

bool chklogin(char *users, char *pwd)
{
    int i;
    for (i = 0; i < 8; i++)
    {
        if ((strcmp(users, usrarray[i].name) == 0) && (strcmp(pwd, usrarray[i].pwd) == 0))
            return true;
    }
    return false;
}
void help(void)
{
    cout << " ����һ�� " << endl;
    cout << endl;
    cout << "create: �����ļ��� " << endl;
    cout << "read: ��ȡ�ļ��� " << endl;
    cout << "write: д���ļ�, ֧�ֶ��߳� " << endl;
    cout << "del : ɾ���ļ��� " << endl;
    cout << "mkdir: ����Ŀ¼�� " << endl;
    cout << "cd: �л�Ŀ¼�� " << endl;
    cout << "logout: �˳���¼�� " << endl;
}
int run()
{
    cout << "linux:" << para << ">";
    cin >> command;
    if (strcmp(command, "mkdir") == 0)
        mkdir();
    else if (strcmp(command, "dir") == 0)
        dir();
    else if (strcmp(command, "cd") == 0)
        cd();
    else if (strcmp(command, "create") == 0)
        create();
    else if (strcmp(command, "read") == 0)
        read();
    else if (strcmp(command, "write") == 0)
        write();
    else if (strcmp(command, "del") == 0)
        del();
    else if (strcmp(command, "help") == 0)
        help();
    else if (strcmp(command, "logout") == 0)
        return 0;
    else
        cout << " ��ο�help �ṩ�������б�!" << endl;
    return 1;
}
int main()
{
    int i = 0;
    bool in = false;
    char users[8], pwd[12];
    cout << "***************************************************************" << endl;
    cout << "* �򵥵Ķ���Linux �ļ�ϵͳ                                     * " << endl;
    cout << "* �˺ţ�usr1-usr8 ���룺usr1-user8                             *" << endl;
    cout << "* ��ֻ�����λ����������˺�                                     * " << endl;
    cout << "* ����help ���Ի�ȡ����                                       * " << endl;
    cout << "***************************************************************" << endl;
    cout << endl;
    while (i < 3)
    {
        cout << "Login:";
        cin >> users;
        cout << "Pass:";
        cin >> pwd;
        if (chklogin(users, pwd))
        {
            in = true;
            break;
        }
        i++;
    }
    createroot();
    while (in)
    {
        if (!run())
            break;
    }
    return 0;
}