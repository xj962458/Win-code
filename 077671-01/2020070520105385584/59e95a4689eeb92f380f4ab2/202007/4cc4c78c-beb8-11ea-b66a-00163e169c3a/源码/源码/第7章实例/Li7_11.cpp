//����Li7_11.cpp
//reverse��sort�㷨��Ӧ��
#include<iostream> 
#include<vector> //���������������vectorͷ�ļ���
#include<algorithm> //�����㷨�������㷨
using namespace std;    
bool inorder(int,int);
int main()
{
	vector<int> nums;//��������������Ϊ0
	nums.insert(nums.begin(),-99 ); // ��������һ��λ�ò���-99
    nums.insert(nums.begin(),4 );   // ��������һ��λ�ò���4
	nums.insert(nums.end(),50);      // ������ĩβ����50
	cout<<"�����ĳ�ʼ˳��Ϊ��"<<endl;
	vector<int>::iterator out;    //����һ��������out��ָ����������
	for(out=nums.begin();out!=nums.end();++out)
		cout<<*out<<" ";
	cout<<endl;
	reverse(nums.begin(),nums.end());   //���õ����㷨
	cout<<"�������ú��˳��Ϊ��"<<endl;
	for(int i=0;i<3;i++)
		cout<<nums[i]<<" " ;
	cout<<endl;
    sort(nums.begin(),nums.end());   //���õ�һ����ʽ�����㷨
	cout<<"ʹ�õ�һ����ʽ�����������˳��Ϊ��"<<endl;
	for(i=0;i<3;i++)
		cout<<nums[i]<<" " ;
    cout<<endl;
    sort(nums.begin(),nums.end(),inorder);   //���õڶ�����ʽ�����㷨
    cout<<"ʹ�õڶ�����ʽ�����������˳��Ϊ��"<<endl;
    for(out=nums.begin();out!=nums.end();++out)
		cout<<*out<<" ";
	cout<<endl;
	return 0;
}
bool inorder(int a,int b){return a>b;};









