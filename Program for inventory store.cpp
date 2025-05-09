#include<iostream>
using namespace std;
void add(int arr[],int &size);
void remove(int arr[],int &size);
void update(int arr[],int &size);
void display(int arr[],int &size);

//main program 
int main()
{
	int size,*ar,i,num;
	bool found=1;
	cout<<"Enter number of products in store = ";
	cin>>size;
	ar=new int [size];
	for(i=0;i<size;i++)
	{
		cout<<"Enter quantity of product "<<i+1<<" = ";
		cin>>ar[i];
	}
	
do
	{
	cout<<"Main menue  \n 1:To add product \n 2:To remove product \n 3:To ";	
	cout<<"update quatity of a product \n 4:To display current inventory\n 5:To exit program  \n \n";
	cout<<"\n \n choose option  = ";
	cin>>num;
	if(num==1)
	{
		add(ar,size);
	}
	 else if(num==2)
	{
		remove(ar,size);
	}
	else if(num==3)
	{
		update(ar,size);
	}
	else if(num==4)
	{
		display(ar,size);
	}
	else if(num==5)
	{
		found=false;
	}
	}while(found);
	
}

void add(int arr[],int &size)
{
	int np,nsize,*arr1,i;
	cout<<"How many products you want to add = ";
	cin>>np;
	nsize=np+size;
	arr1=new int[nsize];
	for(i=0;i<size;i++)
	{
		arr1[i]=arr[i];
	}
	if(np>1)
	{
		for(i=size;i<nsize;i++)
		{
			cout<<"Enter quantites of product # "<<i+1<<" = ";
			cin>>arr1[i];
		}
	}
	else if(np==1)
	{
		cout<<"enter quantities of product "<<size+1<<" = ";
		cin>>arr1[size];
	}
	
	delete [] arr;
	arr =NULL;
	size=nsize;
	arr=arr1;
	arr1=NULL;
	display(arr,size);

}

void remove(int arr[],int &size)
{
	int n,num,i,j;
	bool found=false;
	cout<<"enter number of product to be deleted = ";
	cin>>n;
	num=n-1;
	for(i=0;i<size;i++)
	{
		if(num==i)
		{
			for(j=i;j<size-1;j++)
			{
				arr[j]=arr[j+1];
			}
			
			size--;
		}

	}
	
	display(arr,size);
	
}
void update(int arr[],int &size)
{
	int n,index,i;
	cout<<"enter number of product of which quantities are to be updated = ";
	cin>>n;
	index=n-1;
	cout<<"enter number of quantities = ";
	cin>>arr[index];
	display(arr,size);
}

void display(int arr[],int &size)
{
	int i;
	cout<<"product# \t Quantites \n ";
	for(i=0;i<size;i++)
	{
		cout<<i+1<<"\t \t"<<arr[i]<<endl;
	}
}