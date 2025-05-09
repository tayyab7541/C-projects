#include<iostream>
using namespace std;
template <class t>
class malik
{
	private :
		t num1,num2;
		public:
			malik() {}
			void input();
			void sum();
			void diff();
			void mul();
			void div();
};
template<class t> void malik<t>::input()
{
	cout<<"Enter first number = ";
	cin>>num1;
	cout<<"Enter second number = ";
	cin>>num2;
	
}
template<class t>void malik<t>::sum()
{
	cout<<"Sum of number is = "<<num1+num2;
}
template<class t>void malik<t>::diff()
{
	cout<<"Difference of two number is = "<<num1-num2;
}
template<class t>void malik<t>::mul()
{
	cout<<"Multiplication of two numbers = "<<num1*num2;
	
}
template<class t>void malik<t>::div()
{
	cout<<"division of two number is = "<<num1/num2;
}
int main()
{
	malik <int> m;
	m.input();
	char ch;
	cout<<"Enter operation you want on these numbers = ";
	cin>>ch;
	if(ch=='+')
	{
		m.sum();
	}
	else if (ch=='-')
	{
		m.diff();
	}
	else if(ch=='*')
	{
		m.mul();
		
	}
	else if(ch=='/')
	{
		m.div();
	}
	return 0;
}