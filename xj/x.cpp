#include<iostream>
#include<stdlib.h>
#include<string>
#define N 10
using namespace std;

typedef struct student
{
    string name;
    int age;
    float score;
}STU;

typedef struct link{
    STU s[N];
    int length;
}Link;

void Input(Link &a,int n){
    for(int i=0;i<n;i++){
    cout<<"请输入姓名"<<endl;
    cin>>a.s[i].name;
    cout<<"请输入年龄"<<endl;
    cin>>a.s[i].age;
    cout<<"请输入分数"<<endl;
    cin>>a.s[i].score;
    }
    a.length=n;
}

void Print(Link a){
    cout<<"姓名\t\t年龄\t\t分数\n";
    for(int i=0;i<a.length;i++){
        cout<<a.s[i].name<<"\t\t"<<a.s[i].age<<"\t\t"<<a.s[i].score<<endl;
    }
}
int main(){
    Link a;
    Input(a,3);
    Print(a);
    

}
