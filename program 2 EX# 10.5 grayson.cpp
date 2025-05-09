#include<iostream>
using namespace std;
class circle
{
	private:
		int xcen,ycen;
		double rad;
		static int scalefact;
		public:
			circle(int a,int b,double c): xcen(a),ycen(b),rad(c) {}
			void display() const
			{
				cout<<"points of circle ("<<xcen<<","<<ycen<<")"<<endl;
				cout<<"radius is = "<<rad<<endl;
				cout<<"scale ="<<scalefact*rad<<endl;
			}
			static void fun(int a)
			{
				scalefact=a;
			}
};
int circle::scalefact=2;
int main()
{
	circle c(10,20,5);
	c.display();
	c.fun(4);
	c.display();
	return 0;
}