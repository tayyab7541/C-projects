#include<iostream>
using namespace std;
int bar(int y);
int foo(int x)
{
	if(x<=2)
	{
		return x;
	}
	return bar(x);
}
int bar(int y)
{
	return foo(y-1);
}
int main()
{
	cout<<"value is = "<<foo(4);
	return 0;
}
