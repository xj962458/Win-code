#include <iostream>
#include <stdlib.h>
#include <conio.h>
#include <time.h>
#include <string.h>
using namespace std;

//�궨��
#define MaxUser 20          //�������MDF��Ŀ¼�ļ�
#define MaxDisk 512*1024     //ģ�������̿ռ�
#define commandAmount 12     //���ļ�������ָ����

//�洢�ռ�����йؽṹ��ͱ���
char disk[MaxDisk];     //ģ��512K�Ĵ��̴洢�ռ�
typedef struct distTable  //���̿�ṹ��
{
	int maxlength;
	int start;
	int useFlag;
	distTable *next;
}diskNode;

diskNode *diskHead;
struct fileTable    //�ļ���ṹ�壺�ļ���
{
	char fileName[10];
	int strat;          //�ļ��ڴ��̴洢�ռ����ʼ��ַ
	int length;         //�ļ����ݳ���
	int maxlength;      //�ļ�����󳤶�
	char fileKind[3];   //�ļ������ԡ�����д��ʽ
	struct tm *timeinfo;  //ʱ������ָ��
	bool openFlag;       //�ж��Ƿ��н��̴��˸��ļ�	
};

//����Ŀ¼�ṹ��
typedef struct userFileDirectory  //�û��ļ�Ŀ¼�ļ�UFD
{	
	fileTable *file;
	userFileDirectory *next;
}UFD;

typedef struct master_file_directory  //���ļ�Ŀ¼MFD
{
	char userName[10];
	char password[10];
	UFD *user;
}MFD;
MFD userTable[MaxUser];
int used=0;                             //����MFDĿ¼�������е��û���

//�ļ�����
//void createFile(char fileName[],int length,char fileKind[]);        //�����ļ�
void fileWrite(char fileName[]);                    //д�ļ�
void fileCat(char fileName[]);                    //���ļ�
void fileRen(char fileName[],char rename[]);        //�������ļ�
void fileFine(char fileName[]);                   //��ѯ�ļ�
void fileDir(char UserName[]);                    //��ʾĳһ�û��������ļ�
void fileClose(char fileName[]);                  //�ر��Ѵ򿪵��ļ�
//void delFile(char fileName[]);                    //ɾ���ļ�
void chmod(char fileName[],char kind[]);         //�޸��ļ��Ķ�д��ʽ
int requestDist(int &startPostion,int maxLength); //���̷����ѯ
void initDisk();                                  //��ʼ������
void freeDisk(int startPostion);                  //���̿ռ��ͷ�
void diskShow();                                  //��ʾ����ʹ�����

//�û�����
void userCreate();
int login();
int userID=-1;   //�û���¼��ID�ţ�ֵΪ-1ʱ��ʾû���û���¼



void userCreate()
{
	char c;
	char userName[10];
	int i;
	if(used<MaxUser)
	{
		cout<<"�������û�����";
		for(i=0;c=getch();i++)
		{
			if(c==13) break;
			else
				userName[i]=c;
			printf("%c",c);
		}
		userName[i]='\0';
		for(i=0;i<used;i++)
		{
			if(!strcmp(userTable[i].userName,userName))
			{
				cout<<"\n";
				cout<<"���û����Ѵ���,�����û�ʧ��\n";
				system("pause");
				return;
			}
		}
		strcpy(userTable[used].userName,userName);
		cout<<"\n";
		cout<<"���������룺";
		for(i=0;c=getch();i++)
		{
			if(c==13) break;
			else
				userTable[used].password[i]=c;
			printf("*");
		}
		userTable[userID].password[i]='\0';
		cout<<"\n";
		cout<<"�û������ɹ�\n";
		used++;
		system("pause");
	}
	else
	{
		cout<<"�����û�ʧ�ܣ��û��Ѵﵽ����\n";
		system("pause");
	}
	fflush(stdin);
}

int login()
{
	char name[10],psw[10];
	char c;
	int i,times;
	cout<<"�������û���:";
	for(i=0;c=getch();i++)
	{
		if(c==13) break;
		else
			name[i]=c;
		printf("%c",c);
	}
	name[i]='\0';
	for(i=0;i<used;i++)
	{
		if(!strcmp(userTable[i].userName,name))
			break;
	}
	if(i==used)
	{
		cout<<"\n��������û���������\n";
		system("pause");
		return -1;
	}
	for(times=0;times<3;times++)
	{
		memset(psw,'\0',sizeof(psw));
		cout<<"\n����������:";
		for(i=0;c=getch();i++)
		{
			if(c==13) break;
			else
				psw[i]=c;
			cout<<"*";
		}
		printf("\n");
		for(i=0;i<used;i++)
		{
			if(!strcmp(psw,userTable[i].password))
			{
				printf("�û���¼�ɹ�\n");
				system("pause");
				break;
			}
		}
		if(i==used)
		{
			printf("��������������������%d���������\n",2-times);
			if(times==2) exit(0);
		}
		else break;
	}
	fflush(stdin);
	return i;
}

void initDisk()
{
	diskHead=(diskNode *)malloc(sizeof(diskNode));
	diskHead->maxlength=MaxDisk;
	diskHead->useFlag=0;
	diskHead->start=0;
	diskHead->next=NULL;
}
int requestDist(int &startPostion,int maxLength)
{
	int flag=0;  //����Ƿ����ɹ�
	diskNode *p,*q,*temp;
	p=diskHead;
	while(p)
	{
		if(p->useFlag==0&&p->maxlength>maxLength)
		{
			startPostion=p->start;
			q=(diskNode *)malloc(sizeof(diskNode));
			q->start=p->start;
			q->maxlength=maxLength;
			q->useFlag=1;
			q->next=NULL;
			diskHead->start=p->start+maxLength;
			diskHead->maxlength=p->maxlength-maxLength;		
			flag=1;
			temp=p;
			if(diskHead->next==NULL) diskHead->next=q;
			else
			{
				while(temp->next) temp=temp->next;
				temp->next=q;
			}
			break;
		}
		p=p->next;
	}
	return flag;
}

void createFile(char fileName[],int length,char fileKind[])
{
	//int i,j;
	time_t rawtime;
	int startPos;
	UFD *fileNode,*p;
	for(p=userTable[userID].user->next;p!=NULL;p=p->next)
	{
		if(!strcmp(p->file->fileName,fileName))
		{
			printf("�ļ������������ļ�ʧ��\n");
			system("pause");
			return;
		}
	}
	if(requestDist(startPos,length))   //���̷����ѯ
	{
		fileNode=(UFD *)malloc(sizeof(UFD));
		fileNode->file=(fileTable *)malloc(sizeof(fileTable));  //��һ���ز����٣���ΪfileNode�����ָ��Ҳ��Ҫ�����ַ������fileNode->fileָ������
		strcpy(fileNode->file->fileName,fileName);
		strcpy(fileNode->file->fileKind,fileKind);
		fileNode->file->maxlength=length;
		fileNode->file->strat=startPos;
		fileNode->file->openFlag=false;
		time(&rawtime);
		fileNode->file->timeinfo=localtime(&rawtime);
		fileNode->next=NULL;
		if(userTable[userID].user->next==NULL)
			userTable[userID].user->next=fileNode;
		else
		{
			p=userTable[userID].user->next;
			while(p->next) p=p->next;
			p->next=fileNode;
		}
		printf("�����ļ��ɹ�\n");
		system("pause");
	}
	else
	{
		printf("���̿ռ��������������ļ��������̿������������̿ռ����ʧ��\n");
		system("pause");
	}
}

void freeDisk(int startPostion)
{
	diskNode *p;
	for(p=diskHead;p!=NULL;p=p->next)
	{
		if(p->start==startPostion)
			break;
	}
	p->useFlag=false;
}

void delFile(char fileName[])
{
	UFD *p,*q,*temp;
	q=userTable[userID].user;
	p=q->next;
	while(p)
	{
		if(!strcmp(p->file->fileName,fileName)) break;//�ļ�������
		else 
		{
			p=p->next;
			q=q->next;
		}
	}
	if(p)
	{
		if(p->file->openFlag!=true)            //���ж��Ƿ��н��̴򿪸��ļ�������ļ�û����
		{
			temp=p;
			q->next=p->next;
			freeDisk(temp->file->strat);  //���̿ռ����
			free(temp);
			printf("�ļ�ɾ���ɹ�\n");
			system("pause");
		}
		else
		{
			printf("���ļ��ѱ����̴�,ɾ��ʧ��\n");//�ļ�����
			system("pause");
		}
	}
	else
	{
		printf("û���ҵ����ļ�,����������ļ����Ƿ���ȷ\n");//�ļ�������
		system("pause");
	}
}

void fileCat(char fileName[])
{
	int startPos,length;
	int k=0;
	UFD *p,*q;
	q=userTable[userID].user;
	for(p=q->next;p!=NULL;p=p->next)
	{
		if(!strcmp(p->file->fileName,fileName))
			break;
	}
	if(p)
	{
		startPos=p->file->strat;
		length=p->file->length;
		p->file->openFlag=true;    //�ļ��򿪱��
		printf("------------------------------------\n");
		for(int i=startPos;k<length;i++,k++)
		{
			if(i%50==0) printf("\n");  //һ�д���50���ַ�����
			printf("%c",disk[i]);
		}
		printf("%s�ѱ�read���̴�,����close�����ر�\n",p->file->fileName);
		system("pause");
	}
	else
	{
		printf("û���ҵ����ļ�,����������ļ����Ƿ���ȷ\n");
		system("pause");
	}
}

void fileWrite(char fileName[])
{
	UFD *p,*q;
	q=userTable[userID].user;
	int i,k,startPos;
	for(p=q->next;p!=NULL;p=p->next)
	{
		if(!strcmp(p->file->fileName,fileName))
			break;
	}
	if(p)
	{
		if(!strcmp(p->file->fileKind,"r"))      //�ж��ļ�����
		{
			printf("���ļ���ֻ���ļ�,д��ʧ��\n");
			system("pause");
			return;
		}
		char str[500];
		printf("�����ļ�����:\n");
		gets(str);
		startPos=p->file->strat;
		p->file->openFlag=true;    //�ļ��򿪱��
		p->file->length=strlen(str);
		if(p->file->length>p->file->maxlength)
		{
			printf("д���ַ������ȴ��ڸ��ļ����ܳ���,д��ʧ��\n");
			system("pause");
			return;
		}
		for(i=startPos,k=0;k<(int)strlen(str);i++,k++)
			disk[i]=str[k];
		printf("�ļ�д��ɹ�,����close������ļ��ر�\n");
		system("pause");
	}
	else
	{
		printf("û���ҵ����ļ�,����������ļ����Ƿ���ȷ\n");
		system("pause");
	}
}

void fileFine(char fileName[])
{
	UFD *p,*q;
	q=userTable[userID].user;
	for(p=q->next;p!=NULL;p=p->next)
	{
		if(!strcmp(p->file->fileName,fileName))
			break;
	}
	if(p)
	{
		printf("-------------------------------------------\n");
		printf("�ļ�����%s\n",p->file->fileName);
		printf("�ļ����ȣ�%d\n",p->file->maxlength);
		printf("�ļ��ڴ洢�ռ����ʼ��ַ��%d\n",p->file->strat);
		printf("�ļ����ͣ�%s\n",p->file->fileKind);
		system("pause");
	}
	else
	{
		printf("û���ҵ����ļ�,����������ļ����Ƿ���ȷ\n");
		system("pause");
	}
}

void fileDir(char userName[])
{
	UFD *p;
	int i,k;
	for(i=0;i<MaxUser;i++)
	{
		if(!strcmp(userTable[i].userName,userName))
		{
			k=i;break;
		}
	}
	if(i==MaxUser)
	{
		printf("û���ҵ����û������������û����Ƿ���ȷ\n");
		system("pause");
		return;
	}
	else
	{
		p=userTable[k].user->next;
		printf("----------------------------------------------------------\n");
		printf("�ļ���  �ļ�����  �ļ��ڴ��̵���ʼ��ַ  �ļ�����  ����ʱ��\n");
		for(;p!=NULL;p=p->next)
			printf("%s        %d              %d            %s   %s",p->file->fileName,
			p->file->maxlength,p->file->strat,p->file->fileKind,asctime(p->file->timeinfo));
	
		system("pause");
	}
}

void diskShow()
{
	diskNode *p;
	int i=0,unusedDisk=0;
	printf("-------------------------------------------------------------------\n");
	printf("  �̿��    ��ʼ��ַ       ����(bit)   �Ƿ��ѱ�ʹ��\n");
	for(p=diskHead;p!=NULL;p=p->next,i++)
	{
		if(p->useFlag==false) unusedDisk+=p->maxlength;
		printf("   %d         %d              %d          %d     \n",i,p->start,p->maxlength,p->useFlag);
	}
	printf("���̿ռ���������512*1024bit  ��ʹ�ã�%dbit   ĩʹ�ã�%dbit\n\n",MaxDisk-unusedDisk,
		unusedDisk);
	system("pause");
}

void fileClose(char fileName[])
{
	UFD *p,*q;
	q=userTable[userID].user;
	for(p=q->next;p!=NULL;p=p->next)
	{
		if(!strcmp(p->file->fileName,fileName))
			break;
	}
	if(p) 
	{
		p->file->openFlag=false;
		printf("%s�ļ��ѹر�\n",p->file->fileName);
		system("pause");
	}
	else
	{
		printf("û���ҵ����ļ�,����������ļ����Ƿ���ȷ\n");
		system("pause");
	}
}

 void clrscr()/*����*/
{
	system("cls");
} 

int main()
{
	char order[commandAmount][10];
	strcpy(order[0],"create");
	strcpy(order[1],"del");
	strcpy(order[2],"cat");
	strcpy(order[3],"write");
	strcpy(order[4],"read");
	strcpy(order[5],"dir");
	strcpy(order[6],"close");
	strcpy(order[7],"return");
	strcpy(order[8],"exit");
	strcpy(order[9],"df");
	char command[50],command_str1[10],command_str2[10],command_str3[5],command_str4[3];
	int i,k,j;
	int length;
	initDisk();                     //��ʼ������
	for(i=0;i<MaxUser;i++)          //��ʼ���û�UFDĿ¼�ļ���ͷָ��
	{
		userTable[i].user=(UFD *)malloc(sizeof(UFD));
		userTable[i].user->next=NULL;
	}
	while(1)
	{
		cout<<" 1�������û�\n";
		cout<<" 2���û���¼\n";
		cout<<"\n\n";
		cout<<"��ѡ��:>";
		int choice;
		scanf("%d",&choice);
		if(choice==1) userCreate();
		else if(choice==2) userID=login();
		else printf("������Ϣ������������\n");
			clrscr();
		while(userID!=-1)
		{   
			clrscr();
			fflush(stdin);
			cout<<"����������������������������������������������������������������������\n";
			cout<<" create �����ļ�      | create fileName filesize rw;\n";
			cout<<" del    ɾ���ļ�      | del fileName;      \n";
			cout<<" cat    �鿴�ļ�����  | cat filename\n";
			cout<<" write  д��          | write filename\n";
			cout<<" read   ���ļ�        | read filename\n";
			cout<<" dir    ��ʾ�ļ�      | dir username\n";
			cout<<" close  �ر��ļ�      | close filename\n";
			cout<<" return �˳��û�      |\n";
			cout<<" exit   �˳�����      |\n";
			cout<<"����������������������������������������������������������������������\n";
			cout<<"����������:>";
			gets(command);
			int select;
			for(i=0;command[i]!=' '&&command[i]!='\0';i++)              //command_str1�ַ����洢����Ĳ�������
				command_str1[i]=command[i];
			k=i;
			command_str1[k]='\0';
			for(i=0;i<commandAmount;i++)
			{
				if(!strcmp(command_str1,order[i]))
				{
					select=i;
					break;
				}
			}
			if(i==commandAmount) 
			{
				cout<<"�����������������������\n";
				continue;
			}
			for(i=k+1,k=0;command[i]!=' '&&command[i]!='\0';i++,k++)    //commmand_str2�ַ����洢�ļ������û���
				command_str2[k]=command[i];
			command_str2[k]='\0';
			k=i;
			switch(select)
			{
			case 0:for(i=k+1,k=0;command[i]!=' ';i++,k++)
					   command_str3[k]=command[i];
				command_str3[k]='\0';
				k=i;
				j=1;
				length=0;                                         //��ʼ���ļ�����
				for(i=strlen(command_str3)-1;i>=0;i--)             //���ַ���ת��Ϊʮ����
				{
					length+=(command_str3[i]-48)*j;
					j*=10;
				}
				for(i=k+1,k=0;command[i]!=' '&&command[i]!='\0';i++,k++)
					command_str4[k]=command[i];
				command_str4[k]='\0';
				createFile(command_str2,length,command_str4);break;
			case 1:delFile(command_str2);break;
			case 2:fileCat(command_str2);break;
			case 3:
				fileWrite(command_str2);break;
			case 4:fileFine(command_str2);break;
			case 5:fileDir(command_str2);break;
			case 6:fileClose(command_str2);break;
			case 7:UFD *p;
				for(p=userTable[userID].user->next;p!=NULL;p=p->next)  //�˳��û�֮ǰ�ر����д���ļ�
					if(p->file->openFlag)
						p->file->openFlag=false;
				system("cls");
				userID=-1;break;
			case 8:exit(0);break;
			case 9:diskShow();break;
			}
		}
	}
	return 0;
}