//程序Li7_7.cpp
//使用函数类型参数的类模板
#include <iostream>
#include <cstdlib>
using namespace std;
template <typename AType,int size> class atype //模板类
{
    
	public:
		atype() 
		{
			int i;
			for(i=0;i<size;i++)array[i]=i;
		}
		AType &operator[] (int n);
    private:
        AType array[size];
};
template < typename AType,int size> AType &atype<AType,size>::operator[] (int n)
{
    //下标越界检查
    if(n< 0 || n>=size)
		{  cout<<"下标"<<n<<"超出范围!"<<endl; 
	       exit(1);  
		}
	return array[n];   
}
int main()
{
    // 10个元素的integer数组类，intob为该类的一个对象
	atype<int,10> intob;
	//10个元素的double数组类，doubleob为该类的一个对象
    atype<double,10> doubleob;
    int i;
    cout << "Integer 数组 : ";
    for(i=0;i<10;i++)intob[i]=i;
    for(i=0;i<10;i++)
		cout<<intob[i]<<"  ";
    cout<<endl;
    cout<<"Double 数组: ";
    for(i=0;  i<10;  i++)  
		doubleob[i]=(double)i/2;
    for(i=0;  i<10;  i++)  
		cout<<doubleob[i]  <<"  ";
    cout<<endl;
    intob[12] = 100;  // 下标越界
    return 0;
}