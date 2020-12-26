#include <iostream>
#include <iomanip>
#include <cstring>
using namespace std;

#define FILENAME_LENGTH 10 // 文件名称长度
#define COMMAND_LENGTH 10  // 命令行长度
#define PARA_LENGTH 30     // 参数长度
// 账号结构
typedef struct users
{
    char name[8];
    char pwd[10];
} users;
// 文件结构
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
// 账号
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
// 创建文件与目录结点
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
// 创建文件存储结点
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
                printf(" 对不起, 目录已存在!");
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
        cout << " 文件建立成功!" << endl;
    }
    else
    {
        ttemp = recent->child;
        while (ttemp->next)
        {
            ttemp = ttemp->next;
            if (strcmp(ttemp->filename, temp->filename) == 0 && ttemp->isdir == 0)
            {
                printf(" 对不起, 文件已存在!");
                return 1;
            }
        }
        ttemp->next = temp;
        temp->parent = NULL;
        temp->child = NULL;
        temp->prev = ttemp;
        temp->next = NULL;
        cout << " 文件建立成功!" << endl;
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
        cout << " 文件不存在!" << endl;
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
        cout << " 文件不存在!" << endl;
    }
    return 1;
}

int write()
{
    char filename[FILENAME_LENGTH];
    cin >> filename;
    if (recent->child == NULL)
    {
        cout << " 文件不存在 !" << endl;
        return 1;
    }
    if (strcmp(recent->child->filename, filename) == 0)
    {
        recent->child->isopen = 1; // 设置文件标记为打开
        cin >> recent->child->content;
        recent->child->isopen = 0; // 设置文件标记为关闭
        cout << " 文件写入成功 !" << endl;
        return 1;
    }
    else
    {
        temp = recent->child;
        while (temp->next)
        {
            if (strcmp(temp->next->filename, filename) == 0)
            {
                recent->child->isopen = 1; // 设置文件标记为打开
                cin >> temp->next->content;
                recent->child->isopen = 0; // 设置文件标记为关闭
                cout << " 文件写入成功 !" << endl;
                return 1;
            }
        }
        cout << " 文件不存在 !" << endl;
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
                printf(" 路径错误！ \n");
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
                printf(" 路径错误\n");
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
                printf(" 是文件不是目录。\n");
                return 0;
            }
            strcat(para, recent->filename);
        }
        if (strcmp(recent->filename, recentpara) != 0 || recent == NULL)
        {
            strcpy(para, temppara);
            recent = temp;
            printf(" 输入路径错误\n");
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
            cout << " 不存在该文件！ " << endl;
            return 0;
        }
    }
    else
    {
        cout << " 不存在该文件！ " << endl;
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
    cout << " 文件已删除!" << endl;
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
    cout << " 命令一览 " << endl;
    cout << endl;
    cout << "create: 建立文件。 " << endl;
    cout << "read: 读取文件。 " << endl;
    cout << "write: 写入文件, 支持多线程 " << endl;
    cout << "del : 删除文件。 " << endl;
    cout << "mkdir: 建立目录。 " << endl;
    cout << "cd: 切换目录。 " << endl;
    cout << "logout: 退出登录。 " << endl;
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
        cout << " 请参考help 提供的命令列表!" << endl;
    return 1;
}
int main()
{
    int i = 0;
    bool in = false;
    char users[8], pwd[12];
    cout << "***************************************************************" << endl;
    cout << "* 简单的二级Linux 文件系统                                     * " << endl;
    cout << "* 账号：usr1-usr8 密码：usr1-user8                             *" << endl;
    cout << "* 你只有三次机会来试验账号                                     * " << endl;
    cout << "* 键入help 可以获取帮助                                       * " << endl;
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