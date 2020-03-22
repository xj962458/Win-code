#include<iostream>
using namespace std;
class Rectangle
{
    private:
        float width,height;
    public:
        void SetRectanggle(float newW,float NewH)
        {
            width=newW;
            height=NewH;
        }
        float Area()
        {
            return width*height;
        }
};

Rectangle &compare(Rectangle &r1,Rectangle &r2)
{
    if(r1.Area()>r2.Area())
        return r1;
    else
        return r2;
}

int main()
{
    Rectangle rect1,rect2,rect3;
    rect1.SetRectanggle(12,21);
    rect2.SetRectanggle(21,14);
    rect3.SetRectanggle(21,12);
    Rectangle &maxR=compare(rect3,compare(rect1,rect2));
    cout<<"The larger rectangle has area:"<<maxR.Area()<<endl;
    return 0;
}