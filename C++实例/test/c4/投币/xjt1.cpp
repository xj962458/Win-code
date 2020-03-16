#include<iostream>
#include<ctime>
#include"flip.h"
using namespace std;
void main()
{
	cout<<"now let's begin:"<<endl;
	int k(1);
	int Hcounter(0),Tcounter(0);
	srand((unsigned)time(NULL));
	while(k<=100)
	{
		if(!Flip())
		{
			cout<<"HEADS(k="<<k<<")";
			Hcounter++;
		}
		else
		{
			cout<<"TAILS(k="<<k<<")";
			Tcounter++;
		}
		if(k%4==0)
			cout<<endl;
		k++;
	}
	cout<<"total:"<<k-1<<endl;
	cout<<"HEADS:"<<Hcounter<<endl;
	cout<<"TAILS:"<<Tcounter<<endl;
}

