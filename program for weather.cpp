#include<iostream>
#include<climits>
using namespace std;
void hot(int **arr,int row);
void cold(int **arr,int row);
void average(int **arr,int row);
void display(int **arr,int row);
int main()
{
	int days,temp_states,i,num;
	bool found=1;
	float min,max;
	cout<<"enter number of days in month = ";
	cin>>days;
	cout<<"enter number of temperature states for a day = ";
	cin>>temp_states;
	if(days>=28&&days<=30&&temp_states==3)
	{
	int **ar;
	ar=new int*[days];
	for(i=0;i<days;i++)
	{
		ar[i]=new int[temp_states];
	}
	
	for(i=0;i<days;i++)
	{
		cout<<"For day "<<i+1<<" \n\n ";
		
		cout<<"enter minimum temperature = ";
		cin>>min;
		cout<<"enter maximum temperature = ";
		cin>>max;
		ar[i][0]=min;
		ar[i][1]=max;
		ar[i][2]=(min+max)/2;
		
	}
	

	//for  function
	do
	{
	cout<<"\n Main menue \n 1:To find hottest temperature of month \n 2:To find coldest temperature of month \n";
	cout<<"3:To find find total avg of temperature of month \n 4:To display temperature in increasing order \n";
	cout<<"5:To exit program \n ";
	cout<<"please enter your choice = ";
	cin>>num;
	if(num>=1&&num<=5)
	{
	if(num==1)
	{
		hot(ar,days);
	}
	else if(num==2)
	{
		cold(ar,days);
	}
	else if(num==3)
	{
		average (ar,days);
		
	}
	else if(num==4)
	{
		display(ar,days);
		
	}
	else if(num==5)
	{
		found=false;
	}
}
else
{
	cout<<"invalid input \n";
}
    }while(found);

	for(i=0;i<days;i++)
   {
	delete [] ar[i];
   }
   delete [] ar;
   }
   else
   {
   	cout<<"invalid input \n"; 
   }
   
	
}

void hot(int **arr,int row)
{
	int hottest,i,loc;
	hottest=INT_MIN;
	for(i=0;i<row;i++)
	{
		if(arr[i][1]>hottest)
		{
			hottest=arr[i][1];
			loc=i;
		}
	}
	cout<<"\n Hottest temperature is of day number "<<loc+1<<" which is "<<hottest;
}
void cold(int **arr,int row)
{
	int i,coldest,loc;
	coldest=INT_MAX;
	for(i=0;i<row;i++)
	{
		if(arr[i][0]<coldest)
		{
			coldest=arr[i][0];
			loc=i;
		}
	}
	cout<<"\n coldest temperature is of day number "<<loc+1<<" which is = "<<coldest;
}
void average(int **arr,int row)
{
	int i;
	double total_avg,total;
	total=0;
	for(i=0;i<row;i++)
	{
		total+=arr[i][2];
	}
	total_avg=total/i;
	cout<<"Total average of temperature in whole month is = "<<total_avg;
}
void display(int **arr,int row)
{
	int i;
	cout<<"day # \t min temperature \t max temperature \t avg \n";
	for(i=0;i<row;i++)
	{
		
			cout<<i+1<<"\t "<<arr[i][0]<<"\t     "<<arr[i][1]<<"\t \t"<<arr[i][2]<<endl;
		
	}
}