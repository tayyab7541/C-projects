#include<iostream>
using namespace std;
void fun(const int &x)
{
	//x=x+9; this will give error
	cout<<"value in x = "<<x<<endl;
	
}
int main()
{
	int a=8;
	fun(a);
	cout<<"now checking value in a = "<<a<<endl;
	return 0;
}