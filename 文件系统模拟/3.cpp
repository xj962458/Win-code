#include <iostream>
#include <string>
#include <cstring>
#include <fstream>
using namespace std;
typedef struct node
{
    string name;       //姓名
    string tel;        //手机号
    string email;      //邮箱
    string address;    //地址
    struct node *next; //指向下一节点的指针
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
    // p->address="安琥";
    // p->next=L->next;
    // L->next=p;
    Node no[4] = {
        {"张三", "17605675448", "2291921855@qq.com", "宿州"},
        {"李四", "17682750129", "8371273037@qq.com", "阜阳"},
        {"张平", "17656675448", "2299342855@qq.com", "北京"},
        {"王五", "17634750129", "8567237037@qq.com", "上海"},
    };
    ofstream outfile("./联系人1.csv");
    outfile << "姓名,"
            << "手机号,"
            << "邮箱,"
            << "地址" << endl;
    for (int i = 0; i < 3; i++)
        outfile << no[i].name << ',' << no[i].tel << ',' << no[i].email << ',' << no[i].address<<endl;
    outfile << no[3].name << ',' << no[3].tel << ',' << no[3].email << ',' << no[3].address;
    outfile.close();
    // q=L;
    // while(q->next!=NULL)
    //     q=q->next;
    // ifstream infile("./联系人1.csv");
    // if (!infile)
    // {
    //     cout << "无法打开文件!";
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
    //     /* 获取第一个子字符串 */
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
    //     /* 继续获取其他的子字符串 */
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