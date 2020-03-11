#include <iostream>
#include <string.h>
using namespace std;
class Student
{
public:
    Student(char *pName = "no name");
    ~Student();
    void PrintC()
    {
        cout << "The number of students is" << count << endl;
    }

private:
    static int count; //若写成count=0，则非法
    char name[20];
};

Student::Student(char *pName) //="no name"
{
    cout << "crete one student\n";
    strncpy(name, pName, 20);
    name[19] = '\0';
    count++;
}
Student::~Student()
{
    cout << "destruct one student\n";
    count--;
    cout << "The nimber of students is" << count << endl;
}
int Student::count = 0;

int main()
{
    Student s1;
    s1.PrintC();
    Student s2;
    s2.PrintC();
    return 0;
}