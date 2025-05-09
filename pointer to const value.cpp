#include<iostream>
using namespace std;
void show(int x)
{
	cout<<"value at x = "<<x;
}
int main()
{
	int a=9;
	int b=5;
	const int *ptr;
	ptr=&a;
	show(*ptr);
	//*ptr=5; we cannot change value at the address but change address
	cout<<endl;
	ptr=&b;
	show(*ptr); //this is correct we chenged address here
}