//����Li2_15.cpp
//Ӧ��ʵ��
#include<iostream>
#include<string>
using namespace std;
struct Student
{
   long num;
   string name;
   float score;
   struct  Student *next;
};
void input(Student *&head) 
{
   long num;
   int n=0;
   Student *newNode,*p;
   do{
	  cout<<"�����"<<n+1<<"��ѧ����ѧ�ţ�����0������";
      cin>>num;
      if(num==0)  break;
      n++;
      newNode=new Student;
      newNode->num=num;
      cout<<"������ѧ��Ϊ"<<num<<"������, �ɼ���";
      cin>>newNode->name>>newNode->score;
      if(head==NULL)
          head=newNode;
      else
        p->next=newNode;
        p=newNode;
   }while(1);
   p->next=NULL;
   cout<<"������"<<n<<"��ѧ����¼"<<endl;
   return;
}
float average(Student *head)
{
	Student *p;
    p=head;
	int n=0;
	float ave=0.0;
    if(head==NULL)  return 0.0;
    do
	{
		n=n+1;
        ave+=p->score;
        p=p->next;
	}while (p!=NULL);
	ave=ave/n;
	return ave;
}   
void print( Student* const head)
{
	Student *p;
    int  i=0;
    if(head==NULL)  return;
    p=head;
    cout<<"ѧ��    ����    �ɼ�   "<<endl;
    do
    {
		cout<<p->num<<"      "<<p->name;
        cout<<"      "<<p->score<<endl;
        p=p->next;
	}while(p!=NULL);
}
int main()
{
       Student *stu=NULL;
       input(stu);
	   float ave=average(stu);
       print(stu);
       cout<<"ȫ��ƽ���ɼ�Ϊ��"<<ave<<endl;
       return 0;
}