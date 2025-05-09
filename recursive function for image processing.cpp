#include<iostream>
#include<cstdlib>
#include<ctime>
using namespace std;
void input(int **ar,int r,int c,int i,int j);
void display(int **ar,int r,int c,int i,int j);
void flip(int **ar,int r,int c,int i,int j,int s);
void neg_image(int **ar,int r,int c,int i,int j);
void crop(int **ar,int **arr,int r, int c,int i, int j);
//main program 
int main()
{
	int row,j,col,**ar,i,num;
	bool found =1;
	cout<<"enter number of rows of img = ";
	cin>>row;
	cout<<"enter number of colum of img = ";
	cin>>col;
	ar=new int *[row];
	for(j=0;j<row;j++)
	{
		ar[j]=new int [col];
	} 
	
	input(ar,row,col,0,0);
	cout<<" \n orignal image is \n";
	display(ar,row,col,0,0);
   do
   {
	cout<<"\n Main menue \n 1:To flip image \n 2:To convert image to its negetive \n 3:To crop image \n 4:To exit program  \n Enter your choice = ";
	cin>>num;
	if(num==1)
	{
		flip(ar,row,col,0,0,0);
		cout<<"\n Fliped image \n ";
		display(ar,row,col,0,0);
	}
	else if(num==2)
	{
        neg_image(ar,row,col,0,0);
        cout<<"\n Negetive of image is \n ";
        display(ar,row,col,0,0);
	}
	else if(num==3)
	{
		int n1,n2,**n;
		cout<<"enter new number of rows = ";
		cin>>n1;
		cout<<"enter new number of colums = ";
		cin>>n2;
		n=new int *[n1];
		for(i=0;i<n1;i++)
	{
		n[i]=new int[n2];
	}

		crop(ar,n,n1,n2,0,0);
		for(i=0;i<row;i++)
		{
			delete [] ar[i];
		}
		delete[] ar;
		ar=NULL;
		ar=n;
		row=n1;
		col=n2;
		cout<<"\n croped image is \n ";
		display(ar,row,col,0,0);
	}
	else if(num==4)
	{
		found=0;
	}
    else
       {
	      cout<<"\n INvalid input try again \n ";
        }

   }while(found);


	for(i=0;i<row;i++)
	{
		delete [] ar[i];
	}
	delete [] ar;
}

void input(int **ar,int r,int c,int i,int j)
{
	if(i==r)
	{
		return ;
		
	}
	if(j==c)
	{
		input(ar,r,c,i+1,0);
		return;
	}
	ar[i][j]=rand()%255;
	input(ar,r,c,i,j+1);
}
void display(int **ar,int r,int c,int i,int j)
{
	if(i==r)
	{
		return ;
	}
	if(j==c)
	{    
	    cout<<endl;
		display(ar,r,c,i+1,0);
		return ;
	}
	cout<<ar[i][j]<<"\t";
	display(ar,r,c,i,j+1);
}

void flip(int **ar,int r,int c,int i,int j,int s)
{
	if(i==r-1)
	{
		return ;
	}
	if(j==c)
	{
		flip(ar,r,c,i+1,0,0);
		return ;
	}
	s=ar[i][j];
	ar[i][j]=ar[i+1][j];
	ar[i+1][j]=s;
	flip(ar,r,c,i,j+1,0);
}
void neg_image(int **ar,int r,int c,int i,int j)
{
	if(i==r)
	{
		return ;
	}
	if(j==c)
	{
		neg_image(ar,r,c,i+1,0);
		return ;
	}
	ar[i][j]=255-ar[i][j];
	neg_image(ar,r,c,i,j+1);
}
void crop(int **ar,int **arr,int r, int c,int i, int j)
{
	if(i==r)
	{
		return;

	}
	if(j==c)
	{
		crop(ar,arr,r,c,i+1,0);
		return;
	}
	arr[i][j]=ar[i][j];

	crop(ar,arr,r,c,i,j+1);
}