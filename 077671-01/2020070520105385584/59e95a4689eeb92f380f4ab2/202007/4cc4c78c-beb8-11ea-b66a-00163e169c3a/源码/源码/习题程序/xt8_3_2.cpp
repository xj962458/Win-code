//����2 xt8_3_2.cpp 
#include <iostream>
#include <fstream>
using namespace std;
int main()
{
	int count=0;
	streampos start,end;
   	ifstream infile("file.txt");//�����뷽ʽ���ļ�file.txt

	if (!infile)
	{
		cout<<"File cannot be opened��"<<endl;
		return 0;
    }
	infile.seekg(0,ios::beg);
    start=infile.tellg();
    infile.seekg(0,ios::end);
    end=infile.tellg();
    cout<<"�ļ��У�"<<end-start<<"���ַ�";
    infile.close();
	return 0;
}	


