#include<iostream>
using namespace std;
template <class t>
void fun(t ar[],int &size)
{
	t num;
	cout<<"\n ENter number to delete = ";
	cin>>num;   //input the number to delete 
 	for(int i=0;i<size;i++)
   {
	 if(ar[i]==num)
	 {
	 	for(int j=i;j<size-1;j++)
	 	{
	 		ar[j]=ar[j+1];
		 }
		 size--;
	 }
   }
}
void dis(int ar[],int size)
{
	for(int i=0;i<size;i++)
	{
		cout<<ar[i]<<"\t";
	}
}

int main()//main starts here
{
	int size=10;
	int ar[size]={1,2,3,4,5,6,7,8,9,10};
	dis(ar,size);
	fun(ar,size);
	dis(ar,size);
	return 0;
	
}
