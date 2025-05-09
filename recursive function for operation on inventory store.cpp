#include<iostream>
using namespace std;
void input(int *ar,int s,int i);
void add(int *ar,int *sw,int s,int i);
void remove(int *ar,int n,int &s,int i,int j);
void display(int *ar,int s,int i);
void update(int *ar,int s,int n,int i);
int main()
{
	int *ar,size,num;
	int num_of_pro,new_size,*swap;
	bool found=1;
	cout<<"Enter number of products = ";
	cin>>size;
	ar=new int [size];
	cout<<"input quantities of products \n";
	input(ar,size,0);
	do
	{
	  cout<<"Main menue \n 1:To add new product \n 2:To remove product \n 3:To display \n 4:To update inventory \n 5:To exit main program \n Enter your choice = ";
	  cin>>num;
	  if(num==1)
	  {
	  	cout<<"Enter number of products to be added = ";
	  	cin>>num_of_pro;
	  	new_size=size+num_of_pro;
		swap=new int[new_size];
		
	  	add(ar,swap,size,0);
	  	input(swap,new_size,size);
	  	delete [] ar;
	  	ar=NULL;
	  	ar=swap;
	  	size=new_size;
	  	
	   }
	   else if(num==2)
	   {
	   	cout<<"enter number of product to be deleted = ";
	   	cin>>num_of_pro;	   	
	   	remove(ar,num_of_pro-1,size,0,0);
	   }
	   else if(num==3)
	   { 
	   cout<<"product # \t quantity \n";
	   	display(ar,size,0 );
		}
		else if(num==4)
		{ 
		cout<<"enter number of product of which quatities are to be updated = ";
		cin>>new_size;
			update(ar,size,new_size-1,0);

		}
		else if(num==5)
		{
			found=false;
		}	
		else
		{
			cout<<"Invalid choice enter correct option \n";
			}	
	}while(found);

	delete [] ar;
	return 0;
}
void input(int *ar,int s,int i)
{
	if(i==s)
	{
		return ;
		
	}
	else
	{
		cout<<"enter "<<i+1<<" value = ";
		cin>>ar[i];
		input(ar,s,i+1);
	}
}
void add(int *ar,int *sw,int s,int i)
{
	if(i==s)
	{
		return;
		
	}
	else
	{
		 sw[i]=ar[i];
		 add(ar,sw,s,i+1);
	}
	
}
void display(int *ar,int s,int i)
{
	if(i==s)
	{
		return ;
		
	}
	else 
	{
		cout<<i+1<<"\t \t"<<ar[i]<<"\n";
		display(ar,s,i+1);
	}
}
void remove(int *ar,int n,int &s,int i,int j)
{
	if(i==s)
	{
		return;
	}
		if(n==i)
	{
		for(j=n;j<s-1;j++)
		{
			ar[j]=ar[j+1];
		}
		s--;
		return ;	
	}
	else
       {
		remove(ar,n,s,i+1,j);
        }
}
void update(int *ar,int s,int n,int i)
{
	if(i==s)
	{
		return;
	}
	if(n==i)
	{
		cout<<"enter quantities of that product = ";
		cin>>ar[i];
		return ;
	}
	else
	{
		update(ar,s,n,i+1);
	}
}