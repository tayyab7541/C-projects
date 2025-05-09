#include<iostream>
using namespace std;
void fun(int x=0,int y=10,int z=9);
int main()
{
	int a,b,c;
	a=5;
	b=10;
	c=0;
	fun(a,c);
	return 0;
	
}
void fun(int x,int y,int z)
{
	cout<<(x+y+z);
}