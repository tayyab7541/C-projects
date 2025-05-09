#include<iostream>
using namespace std;
const int st=3;
const int sub=5;
void input(int arr[st][sub],int i,int j);
void display(int ar[st][sub],int i,int j);
void avg(int ar[st][sub],int arr[st],int sum ,int i,int j);
void highest_avg(int ar[],int high,int &loc,int i);
void lowest_avg(int ar[],int low,int &loc1,int i);
void max_in_4(int ar[st][sub],int max,int &loc,int i,int j);


int main()
{
	int av[st];
	int high,low,l,l1;
	int marks[st][sub];
	input(marks,0,0);
	cout<<"sub1 \t sub2 \t sub3 \t sub4 \t sub5 \n";
	display(marks,0,0);
	cout<<"average of students \n";
	avg(marks,av,0,0,0);
	high=av[0];
	highest_avg(av,high,l,0);
	cout<<"the highest average is of student "<<l+1<<" which is = "<<av[l]<<endl;
	low=av[0];
	lowest_avg(av,low,l1,0);
	cout<<"The lowest average is of student "<<l1+1<<" which is = "<<av[l1]<<endl;
	int m4=marks[0][3];
	int l2;
	max_in_4(marks,m4,l2,0,4);
	cout<<"The student who got maximum marks in subject 4 is student number "<<l2+1<<endl;


	return 0;
}


//recursive function to input marks of student in different subjects 
void input(int arr[st][sub],int i,int j)
{
	if(i==st)
	{
		return ;
	}
	if(j==sub)
	{
		input(arr,i+1,0);
	}
	else
	{
	cout<<"Enter marks of student "<<i+1<<" in subject "<<j+1<<" = ";
	cin>>arr[i][j];
	input(arr,i,j+1);
     }
}
void display(int ar[st][sub],int i,int j)
{
	if(i==st)
	{
		return ;
	}
	if(j==sub)
	{
		cout<<endl;
		display(ar,i+1,0);
	}
	else
	{
		cout<<ar[i][j]<<"\t";
		display(ar,i,j+1);
	}
}
//finding average of each student and storing it in a single diemensional array
void avg(int ar[st][sub],int arr[st],int sum ,int i,int j)
{
	if(i==st)
	{
		return ;

	}
	if(j==sub)
	{
		arr[i]=sum/sub;
		cout<<"average of student "<<i+1<<" is = "<<arr[i]<<endl;
		avg(ar,arr,0,i+1,0);
	}
	else
	{
      sum+=ar[i][j];
	  avg(ar,arr,sum,i,j+1);  
	}
}
void highest_avg(int ar[],int high,int &loc,int i)
{
	if(i==st)
	{
		return ;
	}
	else
	{
		if(ar[i]>high)
		{
			high=ar[i];
			loc=i;
		}
		highest_avg(ar,high,loc,i+1);
	}
}
//finding lowest average of student
void lowest_avg(int ar[],int low,int &loc1,int i)
{
	if(i==st)
	{
		return ;
	}
	else
	{
		if(ar[i]<low)
		{
			low=ar[i];
			loc1=i;
		}
		lowest_avg(ar,low,loc1,i+1);
	}
}
void max_in_4(int ar[st][sub],int max,int &loc,int i,int j)
{
	if(i==st)
	{
		return ;
	}
	else
	{
		if(ar[i][j]>max)
		{
			max=ar[i][j];
			loc=i;
		}
		max_in_4(ar,max,loc,i+1,j);
	}
}