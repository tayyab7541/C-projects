#include<iostream>
using namespace std;
class room
{
	private:
		double length,width;
		public:
			room(double a,double b)
			{
				length=a;
				width=b;
			}
			void display() const
			{
				cout<<"Length = "<<length<<endl<<" width = "<<width<<endl;
			}
			void fun(double length,double width)
			{
				this->length=length;
				this->width=width;
				
			}
			void calarea()
			{
				cout<<"area of room is = "<<length*width<<endl;
			}
};

int main()
{
	room r(4,5);
	r.display();
	r.calarea();
	//changing length and width 
	r.fun(6,7);
	r.display();
	r.calarea();
	return 0;
}