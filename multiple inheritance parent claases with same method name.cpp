#include<iostream>
using namespace std;
class a
{
	public:
		void dis()
		{
			cout<<"This is first parent class function \n" ;
		}
};
class b
{
	public:
		void dis()
		{
			cout<<"This is 2nd parent class function \n";
		}
};
class c:private a,private b
{
	public:
	
};
int main()
{
	c o;
   c.a::dis();
   c.b::dis();
   return 0;	
}