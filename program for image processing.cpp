#include<iostream>
#include<cstdlib>
#include<ctime>
using namespace std;
void flip(int **arr,int r,int c);
void neg_image(int **arr,int r,int c);
void crop_image(int **arr,int &r,int &c);
void display_processed(int **arr,int r,int c);
int main()
{
	int row,colum,i,**ar,j;
	cout<<"Enter number of rows = ";
	cin>>row;
	cout<<"Enter number of colums = ";
	cin>>colum;
	ar=new int *[row];
	for(i=0;i<row;i++)
	{
		ar[i]=new int [colum];
	}
	srand(time(0));
	for(i=0;i<row;i++)
	{
		for(j=0;j<colum;j++)
		{
			ar[i][j]=rand()%255;
		}
	}
	
	cout<<"orignal image \n\n";
	for(i=0;i<row;i++)
	{
		for(j=0;j<colum;j++)
		{
			cout<<ar[i][j]<<"\t";
		}
		cout<<endl;
	}
	bool found=1;
	int num;
	do
	{
		cout<<"\n Main menue \n 1:To flip image \n 2:To see negetive of image \n 3:To crop image \n 4:To display image \n 5:To exit main program\n \n ";
		cout<<"choose option = ";
		cin>>num;
		if(num==1)
		{
			flip(ar,row,colum);
		}
		 else if(num==2)
		{
			neg_image(ar,row,colum);
		}
		else if(num==3)
		{
			crop_image(ar,row,colum);
		}
		else if(num==4)
		{
			display_processed(ar,row,colum);
		}
		else if(num==5)
		{
			found=false;
		}
		else 
		{
			cout<<"\n please give correct input \n";
		}
	}while(found);
	for(i=0;i<row;i++)
	{
		delete [] ar[i];
	}
	delete [] ar;
	

}

void flip(int **arr,int r,int c)
{
	int i,j,swap;
	for(i=0;i<r-1;i++)
	{
		for(j=0;j<c;j++)
		{
			swap=arr[i][j];
			arr[i][j]=arr[i+1][j];
			arr[i+1][j]=swap;
		}
	}
	display_processed(arr,r,c);
}
void neg_image(int **arr,int r,int c)
{
	int i,j,**arr1;
	arr1=new int *[r];
	for(i=0;i<r;i++)
	{
		arr1[i]=new int [c];
	}

	for(i=0;i<r;i++)
	{
		for(j=0;j<c;j++)
		{
			arr1[i][j]=255-arr[i][j];
		}
	}
	arr=NULL;
	arr=arr1;
	display_processed(arr,r,c);

}
void crop_image(int **arr,int &r,int &c)
{
	int nr,nc,i,j,**arr1;
	cout<<"enter new number of rows = ";
	cin>>nr;
	cout<<"Enter new number of colums = ";
	cin>>nc;
	if(nr>=0&&nr<=r&&nc>=0&&nc<=c)
	{
		arr1=new int *[nr];
		for(i=0;i<nr;i++)
		{
			arr1[i]=new int [nc];
		}
		for(i=0;i<nr;i++)
		{
			for(j=0;j<nc;j++)
			{
				arr1[i][j]=arr[i][j];
			}
		}
		arr=NULL;
		arr=arr1;
		c=nc;
		r=nr;
		display_processed(arr,r,c);
		
	}
	else
	{
		cout<<"\n you have given incorrect diemenssions of image \n";
	}
}

void display_processed(int **arr,int r,int c)
{
	int i,j;
	cout<<"\n processed image \n \n ";
	for(i=0;i<r;i++)
	{
		for(j=0;j<c;j++)
		{
			cout<<arr[i][j]<<"\t";
		}
		cout<<endl;
	}
}