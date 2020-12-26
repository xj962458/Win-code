#include <iostream>
#include <iomanip>
#include <cstring>
#include <windows.h>
using namespace std;
#define FILENAME_LENGTH 10 // 文件名称长度
#define COMMAND_LENGTH 10  // 命令行长度
#define PARA_LENGTH 30     // 参数长度

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
fnode *initfile(char filename[], int isdir);
void createroot();
int run();
int findpara(char *topara);
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
                cout << " 对不起, 目录已存在!";
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
                cout << " 对不起, 文件已存在!";
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
        cout << " <目录> "
             << ".." << endl;
        i++;
    }
    if (temp->child == NULL)
    {
        cout << "总计: "
             << " 目录:" << i << "\t文件:" << j << endl;
        return 1;
    }
    temp = temp->child;
    while (temp)
    {
        if (temp->isdir)
        {
            cout << " <目录> " << temp->filename << endl;
            i++;
        }
        else
        {
            cout << " <文件> " << temp->filename << endl;
            j++;
        }
        temp = temp->next;
    }
    cout << "总计: "
         << " 目录:" << i << "\t文件:" << j << endl;
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
                cout << " 路径错误！ \n";
                return 1;
            }
        }
    }
    while (i <= signed(strlen(topara)) && recent)
    {
        int j = 0;
        if (topara[i] == '/' && recent->child)
        {
            i++;
            if (recent->isdir)
                recent = recent->child;
            else
            {
                cout << " 路径错误\n";
                return 0;
            }
            strcat(para, "/");
        }
        while (topara[i] != '/' && i <= signed(strlen(topara)))
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
                cout << " 是文件不是目录。\n";
                return 0;
            }
            strcat(para, recent->filename);
        }
        if (strcmp(recent->filename, recentpara) != 0 || recent == NULL)
        {
            strcpy(para, temppara);
            recent = temp;
            cout << " 输入路径错误\n";
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

int run()
{
    cout << "root" << para << ">";
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
    else if (strcmp(command, "exit") == 0)
        return 0;
    else
        cout << " 请参考help 提供的命令列表!" << endl;
    return 1;
}
void help()
{
    cout << "\t\t\t=====================帮助命令一览====================\n";
    cout << "\t\t\t*                                                   *\n";
    cout << "\t\t\t*          1>. create: 创建文件                     *\n";
    cout << "\t\t\t*          2>. read: 读取文件                       *\n";
    cout << "\t\t\t*          3>. write: 写入文件                      *\n";
    cout << "\t\t\t*          4>. del : 删除文件                       *\n";
    cout << "\t\t\t*          5>. mkdir: 建立目录                      *\n";
    cout << "\t\t\t*          6>. cd: 切换目录                         *\n";
    cout << "\t\t\t*          7>. exit: 退出登录                       *\n";
    cout << "\t\t\t*                                    欢迎使用本系统!*\n";
    cout << "\t\t\t=====================================================\n";
}
int main()
{
    int i = 0;
    bool in = false;
    char users[8], pwd[12];
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE);
    // system("color 06");
    cout << "\t\t\t=====================文件系统模拟====================\n";
    cout << "\t\t\t*                                                   *\n";
    cout << "\t\t\t*         1>. 你只有三次机会来试验账号              *\n";
    cout << "\t\t\t*         2>. 键入help 可以获取帮助                 *\n";
    cout << "\t\t\t*                                    欢迎使用本系统!*\n";
    cout << "\t\t\t=====================================================\n";
    cout << endl;
    while (i < 3)
    {
        cout << "请输入用户名:";
        cin >> users;
        cout << "请输入密码:";
        cin >> pwd;
        if ((strcmp("root", users) == 0) && (strcmp("root", pwd) == 0))
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
