#include<iostream>
#include<string>

using namespace std;
void add(string **arr,int &r,int &colum);
void remove(string **arr,int &r,int &colum);
void find(string **arr,int &r,int &colum);
void display(string **arr,int &r,int &colum);
int main()
{
	int row,colum,i,num;
	string **ar;
	bool found=1;
	cout<<"Enter number of rows = ";
	cin>>row;
	cout<<"Enter number of colums = ";
	cin>>colum;
	ar=new string *[row];
	for(i=0;i<row;i++)
	{
		ar[i]=new string [colum];
	}
	do
	{
		cout<<"\n Main menue \n 1:To add attendee \n 2:To remove attendee \n 3:To find attendee \n 4:To display all record \n 5:To exit program \n\n choose only one option = ";
		cin>>num;
		if(num==1)
		{
			add(ar,row,colum);
			
		}
	else if(num==2)
		{
			remove(ar,row,colum);
		}
		else if(num==3)
		{
			find(ar,row,colum);
		}
		else if(num==4)
		{
			display(ar,row,colum);
		}
		else if(num==5)
		{
			found=false;
		}
		else 
		{
			cout<<"\n Invalid input \n ";
		}
		
	}while(found);
	
     for(i=0;i<row;i++)
	 
	 {
	 	delete [] ar[i];
		 }	
		 delete [] ar;
}
void add(string **arr,int &r,int &colum)
{
	int row_num,colum_num;
	char ch;
	do{
	cout<<"enter row number of seat to add attendee = ";
	cin>>row_num;
	cout<<"enter colum number of seat to add attendee = ";
	cin>>colum_num;
	if(row_num>=0&&row_num<=r&&colum_num>=0&&colum_num<=colum)
	{ 
		if(arr[row_num-1][colum_num-1].empty())
		{
		    cout<<"enter name of attende = ";
		    cin.ignore();
		    getline(cin,arr[row_num-1][colum_num-1]);
	    }
	    else
	    {
	    	cout<<"This seat is already taken by  ="<<arr[row_num-1][colum_num-1]<<endl;
		}
	}
	else
	{
		cout<<"Invalid position \n";
	}
	cout<<"do you want to add another attendee [y/N] = ";
	cin>>ch;
}while(ch=='y'||ch=='Y');

	display(arr,r,colum);
}
void remove(string **arr,int &r,int &colum)
{
	int row_num,colum_num;
	cout<<"Enter row number to remove attende = ";
	cin>>row_num;
	cout<<"Enter colum number to remove attende = ";
	cin>>colum_num;
	if(row_num>=0&&row_num<=r&&colum_num>=0&&colum_num<=colum)
	{
		if(arr[row_num-1][colum_num-1].empty())
		{
			cout<<"\n This seat is already empty \n ";
		}
		else 
		{
			arr[row_num-1][colum_num-1].erase();
			cout<<"Attendee has been removed \n";
		}
	}
	
	display(arr,r,colum);
}
void find(string **arr,int &r,int &colum)
{ 
   int i,j,loc1,loc2;
	string name;
	bool found=false;
	cout<<"enter name to find attendee = ";
	cin.ignore();
	getline(cin,name);
	for(i=0;i<r;i++)
	{
		for(j=0;j<colum;j++)
		{
			if(name==arr[i][j])
			{
				found=true;
				loc1=i;
				loc2=j;
			}
		}
	}
     
	 if(found)
	 {
	 	cout<<"Attendee name is found at location = ["<<loc1+1<<"]["<<loc2+1<<"]  \n";
		 }	
		 else
		 {
		 	cout<<"name of attende is not found \n";
		 }
		 display(arr,r,colum);
}
void display(string **arr,int &r,int &colum)
{
	int i,j;
	for(i=0;i<r;i++)
	{
		for(j=0;j<colum;j++)
		{
			if(arr[i][j].empty())
			{
				cout<<"\n seat number ["<<i+1<<"]["<<j+1<<"] is empty \n";
			}
			else
			{
				cout<<"\n seat number ["<<i+1<<"]["<<j+1<<"] is taken by = "<<arr[i][j]<<endl;
			}
		}
	}
}
