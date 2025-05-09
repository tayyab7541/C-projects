#include<iostream>
using namespace std;
class A
{
	public:
	virtual void fun()
	{
		cout<<"This is virtual function of base class \n";
	}
};
class b:public A
{
	public:
	void fun()
	{
		cout<<"this is virtual funciton of derived class \n";
	}
};
int main()
{
	A *p;
	b c;
	p=&c;
	p->fun();
	return 0;
}
