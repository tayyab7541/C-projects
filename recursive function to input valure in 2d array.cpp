#include<iostream>
using namespace std;
void infun(int **ar,int r,int c,int i,int j);
void disfun(int **ar,int r,int c,int i,int j);
int main()
{
	int **ar,row,col;
	cout<<"enter row size of matrix = ";
	cin>>row;
	cout<<"enter number of colums of matrix = ";
	cin>>col;
	int i;
	ar=new int*[row];
	for(i=0;i<row;i++)
	{
		ar[i]=new int[col];
		
	}
	infun(ar,row,col,0,0);
	cout<<"After input \n ";
	disfun(ar,row,col,0,0);
	return 0;
}

void infun(int **ar,int r,int c,int i,int j)
{
	if(i==r)
	{
		return ;
		
	}
	else if(j==c)
	{
		infun(ar,r,c,i+1,0);
	}
	else 
	{
		cout<<"enter value in row "<<i+1<<" and colum number "<<j+1<<" = ";
		cin>>ar[i][j];
		infun(ar,r,c,i,j+1);
	}
}

void disfun(int **ar,int r,int c,int i,int j)
{
	if(i==r)
	{
		return ;
		
	}
	else if(j==c)
	{
			cout<<endl;
		disfun(ar,r,c,i+1,0);
	
	}
	else 
	{
		cout<<ar[i][j]<<"\t";
		disfun(ar,r,c,i,j+1);
	}
}