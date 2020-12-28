#include <iostream>
#include <string>
#include <fstream>
#include <windows.h>
using namespace std;
typedef struct node1
{
    string name;        //姓名
    string tel;         //手机号
    string email;       //邮箱
    string address;     //地址
    struct node1 *next; //指向下一节点的指针
} Node;

class Fnode
{
public:
    Fnode();                 //构造函数，用于初始化一些变量
    ~Fnode();                //析构函数，用于程序结束之后对分配的内存进行清理
    void CreateInfo();       //录入联系人信息
    void InsertInfo();       //插入联系人信息
    void FindInfoName();     //按姓名查找联系人信息
    void FindInfoTel();      //按手机号查找联系人信息
    void DeleteInfoTel();    //按手机号删除联系人信息
    void DispInfo();         //打印所有联系人信息
    void DispInfoSort();     //按姓名排序输出联系人信息
    void SaveInfoToFile();   //保存联系人信息至文件
    void ReadInfoFromFile(); //从文件读取联系人信息
    void Menu();             //菜单

private:
    bool opened; //用于表明文件是否被读取过
    Node *L, *p, *q;
};

Fnode::Fnode() //构造函数，用于初始化一些变量
{
    L = new Node;
    L->next = NULL;
    opened = 0;
}

Fnode::~Fnode() //析构函数，用于程序结束之后对分配的内存进行清理
{
    p = L;
    while (p != NULL)
    {
        delete p;
        p = p->next;
    }
}

void Fnode::CreateInfo() //创建结点
{
    int n;
    q = L->next;
    while (q->next != NULL)
        q = q->next;
    cout << "请输入您要录入的联系人个数:";
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        p = new Node;
        cout << "请输入第" << i + 1 << "位联系人的姓名、手机号、邮箱和地址(用空格隔开):" << endl;
        cin >> p->name >> p->tel >> p->email >> p->address;
        p->next = q->next;
        q->next = p;
        q = p;
    }
}

void Fnode::InsertInfo()
{
    q = L;
    while (q->next != NULL)
        q = q->next;
    p = new Node;
    cout << "请输入您要插入的联系人的姓名、手机号、邮箱和地址(用空格隔开):" << endl;
    cin >> p->name >> p->tel >> p->email >> p->address;
    p->next = q->next;
    q->next = p;
    cout << "插入成功!" << endl;
}

void Fnode::DispInfo() //打印所有联系人信息
{
    p = L->next;
    if (p == NULL)
        cout << "数据为空，无法打印" << endl;
    else
    {
        cout << "姓名  \t\t"
             << "手机号       \t\t"
             << "邮箱             \t\t"
             << "地址" << endl;
        while (p != NULL)
        {
            cout << p->name << "\t\t" << p->tel << "\t\t" << p->email << "\t\t" << p->address << endl;
            p = p->next;
        }
    }
}

void Fnode::FindInfoName() //按姓名查找联系人信息
{
    string name;
    p = L->next;
    if (p == NULL)
        cout << "数据为空，无法查找" << endl;
    else
    {
        cout << "请输入要查找的联系人的姓名:";
        cin >> name;
        while (p->name != name)
        {
            p = p->next;
            if (p == NULL)
            {
                cout << "没有找到相关联系人信息" << endl;
                return;
            }
        }
        cout << "该联系人的信息如下" << endl;
        cout << "姓名  \t\t"
             << "手机号       \t\t"
             << "邮箱             \t\t"
             << "地址" << endl;
        cout << p->name << "\t\t" << p->tel << "\t\t" << p->email << "\t\t" << p->address << endl;
    }
}

void Fnode::FindInfoTel() //按手机号查找联系人信息
{
    string tel;
    p = L->next;
    if (p == NULL)
        cout << "数据为空，无法查找" << endl;
    else
    {
        cout << "请输入要查找的联系人的手机号:";
        cin >> tel;
        while (p->tel != tel)
        {
            p = p->next;
            if (p == NULL)
            {
                cout << "没有找到相关信息" << endl;
                return;
            }
        }
        cout << "该联系人的信息如下" << endl;
        cout << "姓名  \t\t"
             << "手机号       \t\t"
             << "邮箱             \t\t"
             << "地址" << endl;
        cout << p->name << "\t\t" << p->tel << "\t\t" << p->email << "\t\t" << p->address << endl;
    }
}

void Fnode::DeleteInfoTel() //按手机号删除联系人信息
{
    string tel;
    p = L->next, q = L;
    if (p == NULL)
        cout << "数据为空，无法删除" << endl;
    else
    {
        cout << "请输入要删除的联系人的手机号" << endl;
        cin >> tel;
        while (p->tel != tel)
        {
            p = p->next;
            q = q->next;
            if (p == NULL)
            {
                cout << "没有找到相关信息" << endl;
                return;
            }
        }
        q->next = p->next;
        delete p;
        cout << "手机号为" << tel << "的联系人删除成功!" << endl;
    }
}

void Fnode::DispInfoSort() //按姓名排序输出联系人信息
{
    Node *L1;
    p = L->next, q = p->next;
    while (p != NULL)
    {
        if (p->name < q->name)
        {
        }
    }
}

void Fnode::SaveInfoToFile() //保存联系人信息至文件
{
    p = L->next;
    if (p == NULL)
        cout << "数据为空，无法写入!" << endl;
    else
    {
        ofstream outfile("./联系人.csv");
        if (!outfile)
        {
            cout << "无法打开文件!";
            return;
        }
        outfile << "姓名,"
                << "手机号,"
                << "邮箱,"
                << "地址" << endl;
        while (p != NULL)
        {
            outfile << p->name << "," << p->tel << "," << p->email << "," << p->address << endl;
            p = p->next;
        }
        outfile.close();
        cout << "保存联系人信息成功！请查看当前目录下的“联系人.csv文件”" << endl;
    }
}

void Fnode::ReadInfoFromFile() //从文件读取联系人信息
{
    ifstream infile("./联系人.csv");
    if (!infile)
    {
        cout << "无法打开文件!";
        return;
    }
    else if (opened == 1)
    {
        cout << "文件已经被读取，不能够重复读取!" << endl;
        return;
    }
    else
    {
        char str[100];
        q = L;
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
        cout << "读取数据成功！" << endl;
        opened = 1;
    }
}

void Fnode::Menu() //菜单
{
    int item;
    do
    {
        cout << "\t\t\t==================通讯录管理系统==================" << endl;
        cout << "\t\t\t# \t                                         #" << endl;
        cout << "\t\t\t# \t1)联系人信息的逐条录入。                 #" << endl;
        cout << "\t\t\t# \t2)插入某个联系人的信息。                 #" << endl;
        cout << "\t\t\t# \t3)按手机号查找某个联系人的信。           #" << endl;
        cout << "\t\t\t# \t4)按姓名查询某个联系人。                 #" << endl;
        cout << "\t\t\t# \t5)按手机号删除某个联系人的信息           #" << endl;
        cout << "\t\t\t# \t6)所有联系人信息的输出显示。             #" << endl;
        cout << "\t\t\t# \t7)所有联系人按姓名排序并输出显示。       #" << endl;
        cout << "\t\t\t# \t8)所有联系人信息的文件保存。             #" << endl;
        cout << "\t\t\t# \t9)所有联系人信息的文件读取。             #" << endl;
        cout << "\t\t\t# \t0)退出管理系统。                         #" << endl;
        cout << "\t\t\t==================================================" << endl;
        cout << "请输入相应的命令，执行相应的功能:";
        cin >> item;
        system("cls");
        switch (item)
        {
        case 1:
            CreateInfo();
            getchar();
            cout << "\n按任意键返回主菜单" << endl;
            getchar();
            system("cls");
            break;
        case 2:
            InsertInfo();
            getchar();
            cout << "\n按任意键返回主菜单" << endl;
            getchar();
            system("cls");
            break;
        case 3:
            FindInfoTel();
            getchar();
            cout << "\n按任意键返回主菜单" << endl;
            getchar();
            system("cls");
            break;
        case 4:
            FindInfoName();
            getchar();
            cout << "\n按任意键返回主菜单" << endl;
            getchar();
            system("cls");
            break;
        case 5:
            DeleteInfoTel();
            getchar();
            cout << "\n按任意键返回主菜单" << endl;
            getchar();
            system("cls");
            break;
        case 6:
            DispInfo();
            getchar();
            cout << "\n按任意键返回主菜单" << endl;
            getchar();
            system("cls");
            break;
        case 7:
            DispInfoSort();
            getchar();
            cout << "\n按任意键返回主菜单" << endl;
            getchar();
            system("cls");
            break;
        case 8:
            SaveInfoToFile();
            getchar();
            cout << "\n按任意键返回主菜单" << endl;
            getchar();
            system("cls");
            break;
        case 9:
            ReadInfoFromFile();
            getchar();
            cout << "\n按任意键返回主菜单" << endl;
            getchar();
            system("cls");
            break;
        case 0:
            cout << "即将退出通讯录管理系统......" << endl;
            cout << "谢谢您的使用!";
            exit(0);
            break;
        default:
            cout << "您输入的指令错误，请重新输入!" << endl;
            getchar();
            cout << "\n按任意键返回主菜单" << endl;
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