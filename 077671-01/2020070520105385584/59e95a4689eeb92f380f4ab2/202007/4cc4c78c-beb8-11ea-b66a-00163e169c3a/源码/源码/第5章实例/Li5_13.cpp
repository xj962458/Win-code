//Li5_13.cpp
//Ӧ��ʵ��
#include<iostream>
#include<string>
using namespace std;
class Employee                    //����
{
	protected:
		int no;                   //���
	    string name;              //����
	    float salary;             //��н�ܶ�
	    static int totalno;       //����˾Ŀǰ������ֵ
    public:
		Employee()
		{
			no=totalno++;      //�����Ա�����ΪĿǰ����ż�1
		    cout<<"ְ������:";
		    cin>>name;
		    salary=0.0;        //�ܶ��ֵΪ0
		}      

		~Employee(){}
	    virtual void pay()=0;      //������н����
	    virtual void display()=0;  //���Ա����Ϣ����
};
class Technician: public Employee   //�����࣬��ְ������Ա��
{
	private:
		float hourlyrate;          //ÿСʱ���
	    int workhours;             //���¹���ʱ��
    public:
		Technician()               //���캯��
		{
			hourlyrate=100;              //ÿСʱ��н100Ԫ
		    cout<<name<<"���¹���ʱ�䣺";
            cin>>workhours;
		}          
	void pay()                     //�����ְ������Ա��н����
	{
		salary=hourlyrate*workhours; //������н����Сʱ����
	}
	void display()                   //��ʾ��ְ������Ϣ����
	{
		cout<<"��ְ������Ա��"<<name<<",��ţ�";
		cout<<no<<"�����¹��ʣ�"<<salary<<endl;
	}

};
int Employee::totalno=10000;           //Ա����Ż���Ϊ10000
class Saleman:virtual public Employee//�����࣬����Ա��
{
	protected:
		float commrate;     		//�����۶���ȡ���İٷֱ�
	    float sales;                //�������۶�
    public:
		Saleman()                   //���캯��
		{
			commrate=0.04f;         //������ɱ���Ϊ4%
	        cout<<name<<"�������۶";
	        cin>>sales;
		}           
	void pay()                      //��������Ա��н����
	{
	    salary=sales*commrate;      //��н=�������۶�*������ɱ���
	}
	void display()                  //��ʾ����Ա��Ϣ����
	{
		cout<<"����Ա��"<<name<<",��ţ�";
		cout<<no<<",���¹��ʣ�"<<salary<<endl;
	}

};
class Manager:virtual public Employee //�����࣬������
{
	protected:
		float monthlypay; 	          //�̶���н��
public:
	Manager()                         //���캯��
	{
		monthlypay=8000;              //�̶���н8000Ԫ 
	}                                                        

	void pay()                        //���㾭����н����
	{
		salary=monthlypay;            //��н�ܶ�̶���н��
	}                                                        
	void display()                    //��ʾ������Ϣ����
	{
		cout<<"����:"<<name<<",��ţ�";
		cout<<no<<",���¹���:"<<salary<<endl;
	}
};
class Salesmanager:public Manager,public Saleman //�����࣬���۾�����
{
public:
	Salesmanager()                               //���캯��
	{
		monthlypay=5000;                         //���׹���5000Ԫ
	    commrate=0.05f;                          //������ɱ���5%
        cout<<name<<"���ܲ�����������:";
	    cin>>sales;
	}	
	
	void pay()                                   //�������۾�����н����
	{
		salary=monthlypay+commrate*sales;       //��н=�̶���н+�������
	}
	void display()                              //��ʾ���۾�����Ϣ����
	{
		cout<<"���۾���:"<<name<<",���:"<<no<<":���¹���:"<<salary<<endl;
	}

};                                                           
int  main()                                     //������
{
	Manager m1;
    Technician t1;
    Saleman s1;
    Salesmanager sm1;
	Employee* em[4]={&m1,&t1,&s1,&sm1};
    cout<<"������Ա�Ļ�����ϢΪ: "<<endl;
	for(int i=0;i<4;i++)
	{
		em[i]->pay();
        em[i]->display();
	}
	return 0;
}