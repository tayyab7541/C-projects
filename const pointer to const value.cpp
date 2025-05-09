#include<iostream>
using namespace std;
int main()
{
	int a=9;
	int b=10;
	const int *const ptr=&a;
	cout<<"const value in const pointer is = "<<*ptr<<endl;
	return 0;
}