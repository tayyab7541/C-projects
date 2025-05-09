#include<iostream>
using namespace std;
int main()
{
	int a=9;
	int b=5;
	int * const ptr=&b;
	cout<<"value in pointer is = "<<*ptr<<endl;
	*ptr=9;
	cout<<"value in pointer is now = "<<*ptr<<endl;
	//ptr=&a; this is compile time errror because we cannot chenge address of pointer
	return 0;
}