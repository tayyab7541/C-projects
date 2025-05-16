#include<iostream>
using namespace std;
class shape 
{
    public:
    virtual void show()=0;
};
class twod:public virtual shape
{
    public:
    void show()
    {
        cout<<"This is pure virtual function of second class \n";
    }
};
class third:public virtual shape
{
    public:
    void show()
    {
        cout<<"This is pure virtual function of third class \n";
    }
};
class hybrid:public twod,public third
{
    public:
    void show()
    {
        cout<<"This is pure virtual function of Last class \n";
    }
};

int main()
{
    shape *p; // point to base class
    hybrid h;
    p=&h;
    p->show();
    return 0;
}