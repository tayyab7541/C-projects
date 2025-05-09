#include<iostream>
using namespace std;
class a
{
	public :
		virtual void fun() =0;
		// {
		// 	cout<<"This is a pure virtual function of base class \n ";
		// }
};
class b:public a
{
	void fun()
	{
		cout<<"This is a pure virtual function of base class \n ";
	}
};
int main()
{
	a *p;
	b ab;
	p=&ab;
	p->fun();
	return 0;
}