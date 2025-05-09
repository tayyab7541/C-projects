#include<iostream>
void add(int **m1,int **m2,int r1,int r2,int c1,int c2);
void multiply(int **m1,int **m2,int r1,int r2,int c1,int c2);
void transpose(int **m1,int **m2,int r1,int r2,int c1,int c2);
//there is no need of another display function because it will display result automatically when you will perform any 
//operation 
using namespace std;
int main()
{
	int r1,r2,c1,c2,**matrix1,**matrix2,i,j;
	cout<<"Enter number of rows for 1st matrix = ";
	cin>>r1;
	cout<<"Enter number of colums for 1st matrix = ";
	cin>>c1;
	cout<<"Enter number of rows for 2nd matrix = ";
	cin>>r2;
	cout<<"Enter number of colums for 2nd matrix = ";
	cin>>c2;
	matrix1=new int* [r1];
	matrix2=new int*[r2];
	for(i=0;i<r1;i++)
	{
		matrix1[i]=new int [c1];
	}
	for(i=0;i<r2;i++)
	{
		matrix2[i]=new int[c2];
	}
	cout<<"Enter values for 1st matrix \n";
	for(i=0;i<r1;i++)
	{
		cout<<"row number "<<i+1<<" \n ";
		for(j=0;j<c1;j++)
		{
			cout<<"colum number "<<j+1<<" enter value = ";
			cin>>matrix1[i][j];
		}
	}
	cout<<"Enter values for 2nd matrix \n ";
	for(i=0;i<r2;i++)
	{
		cout<<"row number "<<i+1<<" \n ";
		for(j=0;j<c2;j++)
		{
			cout<<"colum number "<<j+1<<" enter value = ";
			cin>>matrix2[i][j];
		}
	}
	int num;
	
	bool found=1;
	do
	{
		cout<<"\n Main menue \n 1:To add matrix \n 2:To multiply matrix \n 3:To give  transpose of matrix \n 4:To exit program \n choose option = ";
		cin>>num;
		if(num==1)
		{
			add(matrix1,matrix2,r1,r2,c1,c2);
			
		}
		else if(num==2)
		{
			multiply(matrix1,matrix2,r1,r2,c1,c2);
		}
		else if(num==3)
		{
			transpose(matrix1,matrix2,r1,r2,c1,c2);
		}
		else if(num==4)
		{
			found=false;
		}
		else
		{
			cout<<"Invalid input \n ";
		}
	}while(found);
	for(i=0;i<r1;i++)
	{
		delete [] matrix1[i];
	}	
		delete [] matrix1;
	for(i=0;i<r2;i++)
	{
		delete [] matrix2[i];
	} 
	delete [] matrix2;	
}

void add(int **m1,int **m2,int r1,int r2,int c1,int c2)
{
	int i,j,**result;
	if(r1==r2&&c1==c2)
	{
		
		result=new int *[r1];
		for(i=0;i<r1;i++)
		{
			result[i]=new int[c1];
		}
		
		for(i=0;i<r1;i++)
		{
			for(j=0;j<c1;j++)
			{
				result[i][j]=m1[i][j]+m2[i][j];
			}
		}
		
		cout<<"Result of addition of two matrix is \n ";
			for(i=0;i<r1;i++)
		{
			for(j=0;j<c1;j++)
			{
				cout<<result[i][j]<<"\t";
			}
			cout<<endl;
		}
	}
	else
	{
		cout<<"Addition is not possible because of different order of matrix both matrix \n";
	}
}
void multiply(int **m1,int **m2,int r1,int r2,int c1,int c2)
{
	int i,j,**result,k;

	if(r1==c2)
	{
		result=new int*[r1];
		for(i=0;i<r1;i++)
		{
			result[i]=new int[c2];
		}

		//for multiplication
		for(i=0;i<r1;i++)
		{
			for(j=0;j<c2;j++)
			{
				result[i][j]=0;
				for(k=0;k<c1;k++)
				{
                  result[i][j] +=m1[i][k]*m2[k][j];
				}
			}
		}

		for(i=0;i<r1;i++)
		{
			for(j=0;j<c2;j++)
			{
				cout<<result[i][j]<<"\t";
			}
			cout<<endl;
		}

		for(i=0;i<r1;i++)
		{
			delete [] result[i];
		}
		delete [] result;
	}
	else
	{
      cout<<"\n Multiplication is not possible \n";
	}
}
void transpose(int **m1,int **m2,int r1,int r2,int c1,int c2)
{
	int i,j,num,**result;
	cout<<"enter number of matrix of which transpose is needed [1 or 2]= ";
	cin>>num;
	if(num==1)
	{
		result=new int*[r1];
		for(i=0;i<r1;i++)
		{
			result[i]=new int[c1];
		}

		for(i=0;i<r1;i++)
		{
			for(j=0;j<c1;j++)
			{
				result[j][i]=m1[i][j];
			}
		}
		cout<<"Transpose of 1st matrix is \n\n ";
		for(i=0;i<c1;i++)
		{
			for(j=0;j<r1;j++)
			{
				cout<<result[i][j]<<"\t";
			}
			cout<<endl;
		}
	}
	else if(num==2)
	{
		result=new int *[r2];
		for(i=0;i<r2;i++)
		{
			result[i]=new int [c2];
		}

		for(i=0;i<r2;i++)
		{
			for(j=0;j<c2;j++)
			{
				result[j][i]=m2[i][j];
			}

		}
		cout<<"Transpose of second matrix is = \n \n";
		for(i=0;i<c2;i++)
		{
			for(j=0;j<r2;j++)
			{
				cout<<result[i][j]<<"\t";
			}
			cout<<endl;
		}
	}
else 
{
	cout<<"\n you enterd invalid number of matrix \n ";
}
}
