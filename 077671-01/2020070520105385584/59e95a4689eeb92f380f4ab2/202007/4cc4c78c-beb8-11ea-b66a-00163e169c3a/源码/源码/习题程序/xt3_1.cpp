//xt3_1.cpp
#include < iostream >
using namespace std;
class Circle
{
public:
   Circle(float r){ radius = r; }
   ~ Circle( ) {}
   float area() { return 3.14 * radius * radius; }
private:
   float radius;
};
int main( )
{
float r;
cout<< "������Բ�İ뾶��";
cin >> r;
Circle  p(r);
cout << "�뾶Ϊ"<< r << "��Բ�����Ϊ��"<< p. area () << endl;
return 0;
}
