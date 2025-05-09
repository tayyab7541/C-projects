#include<iostream>
using namespace std;
class a
{
    public:
    virtual void fun()=0;
    virtual void fun1()=0;

};
class b : public a
{
    public:
    void fun()
    {
        cout<<"this is first virtual function \n";
    }
    void fun1()
    {
        cout<<"this is second virtual function \n ";
    }

};
int main()
{
    a *p;
    b abc;
    p=&abc;
    p->fun();
    p->fun1();
    return 0;
}