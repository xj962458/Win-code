#include <iostream>
using namespace std;
class Person{
	char  name[20];
	int age;
	public:
		int score;
		void setAge(int a){age=a;}
		int getAge();
		void setScore(int s){score=s+10;}
		int  getScore(){return score;}
};
int Person::getAge(){return age;}
int main()
{
	Person p1,*pt,&rp=p1;
	p1.setAge(20);
	p1.score=90; p1.setScore(70);
	pt=&p1;
	cout<<rp.getScore()<<endl;
	return 0;
 }