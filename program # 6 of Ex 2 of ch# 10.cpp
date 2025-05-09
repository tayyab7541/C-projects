#include<iostream>
using namespace std;
class date
{
	private:
		   int d,m,year;
	public:
		  date(int x,int y,int z)
		  {
		  	d=x;
		  	m=y;
		  	year=z;
		  	
		  }
	void show();
	void convert();
	
};
void date::show()
{
	cout<<"Date is \n";
	cout<<d<<"-"<<m<<"-"<<year<<endl;
}
void date::convert()
{
	cout<<"This is converted date \n";
	cout<<year*10000+m*100+d<<endl;
	
}
int main()
{
	int a,b,c;
	cout<<"Enter day = ";
	cin>>a;
	cout<<"Enter month = ";
	cin>>b;
	cout<<"Enter year = ";
	cin>>c;
	date D(a,b,c);
	D.show();
	D.convert();
}