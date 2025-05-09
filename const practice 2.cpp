#include<iostream>
using namespace std;
class point
{
	private:
		 int x,y;
		 public:
		void fun(int x,int y)
		{
			this->x=x;
			this->y=y;
			
		}
		int getx() const
		{
			return x;
		}
		int gety() const 
		{
			return y;
		}
		
};
int main()
{
	int a,b;
	a=5;b=10;
	point p;
	p.fun(a,b);
  cout<<"value of x ="<<p.getx()<<"\n value of y ="<<p.gety()<<endl;
  return 0;
}