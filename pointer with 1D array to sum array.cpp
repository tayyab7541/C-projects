#include<iostream>
using namespace std;
int main()
{
	int size,*ar,i,total;
	total=0;
	cout<<"please enter the size of array = ";
	cin>>size;
	ar=new int [size];
	for(i=0;i<size;i++)
	{
		cout<<"enter value "<<i+1<<" = ";
		cin>>ar[i];
	}
	for(i=0;i<size;i++)
	{
		total+=ar[i];
		
	}
	for(i=0;i<size;i++)
	{
		cout<<ar[i]<<"\t";
	}
	cout<<total;
}