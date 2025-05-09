#include<iostream>
#include<string>
using namespace std;
template <class t,class t1 , class t2>
class malik
{
	private:
	t name;
	t1 roll;
	t2 id, salary;
	public:
		malik() {}
		void input();
		void dis();
};
template<class t,class t1,class t2> void malik<t,t1,t2> ::input()
{
	cout<<"enter your name = ";
	getline(cin,name);
	cout<<"enter your roll # = ";
	cin>>roll;
	cout<<"enter your Id = ";
	cin>>id ;
	cout<<"enter your salary = ";
	cin>>salary;
}
template<class t,class t1,class t2> void malik<t,t1,t2>::dis()
{
	cout<<name<<"\t"<<roll<<"\t"<<id<<"\t"<<salary<<endl;
}
int main()
{
	malik <string,int,double> m;
	m.input();
	m.dis();
	return 0;
}