//Li8_7.cpp
//������Ĵ����������ִ�, �Ƚ����������ļ���
//Ȼ�������������Ļ����ʾ������
#include <iostream>
#include <fstream>
using namespace std;
int main()
{
	char str[10];
	int i=0;
	cout<<"����һ���ַ��������9���ַ���";
	cin.get(str,10,'!');//����һ���ַ���
	ofstream outfile("f1.txt");//�������ʽ���ļ�f1.txt
	if (!outfile)
	{
		cout<<"File cannot be opened��"<<endl;
		return 0;
    }
	char c=str[i];
	while (i<cin.gcount())
	{
	if (isdigit(c))
		outfile<<c;//�����ִ������ļ�outfile
    if(isdigit(c)&&!isdigit(str[i+1]))
		outfile<<endl;
	i=i+1;
	c=str[i];
	}
	outfile<<'\0';
    outfile.close();
	ifstream infile("f1.txt");//�����뷽ʽ���ļ�f1.txt
    if (!infile)
	{
		cout<<"File cannot be opened��"<<endl;
		return 0;
    }
	cout<<"����f1.txt�ļ��е����ִ�Ϊ:"<<endl;
	while(!infile.eof())//���ļ��ж������ݣ����������Ļ�ϡ�
	{
		infile.getline(str,sizeof(str));//���ļ��ж���һ������
	    cout<<str<<endl;
	}
    infile.close();
	return 0;
}	


