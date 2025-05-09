#include<iostream>
using namespace std;
void findhot(int **ar,int r,int &max,int &l,int i);
void findcold(int **ar,int r,int &min,int &l,int i);
void calavg(int **ar,int r,float &av,int i);
void display(int **ar,int r,int c,int i,int j);
void input(int **ar,int r,int i);
int main()
{
	int max;
	int row,col,**ar,i,j;
	bool found=1;
	cout<<"enter number of days in month[28 or 29 or 30] = ";
	cin>>row;
	col=3;
	if(row>=1&&row<=5)
	{
	ar=new int*[row];
	for(i=0;i<row;i++)
	{
		ar[i]=new int[col];
	}
     input(ar,row,0);
    
	 
	 do
	 {
	 	cout<<"\n Main menue \n 1:To find hottest day in month \n 2:To find coldest day in month \n 3:To calculate average of temperature in month \n 4:To display temperature \n 5:To exit program \n enter your choice = ";
	 	cin>>j;
	 	if(j==1)
	 	{
	 		max=ar[0][1];
	 		int loc=-1;
	 		findhot(ar,row,max,loc,0);
	 		cout<<"hottest day is day number "<<loc+1<<" temp of that day is "<<max;
		 }
		 else if(j==2)
		 {
            int min;
		 	min=ar[0][0];
	 		int loc=0;
	 		findcold(ar,row,min,loc,0);
	 		cout<<"coldest day is day number "<<loc+1<<" temp of that day is "<<min;
            
            
		 }
	 else if(j==3)
		 {
            float avg=0;
		 	calavg(ar,row,avg,0);
            cout<<"total average is = "<<avg;
		 }
		 else if(j==4)
		 {  
            cout<<" Min temp \t Max temp \t Avg of temp \n ";
		 	display(ar,row,col,0,0);
		 }
		 else if(j==5)
		 {
		 	found=0;
		 }
		 else 
		 {
		 	cout<<"Invalid input try again \n  ";
		 }
		 
	 }while(found);
	 for(i=0;i<row;i++)
	 {
	 	delete [] ar[i];
	 }
	 delete [] ar;
	 return 0;
}
 else
     {
     	cout<<"Invalid number of days ";
	 }
 }
 void input(int **ar,int r,int i)
 {
 	if(i==r)
 	{
 		return ;
	 }
	 else
	 {
	 	cout<<"Enter min temperature for day "<<i+1<<" = ";
	 	cin>>ar[i][0];
	 	cout<<"Enter max temperature for day "<<i+1<<" = ";
	 	cin>>ar[i][1];
	 	ar[i][2]=(ar[i][0]+ar[i][1])/2;
	 	input(ar,r,i+1);
	 }
 }
 void findhot(int **ar,int r,int &max,int &l,int i)
 {
 	if(i==r)
 	{
 		return ;
 		
	 }
	if(ar[i][1] > max)
	{
		max = ar[i][1];
		l=i;
	}
		findhot(ar,r,max,l,i+1);
	
 }
 void findcold(int **ar,int r,int &min,int &l,int i)
 {
    if(i==r)
 	{
 		return ;
 		
	 }
	if(ar[i][0] < min)
	{
		min = ar[i][0];
		l= i;
	}
		findcold(ar,r,min,l,i+1);
 }
 void calavg(int **ar,int r,float &av,int i)
 {
    if(i==r)
    {
        av=av/r;
        return;
    }
    av +=ar[i][2] ;
    calavg(ar,r,av,i+1);
 }
 void display(int **ar, int r, int c, int i, int j)
{
    if (i == r)
    {
        return;
    }
	    if (j == c)
    {
        cout << endl;
        display(ar, r, c, i + 1, 0); 
    }
    else
    {
         cout<< ar[i][j] << "\t \t";       
        display(ar, r, c, i, j + 1); 
    }
}