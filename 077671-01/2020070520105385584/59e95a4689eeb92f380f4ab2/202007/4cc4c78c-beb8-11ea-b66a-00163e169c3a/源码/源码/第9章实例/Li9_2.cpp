//Li9_2.cpp
//ʾ��ʹ���쳣�������������
#include < iostream >
using namespace std;
int dive(int x,int y);
#include < iostream >
using namespace std;
int dive(int x,int y);//�Զ����������
int main( )
{
	try//����쳣
	{
		cout<<"5/2 ="<<dive(5,2)<<endl;
        cout<<"8/0 ="<<dive(8,0)<<endl;
        cout<<"7/1 ="<<dive(7,1)<<endl;
	}
    catch (int)//�����쳣
    {
           cout<<"Except of deviding zero. "<<endl;
	}
    cout <<"End of program."<<endl;
	return 0;
}
int dive(int x, int y)
{
	if(y==0)//��ĸΪ0
		throw y;//�׳��쳣
    return x/y;
}
