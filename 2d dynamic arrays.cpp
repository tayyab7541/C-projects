#include<iostream>
using namespace std;
void in(int **ar,int r,int c);
void dis(int **ar,int r,int c);
//main program
int main()
{
	int **p,r,c;
	cout<<"enter row =";
	cin>>r;
	cout<<"enter colum = ";
	cin>>c;
	p=new int*[r];
	int i;
	for(i=0;i<r;i++)
	{
	   p[i]=new int[c];
	}
	in(p,r,c);
	dis(p,r,c);
	for(i=0;i<r;i++)
	{
		delete [] p[i];
	}
	delete [] p;
}
void in(int **ar,int r,int c)
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
void dis(int **ar,int r,int c)
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