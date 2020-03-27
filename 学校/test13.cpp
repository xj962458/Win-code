#include <iostream>
#include <string>
using namespace std;
class Person{
	string  name;
	int age;
	public:
		Person(){ name="abc";	}
		Person(string s){name=s;}
		int score;
		void setAge(int a){age=a;}
		int getAge();
		void setScore(int s){score=s+10;}
		int  getScore(){return score;}
		string getName(){return name;	}
		void setName(string n){name=n;	}
};
int Person::getAge(){return age;}
int main()
{
	Person p1,*pt,&rp=p1,p2,p3("Tom");
	p1.setAge(20);
	p1.score=90; p1.setScore(70);
	pt=&p1;
	p1.setName("John");
	cout<<rp.getScore()<<p2.getName()<<" "<<p1.getName()<<p3.getName()<<endl;
	return 0;
 }
