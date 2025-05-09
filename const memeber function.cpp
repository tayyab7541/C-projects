#include<iostream>
using namespace std;
class test
{
	private:
		int a;
		public:
			void fun1(int a)
			{
				this->a=a;
			}
		void display() const
		{
			cout<<"The value of a is = "<<a;
		}
};
int main()
{
	test t;
	int a=10;
	t.fun1(a);
	t.display();
	return 0;
}