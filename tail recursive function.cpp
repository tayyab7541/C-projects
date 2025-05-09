#include<iostream>
using namespace std;
int fun(int n,int n1,int ans)
{
	if(n==0)
	{
	return ans+=n1;
	}
	else
	{
		fun(n-1,ans+1,n1);
	}
}
int main()
{
	int num;
	cout<<"enter number = ";
	cin>>num;
	cout<<"enter second number = ";
	int num1;
	 cin>>num1;
	int answer=0;
	cout<<"The sum of number si = "<<fun(num,num1,answer);
}