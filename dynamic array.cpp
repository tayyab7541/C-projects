#include<iostream>
using namespace std;
int main()
{
	int *p,size;
	cout<<"Enter size of array = ";
	cin>>size;
	p=new int[size];
	int i;
	for(i=0;i<size;i++)
	{
		cout<<"Enter "<<i+1<<" value = ";
		cin>>p[i];
	}
	for(i=0;i<size;i++)
	{
		cout<<p[i]<<"\t";
	}
	delete [] p;
}