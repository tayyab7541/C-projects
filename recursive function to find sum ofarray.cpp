#include<iostream>
using namespace std;
int fun(int ar[],int s,int i)
{
	if(i==s-1)
	{
		return ar[i];
	}
	else 
	{
		return ar[i]+fun(ar,s,i+1);
	}
}
//main
int main()
{
	int size,*p,i,result;
	cout<<"enter size = ";
	cin>>size;
	p=new int [size];
	for(i=0;i<size;i++)
	{
		cout<<"enter"<<i+1<<"value = ";
		cin>>p[i];
		
	}
	result=fun(p,size,0);
	cout<<"sum of whole array is = "<<result;
	delete [] p;
	return 0;
}