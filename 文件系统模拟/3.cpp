#include <iostream>
#include <string>
#include <cstring>
#include <fstream>
using namespace std;
typedef struct node
{
    string name;       //����
    string tel;        //�ֻ���
    string email;      //����
    string address;    //��ַ
    struct node *next; //ָ����һ�ڵ��ָ��
} Node;
// Node p[4];
int main()
{
    // Node *L=new Node,*p,*q;
    // L->next=NULL;
    char str[100];
    // p->name="Tom";
    // p->tel="17606787889";
    // p->email="2291921855@qq.com";
    // p->address="����";
    // p->next=L->next;
    // L->next=p;
    Node no[4] = {
        {"����", "17605675448", "2291921855@qq.com", "����"},
        {"����", "17682750129", "8371273037@qq.com", "����"},
        {"��ƽ", "17656675448", "2299342855@qq.com", "����"},
        {"����", "17634750129", "8567237037@qq.com", "�Ϻ�"},
    };
    ofstream outfile("./��ϵ��1.csv");
    outfile << "����,"
            << "�ֻ���,"
            << "����,"
            << "��ַ" << endl;
    for (int i = 0; i < 3; i++)
        outfile << no[i].name << ',' << no[i].tel << ',' << no[i].email << ',' << no[i].address<<endl;
    outfile << no[3].name << ',' << no[3].tel << ',' << no[3].email << ',' << no[3].address;
    outfile.close();
    // q=L;
    // while(q->next!=NULL)
    //     q=q->next;
    // ifstream infile("./��ϵ��1.csv");
    // if (!infile)
    // {
    //     cout << "�޷����ļ�!";
    //     exit(0);
    // }
    // // infile.getline(str, sizeof(str));
    // while (!infile.eof())
    // {
    //     p=new Node;
    //     // infile.getline(str,sizeof(str));
    //     infile.getline(str, sizeof(str));
    //     // Convert(str);
    //     // str1=strtok(str, ",");
    //     // strcpy(str1, strtok(NULL, ","));
    //     // strcpy(str2, strtok(NULL, ","));
    //     // strcpy(str3, strtok(NULL, ","));
    //     // cout<< str <<" "<<str1<<" "<<str2<<" "<<str3<<endl;
    //     /* ��ȡ��һ�����ַ��� */
    //     // string token;
    //     // char *token = strtok(str, ",");
    //     // token = strtok(str, ",");
    //     // cout << token<<" ";
    //     // token = strtok(NULL, ",");
    //     // cout << token<<" ";
    //     // token = strtok(NULL, ",");
    //     // cout << token<<" ";
    //     // token = strtok(NULL, ",");
    //     // cout << token;
    //     p->name = strtok(str, ",");
    //     // cout << token << " ";
    //     p->tel = strtok(NULL, ",");
    //     // cout << token << " ";
    //     p->email = strtok(NULL, ",");
    //     // cout << token << " ";
    //     p->address = strtok(NULL, ",");
    //     // p->next=L->next;
    //     // L->next=p;
    //     p->next=q->next;
    //     q->next=p;
    //     q=p;
    //     // cout << token;
    //     /* ������ȡ���������ַ��� */
    //     // while (token != '\0')
    //     // {
    //     //     // printf("%s", token);
    //     //     cout<<token<<" ";
    //     //     token = strtok(NULL, ",");
    //     // }
    //     // cout<<endl;
    //     // cout<<str1<<endl;
    // }
    // infile.close();
    // // for (int i = 0; i < 4; i++)
    //     // cout << p[i].name << " " << p[i].tel << " " << p[i].email << " " << p[i].address << endl;
    // p=L->next;
    // while(p!=NULL){
    //     cout << p->name << " " << p->tel << " " << p->email << " " << p->address << endl;
    //     p=p->next;
    // }
    return 0;
}