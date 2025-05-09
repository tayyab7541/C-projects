#include<iostream>
using namespace std;
void fun(int ar[],int ar1[],int size,int i)
{
	if(i==size)
	{
      return ;
	}
		ar1[i]=ar[i];
	
	fun(ar,ar1,size,i+1);
}
//main
int main()
{
	int i,s,*p,*p1;
	cout<<"enter size of array = ";
	cin>>s;
	p=new int [s];
	p1=new int [s];
	for(i=0;i<s;i++)
	{
		cout<<"enter "<<i+1<<" value =";
		cin>>p[i];
		
	}
	fun(p,p1,s,0);
	cout<<"orignal array \n";
	for(i=0;i<s;i++)
	{
		cout<<p[i]<<"\t";
	}
	cout<<"\n copied array \n";
	for(i=0;i<s;i++)
	{
		cout<<p1[i]<<"\t";
	}
	
   delete [] p;
   delete [] p1;
   return 0;	
}