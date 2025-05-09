#include<iostream>
#include<ctime>
using namespace std;
int main()
{
	int r,c,**ar,**s,i,j;
	cout<<"enter the number of rows = ";
	cin>>r;
	cout<<"enter the number of colums = ";
	cin>>c;
	srand(time(0));
	ar=new int *[r];
	s=new int *[r];
	for(i=0;i<r;i++)
	{
		ar[i]=new int [c];
		s[i]=new int[c];
	}
	for(i=0;i<r;i++)
	{
		for(j=0;j<c;j++)
		{
			ar[i][j]=rand()%256;
		}
	}
	cout<<"orignal image \n \n  ";
	for(i=0;i<r;i++)
	{
		for(j=0;j<c;j++)
		{
		   cout<<ar[i][j]<<"\t";
		}
		cout<<endl;
	}
	for(i=0;i<r-1;i++)
	{
		for(j=0;j<c;j++)
		{
			s[i][j]=ar[i][j];
			ar[i][j]=ar[i+1][j];
			ar[i+1][j]=s[i][j];
		}
	}
	cout<<"flipped image is \n \n";
	for(i=0;i<r;i++)
	{
		for(j=0;j<c;j++)
		{
			cout<<ar[i][j]<<"\t";
		}
		cout<<endl;
	}
	int nr,nc;
	cout<<"enter the number of rows again = ";
	cin>>nr;
	cout<<"enter the number of colums again = ";
	cin>>nc;
	if(nr<=r&&nc<=c)
	{
	for(i=0;i<nr;i++)
	{
		for(j=0;j<nc;j++)
		{
			s[i][j]=ar[i][j];
		}
	}
	cout<<"resized image is \n\n ";
	for(i=0;i<nr;i++)
	{
		for(j=0;j<nc;j++)
		{
			cout<<s[i][j]<<"\t";
		}
		cout<<endl;
	}
}
else 
{
	cout<<"you enterd incorrect number of rows and colums ";
}
	
}