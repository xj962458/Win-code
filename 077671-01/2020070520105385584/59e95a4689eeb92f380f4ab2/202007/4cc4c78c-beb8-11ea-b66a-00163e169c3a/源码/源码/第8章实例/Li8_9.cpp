//Li8_9.cpp
//�ö������ļ��������ѧ����Ϣ
#include<iostream>    
#include<fstream>    //�ļ���ͷ�ļ�
#include<string>
using namespace std;  
class student
{
	private:
		long num;
	    string  name;
		float score;
    public:
		void setnum() //����ѧ��
		{
			cin>>num;
		}
        void setname()        //��������
		{
			cin>>name;
		}
       void setscore() //����ɼ�
		{
			cin>>score;
		}
        long getnum()// �õ�ѧ��
		{
         return num;
		}
        string getname()//�õ�����
		{
         return name;
		}
        float getscore()//�õ��ɼ�
		{
         return score;
		}
};
int main()
{
	fstream file;
    file.open("student.dat",ios::in|ios::out|ios::binary);
	if(!file)
	{
		cout<<"File student.dat cannot be opened."<<endl;
		return 0;
    }
    student stud[100],s;
    cout<<"��������3��ѧ������Ϣ:"<<endl;
	cout<<"ѧ��\t����\t�ɼ�"<<endl;
    for(int i=0;i<3;i++)
	{
		 stud[i].setnum();         //����ѧ��
         stud[i].setname();        //��������
         stud[i].setscore();       //����ɼ�
         file.write((char*)&stud[i],sizeof(student));
	}
    cout<<"���ڵ�2��ѧ�����������ѧ������Ϣ:"<<endl;
    cout<<"ѧ��\t����\t�ɼ�"<<endl;	
	file.seekp(sizeof(student)*2);
    for(i=3;i<5;i++)
	{
		 stud[i].setnum();          //����ѧ��
         stud[i].setname();         //��������
         stud[i].setscore();        //����ɼ�
         file.write((char*)&stud[i],sizeof(student));
	}
    cout<<"�����2��4��ѧ������Ϣ:"<<endl;
    cout<<"ѧ��\t����\t�ɼ�"<<endl;
	file.seekg(sizeof(student)*1);//��ָ���Ƶ���2����¼
    file.read((char*)&s,sizeof(student));
    cout<<s.getnum()<<"\t";
    cout<<s.getname()<<"\t";
    cout<<s.getscore()<<endl;
    file.seekg(sizeof(student)*3);//��ָ���Ƶ���4����¼
	file.read((char*)&s,sizeof(student));
    cout<<s.getnum()<<"\t";
    cout<<s.getname()<<"\t";
    cout<<s.getscore()<<endl;
    file.close();           //�ر��ļ�
	return 0;
}