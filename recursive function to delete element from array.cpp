#include<iostream>
using namespace std;
void fun(int ar[],int &size,int num,int i,int j)
{
	if(i==size)
	{
		return ;
	}
	if(ar[i]==num)
	{
		for(j=i;j<size-1;j++)
		{
			ar[j]=ar[j+1];
		}
		size--;
	}
	fun(ar,size,num,i+1,j);
}
int main()
{
	int i,s,*ar,num;
	cout<<"enter size of array = ";
	cin>>s;
	ar=new int [s];
	for(i=0;i<s;i++)
	{
		cout<<"enter "<<i+1<<" value = ";
		cin>>ar[i];
		
	}
	cout<<"enter the number to delete = ";
	cin>>num;
	fun(ar,s,num,0,0);
	cout<<"after deletion \n";
	for(i=0;i<s;i++)
	{
		cout<<ar[i]<<"\t";
	}
	delete [] ar;
	return 0;
}