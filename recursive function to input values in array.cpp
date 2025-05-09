#include<iostream>
using namespace std;
void display(int *ar,int size,int j);
void fun(int *ar,int s,int i)
{
	if(i==s)
	{
		return ;
	}
	else
	{
		cout<<"Enter "<<i+1<<" value = ";
		cin>>ar[i];
		fun(ar,s,i+1);
	}
}
int main()
{
	int *ar,size;
	cout<<"enter the size of array = ";
	cin>>size;
	ar=new int[size];
	fun(ar,size,0);
	cout<<"Array after input \n ";
	display(ar,size,0);
//	cout<<"Array after input \n";
//	for(int i=0;i<size;i++)
//	{
//		cout<<ar[i]<<"\t";
//	}
	return 0;
}
void display(int *ar,int size,int j)
{
	if(j==size)
	{
		return ;
	}
	else
	{
		cout<<ar[j]<<"\t";
		display(ar,size,j+1);
	}
}