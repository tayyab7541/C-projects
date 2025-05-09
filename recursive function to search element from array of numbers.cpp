#include<iostream>
using namespace std;
 void fun(int ar[],int n,int size,int i,int &j)
{
	if(i==size)
	{
		return ;
	}
	if(ar[i]==n)
	{
		j=i;
	}
	else
	{
	  fun(ar,n,size,i+1,j);
	}
}
//main
int main()
{
	int s,i,num,*ar,result,l;
	cout<<"enter size of array = ";
	cin>>s;
	ar=new int [s];
	for(i=0;i<s;i++)
	{
		cout<<"enter "<<i+1<<" value = ";
		cin>>ar[i];
		
	}
	cout<<"enter number to search = ";
	cin>>num;
	l=-1;
	fun(ar,num,s,0,l);
if(l!=-1)
{
		cout<<"number is found at index "<<l;
}
else 
{
	cout<<"number not found";
}
	delete [] ar;
	return 0;
	
}