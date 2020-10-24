//����Li3_19.cpp
//Ӧ��ʵ��
#include <iostream>  
#include <string>
using namespace std; 
class Student //��Ķ��� 
{
	int no;         //ѧ����ѧ��
	string name;    //ѧ��������
	float score;   //ѧ���ĳɼ�
	Student* per;   //��ǰ���ָ�� 
	Student* next;  //��һ�����ָ�� 
	public:  
		Student();                        //���캯��
        Student* find(int i_no);                   //����ָ��ѧ�ŵ�ѧ��
		void edit(string i_newname,float i_score); //�޸�ѧ������Ϣ
		void erase();                               //ɾ��ָ��ѧ�ŵ�ѧ��
		int add(Student* i_newStudent);           //����ѧ��
		int getno();                                //���ѧ����ѧ��
		string getname();                           //���ѧ��������
        float getscore();                          //���ѧ���ĳɼ�
		static int maxno;
};  
Student::Student()                         
{
	score=0.0;
	per=NULL;                     
	next=NULL;                   
}
Student* Student::find(int i_no)  
{  
	if(i_no==no)  
		return this;  
	if(next!=NULL)  
		return next->find(i_no); 
	return NULL;  
}  
void Student::edit(string i_name,float i_score)  
{ 
	if(i_name=="")  
		return ;  
	name=i_name; 
	score=i_score;
}  
void Student::erase()  
{ 
	if(no<0)  
		return ; 
	if(per!=NULL) 
		per->next=next;  
	if(next!=NULL)  
		next->per=per;  
	next=NULL;  
	per=NULL;  
}  
int Student::add(Student* i_newStudent)  
{ 
	int no=maxno+1;  
	while(true)
	{ 
		if(NULL==find(no)) 
			break;
		no=no+1;
	}  
	Student* tmp=this;  
	while(true){
		if(tmp->next==NULL)  
			break;  
		tmp=tmp->next;  
		}  
	tmp->next=i_newStudent;  
	i_newStudent->next=NULL;  
	i_newStudent->per=tmp;  
	i_newStudent->no=no;  
	return no;  
}
int Student::getno(){return no;}
string Student::getname(){return name;}
float Student::getscore(){return score;} 
int Student::maxno=1000;
int main()  
{
	Student* Studentroot=new Student();
	string input1;
	float input2;
	Student* tmp=NULL; 
	while(true){ 
		cout<<"����ָ�����(F),����(A),�༭(E),ɾ��(D),�˳�(Q)"<<endl; 
		cin>>input1; 
		if(("F"==input1)||("f"==input1)) 
		{ 
			cout<<"����ѧ��:"; 
			int no=-1; 
			cin>>no;
			tmp=Studentroot->find(no);
			if(tmp==NULL) 
			{ 
				cout<<"û�ҵ�"<<endl; 
				continue; 
			}  
			cout<<"ѧ��:"<<tmp->getno(); 
			cout<<"  ����:";  
			string name;  
			if((name=tmp->getname())!="") 
				cout<<name;  
			else  
				cout<<"δ����"<<endl;  
			cout<<" �ɼ���"<<tmp->getscore()<<endl;
		} 
		else if((input1=="A")||(input1=="a")) 
		{ 
			cout<<"�����������ɼ�: ";  
			cin>>input1>>input2;;  
			tmp=new Student();  
			tmp->edit(input1,input2); 
			cout<<"ѧ��: "<<Studentroot->add(tmp)<<endl; 
		}  
		else if((input1=="E")||(input1=="e"))
		{  
			cout<<"����ѧ��:"; 
			int no=0; 
			cin>>no;  
			tmp=Studentroot->find(no);  
			if(tmp==NULL)  
				{ 
				cout<<"�պ�"<<endl; 
				continue;  
				}  
			cout<<"������,�³ɼ�: "; 
			cin>>input1>>input2;  
			tmp->edit(input1,input2);  
			cout<<"���ĳɹ�."<<endl; 
		}  
		else if((input1=="D")||(input1=="d")) 
		{ 
			cout<<"����ѧ��:"; 
			int no=0; 
			cin>>no; 
			tmp=Studentroot->find(no); 
			tmp->erase();
			cout<<"�ѳɹ�ɾ��"<<endl;
			delete tmp;
		} 
		else if((input1=="Q")||(input1=="q"))
		{  
			break;  
		}
		    else 
			{ 
				cout<<"��������"<<endl; 
			}  
		}  
	delete Studentroot; 
	return 0;
}  
