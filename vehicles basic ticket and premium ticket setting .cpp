#include<iostream>
#include<string>
#include<cmath>
using namespace std;
class basic_ticket  //parent class
{
	protected:
		string name,departure_city,arival_city;
		int flight_number,price;
		public:
			basic_ticket() {} //this is default constructue
			basic_ticket(string st,string departure,string arival,int flight,int p)
			{
				name=st;
				departure_city=departure;
				arival_city=arival;
				flight_number=flight;
				price=p;
			}
			int getprice()
			{
				return price;
			}	
//			virtual void dis()=0;		
};
class premium_ticket:public basic_ticket
{
	protected:
		int seat_number;
		public:
			premium_ticket(string st,string departure,string arival,int flight,int p,int seat):basic_ticket(st,departure,arival,flight,p),seat_number(seat) {}
			void getprice()
			{
				int num=basic_ticket::getprice();
				cout<<"Value of premium ticket is = "<< price+num*0.1<<endl;
			}
//			void dis()
//			{
//				cout<<name<<"\t"<<departure_city<<"\t"<<arival_city<<"\t"
//					}		
};

int main()
{
	basic_ticket b("wahab","islamabad","faislabad",4,500);
	premium_ticket p("wahab","islamabad","faislabad",4,500,39);
	cout<<"Basic ticket price is = "<<b.getprice()<<endl;
	p.getprice();
}


