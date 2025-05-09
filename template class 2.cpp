#include<iostream>
using namespace std;
template <class t>
class malik
{
	private:
	t n,n1,n2;
	public:
		malik() {}
		void input();
		void dis();
};
template<class t>void  malik<t>::input()
{
	cout<<"enter number = ";
	cin>>n;
	cout<<"enter second number = ";
	cin>>n1;
	cout<<"enter third number = ";
	cin>>n2;
}
template<class t> void malik<t>::dis()
{
	cout<<"number are = \n";
	cout<<n1<<"\t"<<n2<<"\t"<<n<<endl; 
}
int main()
{
	malik <int> m;
	m.input();
	m.dis();
	return 0;
}