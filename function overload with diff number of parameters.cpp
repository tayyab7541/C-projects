#include<iostream>
using namespace std;
void sum(int x,int y);
void sum(int x,int y,int z);
int main()
{
	int a,b,c;
	cout<<"enter a =";
	cin>>a;
	cout<<"enter b =";
	cin>>b;
	cout<<"enter c =";
	cin>>c;
	sum(a,b,c);
	sum(a,b);
	return 0;
	
}

void sum(int x,int y )
{
	cout<<"\n sum is = "<<x+y;
	
}
void sum(int x,int y,int z)
{
	cout<<"\n sum is = "<<x+y+z<<endl;
	
}