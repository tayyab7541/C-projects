#include<iostream>
using namespace std;
class shape
{
    protected:
    int side;
};
class circle:public virtual shape
{
    protected:
    int radius;

};
class rectangle:public virtual shape
{
    protected:
    int length,width;

};
class areas:public circle ,public rectangle
{
    public:
    void cir_area()
    {

        cout<<"Please enter radius of circle to find area = ";
        cin>>radius;
        cout<<"Area of circle is = "<<3.14*radius*radius<<endl;
    }
    void rec_area()
    {
        cout<<"Enter length of rectangle = ";
        cin>>length;
        cout<<"Enter width of rectangle = ";
        cin>>width;
        cout<<"Area of rectangle is = "<<length*width<<endl;
    }
    void sqr_area()
    {
        cout<<"Enter side of square to find its area = ";
        cin>>side;
        cout<<"Area of square is = "<<side*side<<endl;
    }
};
int main()
{
    areas ar;
    ar.cir_area();
    ar.rec_area();
    ar.sqr_area();
    return 0;
}