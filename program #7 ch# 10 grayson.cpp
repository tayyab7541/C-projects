#include<iostream>
using namespace std;
class emp
{
	private :
	    static int tax;
	    int id;
	    public:
	    	emp(int tax)
	    	{
	    	   id=tax;
			}
		 void display()
		 {
		 	cout<<"Tax for employ number id "<<id<<" = "<<tax <<endl;
		
		 }		 
};
 int emp::tax=9;
 int main()
 {
 	emp e(2500),d(2700),a(2900);
 	e.display();
 	d.display();
 	a.display();
 	return 0;
 	
 	
 }