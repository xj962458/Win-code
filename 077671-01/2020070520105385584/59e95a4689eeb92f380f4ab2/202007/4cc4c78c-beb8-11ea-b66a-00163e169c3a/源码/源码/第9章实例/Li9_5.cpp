//Li9_5.cpp
//ʾ���쳣����㴫�ݡ�
#include<iostream>
#include<string>
using namespace std;
string e="exception";
void func( )
{
	try
        { throw e; }//����string���͵��쳣
    catch (string msg )//�����쳣��������
		{
            cout<<"func: catch "<<msg<<endl;
		    cout<<"      throw "<<msg<<"  to main"<<endl;
            throw;//�������쳣�ٴ��ݸ���һ��
		 }
     return;
}
int main( )
{ 
	try
         { func(); }//����쳣
    catch(string msg )//�����쳣��������
         { cout<<"main: catch "<<msg<<" from func"<<endl; }
	return 0;
}
	 