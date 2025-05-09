#include<iostream>
using namespace std;
int fun(int a,int b)
{
	if(b==0)
	{
		return a;
	}
	else
	{
		return 1+fun(a,b-1);
	}
}
int main()
{
	int x,y;
	cout<<"enter value of x = ";
	cin>>x;
	cout<<"enter value of y = ";
	cin>>y;
	int result;
	result=fun(x,y);
	cout<<"sum of two number is = "<<result;
	return 0;
}