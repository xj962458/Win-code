//����Li2_4.cpp
//���õ�˵�����÷�
#include <iostream>
using namespace std;
int main()
{
  int num(5);
  int &refv=num;
  cout<<"num="<<num <<','<<"refv="<<refv<<endl;
  num+=5;
  cout<<"num="<<num <<','<<"refv="<<refv<<endl;
  refv+=8;
  cout<<"num="<<num <<','<<"refv="<<refv<<endl;
  return 0;
 }
