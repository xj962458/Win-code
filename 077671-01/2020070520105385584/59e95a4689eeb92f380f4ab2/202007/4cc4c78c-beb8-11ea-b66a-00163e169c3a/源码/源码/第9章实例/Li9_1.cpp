//Li9_1.cpp
//ʾ����ʹ���쳣�������������
#include < iostream >
using namespace std;
int dive(int x,int y);//�Զ����������
int main( )
{
	cout<<"5/2 ="<<dive(5,2)<<endl;
    cout<<"8/0 ="<<dive(8,0)<<endl;
    cout<<"7/1 ="<<dive(7,1)<<endl;
	cout<<"End of program."<<endl;
	return 0;
}
int dive(int x,int y)
{
	if(y==0)//��ĸΪ0
    {
		cout <<"Except of deviding zero."<<endl ; 
		exit(1);//�˳�����
    }
	else
	    return x/y;
}
