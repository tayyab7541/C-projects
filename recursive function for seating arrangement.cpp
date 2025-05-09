#include<iostream>
#include<string>
using namespace std;
void input(string **ar,int row,int col,int i,int j,int k,int l);
void find(string **ar,string nam,int row,int col,int i,int j,int &rn,int &cn);
void remove(string **ar,int row,int col,int rn,int cn,int i,int j);
void display(string **ar,int row,int col,int i,int j);
int main()
{
	int row,col,num,i;
	string **seat;
		int r,c;
		int a,b;
	bool found =1;
	
	a=-1;
	b=-1;
	string name;
	cout<<"enter number of rows = ";
	cin>>row;
	cout<<"enter number of colums = ";
	cin>>col;
	seat=new string *[row];
	for(i=0;i<row;i++)
	{
		seat[i]=new string [col];
	}
	
	do
	{
		cout<<"\n Main menue \n 1:To add attende \n 2:To remove attendee \n 3:TO display arrngements \n 4:To find specific attendee \n 5:To exit main program \n Enter your choice = ";
		cin>>num;
		if(num==1)
		{
		
			cout<<"enter row number of seat = ";
			cin>>r;
			cout<<"enter column number of seat = ";
			cin>>c;
			input(seat,row,col,r-1,c-1,0,0);
		}
		else if(num==2)
		{
                
			cout<<"enter name of attendee to be removed = ";
			cin.ignore();
			getline(cin,name);
			find(seat,name,row,col,0,0,a,b);
			if(a>=0&&b>=0)
			{
			remove(seat,row,col,a,b,0,0);
			}
			else
			{
				cout<<"attendee is not found \n";
			}
		}
		else if(num==3)
		{
			display(seat,row,col,0,0);
		}
		else if(num==4)
		{
			
			cout<<"enter name of attendee to find = ";
			cin.ignore();
			getline(cin,name);
			find(seat,name,row,col,0,0,a,b);
			if(a>=0&&b>=0)
			{
			cout<<"seat reserved by the attendee is = ["<<a+1<<"]["<<b+1<<"]";
	    	}
			else
			{
				cout<<"attendee name is not found \n ";
			}
	}
		else if(num==5)
		{
			found=0;
		}
		else
		{
			cout<<"Invalid try please enter again \n ";
		}
		
	}while(found);
	for(r=0;r<row;r++)
	{
		delete [] seat[r];
	}
	delete [] seat;
}

void input(string **ar,int row,int col,int i,int j,int k,int l)
{
	if(k==row)
	{
		return ;
	}
	if(k==i&&l==j)
	{
		if(ar[k][l].empty())
		{
		cout<<"enter name of attendee = ";
		cin.ignore();
		getline(cin,ar[i][j]);
	    }
	    else 
	    {
	    	cout<<"seat is already reserved by  ="<<ar[k][l];
		}
	}
	if(l==col)
	{
		input(ar,row,col,i,j,k+1,0);
		return ;
	}
	input(ar,row,col,i,j,k,l+1);
	
}
void find(string **ar,string nam,int row,int col,int i,int j,int &rn,int &cn)
{
	if(i==row)
	{
		return ;
	}
	if(ar[i][j]==nam)
	{
		rn=i;
		cn=j;
		return;
	}
	if(j==col-1)
	{
		find(ar,nam,row,col,i+1,0,rn,cn);

	}
	else
	{
	   find(ar,nam,row,col,i,j+1,rn,cn);
}
}

void display(string **ar,int row,int col,int i,int j)
{
	if(i==row)
	{
		return;

	}
	if(j==col)
	{   cout<<endl;
		display(ar,row,col,i+1,0);
		return ;
	}
	if(ar[i][j].empty())
	{
		cout<<"\n this seat ["<<i+1<<"]["<<j+1<<"] is empty \n";
	}
	else{
		cout<<"this seat ["<<i+1<<"]["<<j+1<<"] is reserved by = "<<ar[i][j]<<endl;
	}
	display(ar,row,col,i,j+1);

}
void remove(string **ar,int row,int col,int rn,int cn,int i,int j)
{
	if(i==row)
	{
		return ;
	}
	if(rn==i&&cn==j)
	{
		if(ar[i][j].empty())
		{
			cout<<"seat is already empty \n";
			return ;
		}
		else
		{
			ar[i][j].erase();
			cout<<"attendee has been remvoed \n ";
			return;
		}
	}
	if(j==col)
	{
		remove(ar,row,col,rn,cn,i+1,0);
	}
	else
	{
		remove(ar,row,col,rn,cn,i,j+1);
	}

}