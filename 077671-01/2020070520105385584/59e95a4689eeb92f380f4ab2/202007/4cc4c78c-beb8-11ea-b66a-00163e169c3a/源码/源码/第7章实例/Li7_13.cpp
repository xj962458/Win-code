//����Li7_13.cpp
//ʾ��STL��ʹ��
#include <iostream>
#include <list>//����˫����������ͷ�ļ�
#include <iterator>//������ͷ�ļ�������ʡ��
#include<algorithm> //STL�㷨
using namespace std;
int main()
{
	list< int >List;
	int Value=0,Option=0;
   	do{  
		cout<<endl
			<<"        ˫������˵�"<<endl
			<<" 1. �������ײ�����һ����� "<<endl
			<<" 2. ������β������һ����� "<<endl
			<<" 3. �������ײ�ɾ��һ����� "<<endl
			<<" 4. ������β��ɾ��һ����� "<<endl
			<<" 5. �������ײ���ʼ���������� "<<endl
			<<" 6. ������β����ʼ���������� "<<endl
			<<" 0. �˳� "<<endl
			<<"���ѡ��";
		cin>>Option;
		switch(Option)
		{
		case 1:
			{
			cout<<"���������ݣ�";
			cin>>Value;
			List.insert(List.begin(),Value);
			cout<<"���"<<Value<<"�ɹ����롣"<<endl;
			break;
			}
        case 2:
			{
			cout<<"���������ݣ�";
			cin>>Value;
			List.insert(List.end(),Value);
            cout<<"���"<<Value<<"�ɹ����롣"<<endl;
			break;
			}
        case 3:
			{
			if(List.begin()==List.end())
				cout<<endl<<"û���������ܽ���ɾ����";
			else
				{
				List.erase(List.begin()) ;
                cout<<endl<<"���ɾ���ɹ���"<<endl;
			    }
                break;
            } 
		case 4:
			{
				if (List.begin()==List.end())
                	cout<<endl<<"û���������ܽ���ɾ����";
			    else
                {
				List.erase(List.end());
                cout<<endl<<"���ɾ���ɹ���"<<endl;
                } 
			    break;
			}
		case 5:
			{
		    list<int>::const_iterator p1;//p1������˫������ĵ�����
            if(List.begin()==List.end())
                cout<<endl<<"û������û�н�������";
			else
			{
		    cout<<"���ײ���ʼ�������:"<<endl;
	        for(p1=List.begin();p1!=List.end();p1++)
		    cout<<*p1<<" ";   // �����������������Ԫ��
	        cout<<endl;
			}
			break;
			}
		case 6:
			{
			list<int>::reverse_iterator p2;//p2������˫������ĵ�����
			if (List.rbegin()==List.rend())
                cout<<endl<<"û������û�н�������";
			else
			{
				p2=List.rbegin();//�������ָ�����һ��Ԫ��
                cout<<"��β����ʼ�������:��"<<endl;
	            while(p2!=List.rend())//�����������ָ���һ��Ԫ��ʱ
				{
		        cout<<*p2<<" ";   // �����������������Ԫ�أ�
		        p2++;
				}
			} 
	        cout<<endl;
 			break;
			}
		}
     }while(Option!=0);
	 return 0;
}
