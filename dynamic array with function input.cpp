#include<iostream>
using namespace std;
void fun(int ar[],int size);
int main()
{
	int *p,s;
	cout<<"enter size of array = ";
	cin>>s;
	p=new int[s];
	fun(p,s);
	delete [] p;
	return 0;
}
void fun(int ar[],int size)
{
	int i;
	for(i=0;i<size;i++)
	{
		cout<<"enter value = ";
		cin>>ar[i];
	}
}