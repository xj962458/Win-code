#include<iostream>
using namespace std;
class Point
{
    public:
        Point(int xx=0,int yy=0){X=xx;Y=yy;cout<<"Poiny constructor"<<endl;}
        Point(Point &p);
        ~Point(){cout<<"Point destructor"<<endl;}
        int GetX(){return X;}
        int GetY(){return Y;}
    private:
        int X,Y;
};
Point::Point(Point &p)
{
    X=p.X;
    Y=p.Y;
    cout<<"Point拷贝函数被调用"<<endl;
}

//类的组合
class Rectangle
{
    public:
        Rectangle(Point xp1,Point xp2,int c);
        ~Rectangle();
        int GetColor(){return color;}
        int GetWidth(){return abs(p1.GetX()-p2.GetX());}
        int GetHeight(){return abs(p1.GetY()-p2.GetY());}
    private:
        Point p1,p2;
        int color;
};

Rectangle::Rectangle(Point xp1,Point xp2,int c):p1(xp1),p2(xp2)
{
    cout<<"Rectangle构造函数被调用"<<endl;
    color=c;
}

Rectangle::~Rectangle()
{
    cout<<"析构Rectangle对象"<<endl;
}

int main()
{
    Point myp1(1,1),myp2(4,5);
    Rectangle myr(myp1,myp2,255);
    cout<<"The rectangle's color is:";
    cout<<myr.GetColor()<<endl;
    cout<<"The rectangle's width is:";
    cout<<myr.GetWidth()<<endl;
    cout<<"The rectangle's height is:";
    cout<<myr.GetHeight()<<endl;
    return 0;
}
