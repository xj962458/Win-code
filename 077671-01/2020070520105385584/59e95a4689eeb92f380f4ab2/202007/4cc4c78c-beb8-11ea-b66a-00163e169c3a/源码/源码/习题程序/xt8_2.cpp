//xt8_2.cpp
#include <iostream>
#include <fstream>
using namespace std;
int main()
{
	char str[80];
	ifstream infile("f1.txt");//�����뷽ʽ���ļ�f1.txt
    ofstream ("f2.txt");//�������ʽ���ļ�f2.txt
	if (!infile||!outfile)
	{
		cout<<"File cannot be opened��"<<endl;
		return 0;
    }
	while(!infile.eof())//���ļ�f1.txt�ж������ݣ��������f2.txt��
	{
		infile.getline(str,sizeof(str));//���ļ��ж���һ������
	   	outfile<<str<<endl;
	}
    infile.close();
    outfile.close();
	return 0;
}	


