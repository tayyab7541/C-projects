#include<iostream>
using namespace std;
int fun(int a,int b)
{
	if(b==0)
	{
		return 0;
	}
	else 
	{
		return a+fun(a,b-1);
		
	}
}
int main()
{
	int x,y,result;
	cout<<"enter num1 = ";
	cin>>x;
	cout<<"enter num2 = ";
	cin>>y;
	result=fun(x,y);
	cout<<"the product of two numbers is = "<<result;
	return 0;
}