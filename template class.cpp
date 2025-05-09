#include<iostream>
using namespace std;
template <class t>
class malik
{
	private:
		t n1,n2;
		public:
			malik(int a ,int b)
			{
				n1=a;
				n2=b;
			}
			void dis()
			{
				cout<<"sum of two numbers = "<<n1+n2<<endl;
			}
};

int main()
{
	malik <int>m1(5,5);
	malik<char> m2('a','b');
	m2.dis();
	m1.dis();
	return 0;
}