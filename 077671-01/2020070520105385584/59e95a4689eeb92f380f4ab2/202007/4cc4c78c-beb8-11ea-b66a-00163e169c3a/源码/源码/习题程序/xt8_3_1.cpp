//����1 xt8_3_1.cpp 
#include <iostream>
#include <fstream>
using namespace std;
int main()
{
	int count=0;
   	ifstream infile("file.txt");//�����뷽ʽ���ļ�file.txt

	if (!infile)
	{
		cout<<"File cannot be opened��"<<endl;
		return 0;
    }
	while(!infile.eof())//���ļ�file.txt�ж�������
	{
		infile.get();
		count=count+1;
	}
    cout<<"�ļ��У�"<<count<<"���ַ�"<<endl;
    infile.close();
	return 0;
}	


