#include<iostream>
using namespace std;

int main()
{
	int row,colum,**ar,i,j;
	cout<<"please enter number of row = ";
	cin>>row;
	cout<<"please enter number of colum = ";
	cin>>colum;
	int sum[row];
	ar=new int *[row];
	for(i=0;i<row;i++)
	{
		ar[i]=new int [colum];
	}
	for(i=0;i<row;i++)
	{cout<<"row number = "<<i+1;
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
for(i=0;i<row;i++)
{
	sum[i]=0;
	for(j=0;j<colum;j++)
	{
		sum[i]+=ar[i][j];
	}
}
for(i=0;i<row;i++)
{
	cout<<sum[i]<<endl;
}
int usum=0;
for(i=0;i<row;i++)
{
	for(j=0;j<colum;j++)
	{
		if(i<j)
		{
			usum+=ar[i][j];
		}
	}
}
cout<<"\n sum of upper diagonle is "<<usum;
int lsum=0;
for(i=0;i<row;i++)
{
	for(j=0;j<colum;j++)
	{
		if(i>j)
		{
			lsum+=ar[i][j];
		}
	}
	
}
cout<<"\n sum of lower diagonle elements  = "<<lsum;	
}