//Li8_8.cpp
//�ö������ļ�����ѧ����Ϣ
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
		void setnum() //����ѧ��num
		{
			cout<<"������ѧ����ѧ�ţ�";
            cin>>num;
		}
        void setname()        //��������name
		{
			cout<<"������ѧ����������";
            cin>>name;
		}
       void setscore() //����ѧ�ųɼ�
		{
			cout<<"������ѧ���ĳɼ���";
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
    ofstream outfile("student.dat",ios::binary);
	if(!outfile)
	{
		cout<<"File student.dat cannot be opened."<<endl;
		return 0;
    }
    student stud[100];
    char ch;
	int i=0;
    while(1)
    {
         cout<<"\n ������������¼��(y/n)? ";
         cin>>ch;
         if(ch=='n'||ch=='N')
			 break;
       	 i=i+1;
		 stud[i].setnum();       //����ѧ��
         stud[i].setname();        //��������
         stud[i].setscore();        //����ɼ�
         outfile.write((char*)&stud[i],sizeof(student));
	}
    outfile.close();           //�ر��ļ�
    cout<<"********�������********"<<endl;
    cout<<"\n ���뿴�ļ�������(y/n)? ";
    cin>>ch;
    if(ch=='Y'||ch=='y')
	{
		ifstream infile("student.dat",ios::binary);
        if(!infile)
		{
		    cout<<"File student.dat cannot be opened."<<endl;
		    return 0;
		}
		cout<<"ѧ��"<<"\t����"<<"\t�ɼ�"<<endl;
		i=1;
		infile.read((char*)&stud[i],sizeof(student));
        while(infile)
		{
		     cout<<stud[i].getnum()<<"\t";
             cout<<stud[i].getname()<<"\t";
             cout<<stud[i].getscore()<<endl;
			 i=i+1;
			 infile.read((char*)&stud[i],sizeof(student));
		}
       infile.close();           //�ر��ļ�
	}
  	return 0;
}