#include<iostream>
using namespace std;
void add(int x,int y);
void add(int x,float y);
int main()
{
	int a,b;
	float c;
	cout<<"enter a =";
	cin>>a;
	cout<<"eneter b=";
	cin>>b;
	cout<<"enter c = ";
	cin>>c;
	add(a,b);
	add(a,c);
	
}
void add(int x,int y)
{
	cout<<x+y;
	
}
void add(int x,float y)
{
	cout<<"\n"<<x+y;
}