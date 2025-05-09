#include<iostream>
using namespace std;
void s(int *p,int sze);

//main program
int main()
{
	int size;
	cout<<"please enter the size of array = ";
	cin>>size;
	int *ar;
	ar=new int[size];
	int i;
	for(i=0;i<size;i++)
	{
		cout<<"please value "<<i+1<<" = ";
		cin>>ar[i];
	}
	s(ar,size);
	
}
//function
void s(int *p,int sze)
{
	int i,j;
	int n;
	j=0;
	cout<<"enter the number you want to search = ";
	cin>>n;
	for(i=0;i<sze;i++)
	{
	if(p[i]==n)
	{
		j=1;
		}	
	}
	
	if(j)
	{
		cout<<"number is found ";
	}
	else
	{
		cout<<"not found ";
	}
}