#include<iostream>
#include<cmath>
using namespace std;
class coord
{
	private:
		double xval,yval;
		public:
			coord(double x,double y)
			{
				xval=x;
				yval=y;
				
			}
			void display() const
			{
				cout<<xval<<endl<<yval<<endl;
			}
			void convert(double a,double b)
			{
				xval=a*cos(b*M_PI/180);
				yval=a*sin(b*M_PI/180);
			}
};
int main()
{
	coord t(2,4);
	cout<<"values before convert \n";
	t.display();
	
	cout<<"values after convert \n";
	t.convert(6,30);
	t.display();
	return 0;
}