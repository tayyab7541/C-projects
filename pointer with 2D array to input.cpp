#include<iostream>
using namespace std;
int main()
{
	int row,colum,**ar;
	cout<<"please enter number of rows = ";
	cin>>row;
	cout<<"please enter number of colums = ";
	cin>>colum;
	ar=new int *[row];
	int i,j;
	for(i=0;i<row;i++)
	{
		ar[i]=new int[colum];
		
	}
	cout<<"enter values in 2d array = \n";
	for(i=0;i<row;i++)
	{
		cout<<"row number "<<i+1<<" = ";
		for(j=0;j<colum;j++)
		{   
		cout<<"\n colum number "<<j+1<<" = ";
			cin>>ar[i][j];
		}
	}
	for(i=0;i<row;i++)
	{
		for(j=0;j<colum;j++)
		{
			cout<<ar[i][j]<<"\t";
		}
		cout<<endl;
	}
}