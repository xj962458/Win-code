#include <iostream>
using namespace std;
inline int sum(int a,int b){ return a+b;}
inline double sum(double a,double b,double c){return a+b+c;}
int main(){
  int x,y,ans;
  cin>>x>>y;
  ans=sum(x,y);
  cout<<x<<" "<<y<<"  "<<ans<<endl;
  cout<<sum(3.1,2.5,8)<<endl;
  return 0;
}