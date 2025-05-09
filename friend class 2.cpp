#include<iostream>
#include<cmath>
using namespace std;
class point
{
    private:
    int x,y;
    public:
    void input()
    {
        cout<<"enter x = ";
        cin>>x;
        cout<<"enter y = ";
        cin>>y;

    }
    friend class b;
};
class b
{
    point p;//creating object of first class
    public:
    void distance()
    {
        p.input(); //calling function to input values 
        cout<<"Distance between these points is = "<<sqrt(p.x*p.x-p.y*p.y);
    }
};

int main()
{
    b obj;
    obj.distance();
    return 0;
}