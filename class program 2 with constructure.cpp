#include<iostream>
using namespace std;
class date
{
	private:
		    int day;
		    int month;
		    int year;
	public: 
	       date(int x,int y,int z)
	       {
	       	day=x;
	       	month=y;
	       	year=z;
		   }
		   void dispaly();
		   
};
void date::dispaly()
{
	cout<<"This is date \n";
	cout<<day<<"-"<<month<<"-"<<year<<endl;
	
}
int main()
{
	int a,b,c;
	cout<<"enter day = ";
	cin>>a;
	cout<<"enter month = ";
	cin>>b;
	cout<<"enter year =";
	cin>>c;
	date cons(a,b,c);
	
	cons.dispaly();
	return 0;
}