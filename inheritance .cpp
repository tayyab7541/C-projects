#include<iostream>
using namespace std;
class circle
{
	protected:
		double radius;
	public:
		void input()
		{
			cout<<"Enter radius of circle= ";
			cin>>radius;
		}
		double calvolume()
		{
			return (4/3)*3.14*radius*radius*radius;
		}
};

class cylinder:public circle
{
	protected:
		int length;
		public:
			double calvolume()
			{
                cout<<"Enter height of cylinder = ";
                cin>>length;
				return 3.14*radius*radius*length;
			}
};

int main()
{
	cylinder c;
	c.circle::input();
    cout<<"Volume of circle is = "<<c.circle::calvolume();
    cout<<"Volume of cylinder is = "<<c.calvolume();
    return 0;
}
