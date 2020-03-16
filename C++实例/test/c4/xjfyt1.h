#include<stdio.h>
int max(int a,int b,int c)
{
	int t;
	t=b;
	if(a>b)
		t=a;
	if(c>t)
		t=c;
	return t;
}

int min(int a,int b,int c)
{
	int n;
	n=b;
	if(a<b)
		n=a;
	if(c<n)
		n=c;
	return n;
}
