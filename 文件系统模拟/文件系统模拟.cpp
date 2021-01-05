#include <iostream>
#include <string>
#include <cstring>
using namespace std;

typedef struct file
{
    string filename;    //�ļ���Ŀ¼��
    int isdir;          //�Ƿ���Ŀ¼,�ǵĻ�Ϊ1,����Ϊ0
    int opened;         //�Ƿ��
    string filecontent; //�ļ�����
    file *parent;       //˫�׽ڵ�
    file *child;        //���ӽڵ�
    file *next;         //��һ���ֵܽڵ�
    file *pre;          //ǰһ���ֵܽڵ�
} File;

class FileClass
{
public:
    File *InitFile(string filename, int isdir); // �����ļ���Ŀ¼���
    void CreateRoot();                          // �����ļ��洢�����
    void FindPara(string topara);               //Ѱ�ҵ�ǰ·���ĸ�·��������·��
    void Mkdir();                               //����Ŀ¼
    void Create();                              //�����ļ�
    void Read();                                //��ȡ�ļ�����
    void Write();                               //���ļ�д������
    void Del();                                 //ɾ���ļ���Ŀ¼
    void Cd();                                  //�л�Ŀ¼
    void Dir();                                 //��ʾ�ļ���Ŀ¼
    void Help();                                //��������
    int Run();                                  //�������к���

private:
    File *root, *recent, *temp, *ttemp;         //����ָ�룬�������к����ĵ���
    string para, command, temppara, recentpara; //�����ַ��������������洢·���Լ����������
};

// �����ļ���Ŀ¼���
File *FileClass::InitFile(string filename, int isdir)
{
    File *node = new File;
    node->filename = filename;
    node->isdir = isdir;
    node->opened = 0;
    node->parent = NULL;
    node->child = NULL;
    node->next = NULL;
    node->pre = NULL;
    return node;
}

// �����ļ��洢�����
void FileClass::CreateRoot()
{
    recent = root = InitFile("/", 1);
    root->parent = NULL;
    root->child = NULL;
    root->pre = root->next = NULL;
    para = "/";
}

//����Ŀ¼
void FileClass::Mkdir()
{
    temp = InitFile(" ", 1);
    cin >> temp->filename;
    if (recent->child == NULL)
    {
        temp->parent = recent;
        temp->child = NULL;
        recent->child = temp;
        temp->pre = temp->next = NULL;
        cout << " Ŀ¼�����ɹ�!" << endl;
    }
    else
    {
        ttemp = recent->child;
        if (ttemp->filename == temp->filename && ttemp->isdir == 1)
        {
            cout << " Ŀ¼�Ѿ�����!" << endl;
            return;
        }
        else
        {
            while (ttemp->next)
            {
                ttemp = ttemp->next;
                if (ttemp->filename == temp->filename && ttemp->isdir == 1)
                {
                    cout << " Ŀ¼�Ѿ�����!" << endl;
                    return;
                }
            }
        }
        ttemp->next = temp;
        temp->parent = NULL;
        temp->child = NULL;
        temp->pre = ttemp;
        temp->next = NULL;
        cout << " Ŀ¼�����ɹ�!" << endl;
    }
}

//�����ļ�
void FileClass::Create()
{
    temp = InitFile(" ", 0);
    cin >> temp->filename;
    cin >> temp->filecontent;
    if (recent->child == NULL)
    {
        temp->parent = recent;
        temp->child = NULL;
        recent->child = temp;
        temp->pre = temp->next = NULL;
        cout << " �ļ������ɹ�!" << endl;
    }
    else
    {
        ttemp = recent->child;
        if (ttemp->filename == temp->filename && ttemp->isdir == 0)
        {
            cout << " �ļ��Ѿ�����!" << endl;
            return;
        }
        else
        {
            while (ttemp->next)
            {
                ttemp = ttemp->next;
                if (ttemp->filename == temp->filename && ttemp->isdir == 0)
                {
                    cout << " �ļ��Ѵ���!" << endl;
                    return;
                }
            }
        }
        ttemp->next = temp;
        temp->parent = NULL;
        temp->child = NULL;
        temp->pre = ttemp;
        temp->next = NULL;
        cout << " �ļ������ɹ�!" << endl;
    }
}

//��ʾ�ļ���Ŀ¼
void FileClass::Dir()
{
    int i = 0, j = 0;
    temp = recent;
    if (temp != root)
    {
        cout << " <Ŀ¼> .." << endl;
        i++;
    }
    if (temp->child == NULL)
    {
        cout << "�ܼ�:"
             << " Ŀ¼:" << i << "\t�ļ�:" << j << endl;
        return;
    }
    temp = temp->child;
    while (temp != NULL)
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
         << "Ŀ¼: " << i << "\t�ļ�:" << j << endl;
}

//��ȡ�ļ�����
void FileClass::Read()
{
    string filename;
    cin >> filename;
    if (recent->child == NULL)
    {
        cout << "�ļ�������!" << endl;
        return;
    }
    else
    {
        temp = recent->child;
        while (temp)
        {
            if (temp->filename == filename)
            {
                cout << temp->filecontent << endl;
                return;
            }
            temp = temp->next;
        }
        cout << " �ļ�������!" << endl;
    }
}

//���ļ�д������
void FileClass::Write()
{
    string filename;
    cin >> filename;
    if (recent->child == NULL)
    {
        cout << "�ļ�������!" << endl;
        return;
    }
    else
    {
        temp = recent->child;
        while (temp != NULL)
        {
            if (temp->filename == filename)
            {
                recent->opened = 1; //�����ļ����Ϊ��
                cin >> temp->filecontent;
                recent->opened = 0; //�����ļ����Ϊ�ر�
                cout << "�ļ�д��ɹ�!" << endl;
                return;
            }
            temp = temp->next;
        }
        cout << "�ļ�������!" << endl;
    }
}

//ɾ���ļ���Ŀ¼
void FileClass::Del()
{
    string filename;
    cin >> filename;
    if (recent->child != NULL)
    {
        temp = recent->child;
        while (temp->next && temp->filename != filename)
            temp = temp->next;
        if (temp->filename != filename)
        {
            cout << " �����ڸ��ļ�!" << endl;
            return;
        }
    }
    else
    {
        cout << " �����ڸ��ļ�! " << endl;
        return;
    }
    if (temp->parent == NULL)
    {
        temp->pre->next = temp->next;
        if (temp->next)
            temp->next->pre = temp->pre;
        temp->pre = temp->next = NULL;
    }
    else
    {
        if (temp->next)
            temp->next->parent = temp->parent;
        temp->parent->child = temp->next;
    }
    delete temp;
    cout << "�ļ���ɾ��!" << endl;
}

//�л�Ŀ¼
void FileClass::Cd()
{
    string topara;
    cin >> topara;
    if (topara == "..") //�л���һ��Ŀ¼
    {
        int i;
        while (recent->pre)
            recent = recent->pre;
        if (recent->parent)
            recent = recent->parent;
        i = para.length();
        while (para[i] != '/' && i > 0)
            i--;
        para.replace(i + 1, para.length(), "\0");
    }
    else
        FindPara(topara);
}

//Ѱ�ҵ�ǰ·���ĸ�·��������·��
void FileClass::FindPara(string topara)
{
    int i = 0;
    int sign = 1;
    char str[50];
    if (topara == "/") //�л��ظ����
    {
        recent = root;
        para = "/";
        return;
    }
    temp = recent;
    temppara = para;
    if (topara[0] == '/') //�л�Ϊ���ڵ�ĵ�һ����Ŀ¼
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
                cout << "·������!" << endl;
                return;
            }
        }
    }
    while (i <= signed(topara.length()) && recent) //������Ҫ�����·�����д���
    {
        int j = 0;
        if (topara[i] == '/' && recent->child)
        {
            i++;
            if (recent->isdir)
                recent = recent->child;
            else
            {
                cout << "·������!" << endl;
                return;
            }
            para += "/";
        }
        while (topara[i] != '/' && i <= signed(topara.length()))
        {
            str[j] = topara[i];
            i++;
            j++;
        }
        str[j] = '\0';
        recentpara = string(str);
        while ((recent->filename != recentpara || (recent->isdir != 1)) &&
               recent->next != NULL)
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
                return;
            }
            para += recent->filename;
        }
        if (recent->filename != recentpara || recent == NULL)
        {
            para = temppara;
            recent = temp;
            cout << " ����·������\n";
            return;
        }
    }
}

//��������
void FileClass::Help()
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

//�������к���
int FileClass::Run()
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
    {
        cout << "�����˳��ļ�ϵͳģ�⣬лл����ʹ�ã�" << endl;
        return 0;
    }
    else
        cout << " ��ο�help �ṩ�������б�!" << endl;
    return 1;
}
int main()
{
    int i = 0;
    bool in = false;     //inΪtrue���������ϵͳ�������������
    FileClass f;         //����һ��FileClass����
    string user, passwd; //���ڴ洢�û���������
    cout << "\t\t\t=====================�ļ�ϵͳģ��====================\n";
    cout << "\t\t\t*                                                   *\n";
    cout << "\t\t\t*         1>. ��ֻ�����λ����������˺�              *\n";
    cout << "\t\t\t*         2>. ����help ���Ի�ȡ����                 *\n";
    cout << "\t\t\t*                                    ��ӭʹ�ñ�ϵͳ!*\n";
    cout << "\t\t\t=====================================================\n";
    cout << endl;
    while (i < 3) //���������˺ź�����Ĵ������Ϊ����
    {
        cout << "�������û���:";
        cin >> user;
        cout << "����������:";
        cin >> passwd;
        if (user == "root" && passwd == "root")
        {
            in = true;
            break;
        }
        else
        {
            if (2 - i != 0)
                cout << "\t��������˺Ż������������������,������" << 2 - i << "�λ���!" << endl;
            else
            {
                cout << "\t���Ļ��������꣡лл����ʹ��" << endl;
                exit(0);
            }
        }
        i++;
    }
    f.CreateRoot(); //�������ڵ�
    while (in)      //������Ϣѭ��
    {
        if (!f.Run())
            break;
    }
    return 0;
}