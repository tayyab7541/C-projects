#include<iostream>
using namespace std;
class rectangle 
{
    protected:
    double length,width;
    public:
    rectangle(double l,double w): length(l),width(w){}
    double area()
    {
        return length*width;
    }
};
class box:public rectangle
{
    protected:
    double depth;
    public:
    box(double l,double w,double d):rectangle(l,w),depth(d){}
    double volume()
    {
        return length*width*depth;
    }
    double area()
    {
        return 2*(length*width+length*depth+width*depth);
    }
};
int main()
{
    box b(4.5,5.5,7.0);
    cout<<"Area of rectangle is = "<<b.rectangle::area()<<endl;
    cout<<"Volume of box = "<<b.volume()<<endl;
    cout<<"Area of box = "<<b.area()<<endl;
    return 0;
}