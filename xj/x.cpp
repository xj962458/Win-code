#include<iostream>
#include<math.h>
using namespace std;
int main()
{
    int d,e,n,i,j,k,l;
    cin>>n;
    d=(n+1)/2;
    for(i=1;i<n;i++)
    {
        e=fabs(i-d);
        for(j=0;j<e;j++)
            cout<<" ";
        for(k=0;k<d-e;k++)
            cout<<d-e;
        for(l=0;l<3-e;l++)
            cout<<" ";
        if((3-e)!=0)
        {
            for(j=0;j<e;j++)
                cout<<" ";
            cout<<endl;
        }
    }
}
