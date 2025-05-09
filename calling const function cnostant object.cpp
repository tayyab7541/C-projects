#include<iostream>
using namespace std;
class test
{
	private:
		int s;
		public:
			test(int a):s(a){}
		int f() const
		{
			return s;
		}
};
int main()
{
	const test t(10);
	cout<<"The number when calling funciton with const object ="<<t.f();
}