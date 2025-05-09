#include<iostream>
using namespace std;
int n=0;
class emp
{
	private:
		int id,wh;
		double pay;
		public:
			void add(emp ar[],int size);
			void del(emp ar[] , int size);
			void mod(emp ar[],int size);
			void dis(emp ar[],int size);			
};
int main()
{
	int size=5;
	emp ar[size];
	int n;
	bool found =1;
	do
	{
		cout<<"\n Main menue \n 1:To add record \n 2:To del record \n 3:To modify record \n 4:To display records \n 5:To exit program \n enter your choice = ";
		cin>>n;
		if(n==1)
		{
			ar[1].add(ar,size);
		}
		else if(n==2)
		{
			ar[1].del(ar,size);
		}
		else if(n==3)
		{
			ar[1].mod(ar,size);
			
		}
		else if(n==4)
		{
			ar[1].dis(ar,size);
		}
		else if(n==5)
		{
			found =0;
		}
		else
		{
			cout<<"Invalid input try again \n ";
			
		}
	}while(found) ;
	return 0;
}
void emp::add(emp ar[],int size)
{
	int i;
	if(n<size)
	{
		cout<<"Enter id of employee =";
		cin>>ar[n].id;
		cout<<"Enter work hours in week = ";
		cin>>ar[n].wh;
		cout<<"Enter pay rate of employee = ";
		cin>>ar[n].pay;
		n++;
	}
}
void emp::del(emp ar[],int size)
{
	int i,num,j;
	bool f=0;
	cout<<"enter id of employee of which record to be deleted = ";
	cin>>num;
	for(i=0;i<n;i++)
	{
		if(num==ar[i].id)
		{
			for(j=i;j<n-1;j++)
			{
				ar[j]=ar[j+1];
			}
			n--;
			f=1;
			break;
			
		}
	}
	if(f)
	{
		cout<<"record deleted \n";
		
	}
	else
	{
		cout<<"record not found \n";
	}
}
void emp::mod(emp ar[],int size)
{
	int i,num;
	bool f=0;
	cout<<"enter id of employee of which record to be modified = ";
	cin>>num;
	for(i=0;i<n;i++)
	{
		if(num==ar[i].id)
		{
			cout<<"Enter new id =";
			cin>>ar[i].id;
			cout<<"Enter new work hours = ";
			cin>>ar[i].wh;
			cout<<"Enter new pay rate = ";
			cin>>ar[i].pay;
			f=1;
			break; 
		}
	}
	if(f)
	{
		cout<<"\n MOdification done successfully \n";
	}
	else
	{
		cout<<"record not found \n";
	}
}
void emp::dis(emp ar[],int size)
{
	int i;
	for(i=0;i<n;i++)
	{
		cout<<ar[i].id<<"\t"<<ar[i].wh<<"\t"<<ar[i].pay<<endl;
	 } 
}