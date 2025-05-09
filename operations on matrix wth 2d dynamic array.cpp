#include<iostream>
#include<cmath>
using namespace std;
void input(int **ar,int r,int c);
void dis(int **ar,int r,int c);
void rowsum(int **ar,int r,int c);
void colsum(int **ar,int r,int c);
void upertriangle(int **ar,int r,int c);
void lowertriangle(int **ar,int r,int c);
void diagsum(int **ar,int r,int c);

//main program
int main()
{
	int **ar,r,c;
	cout<<"Enter number of rows = ";
	cin>>r;
	cout<<"Enter number of colums = ";
	cin>>c;
   ar=new int *[r];
   int i;
   for(i=0;i<r;i++)
   {
   	ar[i]=new int [c];
   }
   input(ar,r,c);
   dis(ar,r,c);
   rowsum(ar,r,c);
   colsum(ar,r,c);
   upertriangle(ar,r,c);
   lowertriangle(ar,r,c);
   diagsum(ar,r,c);
   for(i=0;i<r;i++) //de_allocation of 2d array 
   {
   	delete [] ar[i];
   }
   delete [] ar;
return 0;
}

//function to input values 
void input(int **ar,int r,int c)
{
	int i,j;
	for(i=0;i<r;i++)
	{
		for(j=0;j<c;j++)
		{
			cout<<"Enter value = ";
			cin>>ar[i][j];
		}
	}
}

void dis(int **ar,int r,int c) //function to display values 
{
	int i,j;
	for(i=0;i<r;i++)
	{
		for(j=0;j<c;j++)
		{
			cout<<ar[i][j]<<"\t";
		}
		cout<<endl;
	}
}

void rowsum(int **ar,int r,int c)//function to find sum of each row
{
	int i,j,sum;
	for(i=0;i<r;i++)
	{
		sum=0;
		for(j=0;j<c;j++)
		{
			sum+=ar[i][j];
			
		}
		cout<<"sum of "<<i+1<<" row = "<<sum<<endl;
	}
}
void colsum(int **ar,int r,int c) //function to find sum of each colum individually 
{
	int i,j,sum;
	for(i=0;i<c;i++)
	{
		sum=0;
		for(j=0;j<r;j++)
		{
			sum+=ar[j][i];
		}
		cout<<"sum of "<<i+1<<" colum = "<<sum<<endl;
		
	}
}
void upertriangle(int **ar,int r,int c) //function to find sum of uper triangle elements 
{
	int i,j,sum;
	sum=0;
	if(r==c)
	{
		for(i=0;i<r;i++)
		{
			for(j=0;j<c;j++)
			{
				if(j>i)
				{
					sum+=ar[i][j];
				}
			}
		}
		cout<<"sum of upper triangle is = "<<sum<<endl;
		
	}
	else
	{
		cout<<"it is not a square matrix ";
	}
}
void lowertriangle(int **ar,int r,int c) //function to find sum of upper triangle 
{
	int i,j,sum;
	if(r==c)
	{
		sum=0;
		for(i=0;i<r;i++)
		{
			for(j=0;j<c;j++)
			{
				if(i>j)
				{
					sum+=ar[i][j];
				}
			}
		}
		cout<<"sum of lower triangle = "<<sum<<endl;
	}
	else
	{
		cout<<"it is not a square matrix ";
	}
	
}
void diagsum(int **ar,int r,int c) //function to give the sum of diagonal elements 
{
	int i,j,sum;
	if(r==c)
	{
		sum=0;
		for(i=0;i<r;i++)
		{
			for(j=0;j<c;j++)
			{
				if(i==j)
				{
					sum+=ar[i][j];
				}
			}
		}
		cout<<"sum of diagonal elements of matrix = "<<sum<<endl;
	}
	else
	{
		cout<<"it is not a square matrix so it has no diagonal elements \n";
	}
}
