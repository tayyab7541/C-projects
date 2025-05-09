#include<iostream>
#include<cstring>
using namespace std;
class student // first base class
{
	protected:
	char name[40];
};
class st //2nd base class
{
	protected:
	int roll;
	float sem;
};
class sub:private student,private st //derived class
{
	public:
	void input();
	void dis();
};
void sub::input()
{
	cout<<"Enter name of student = ";
	cin.getline(name,40);
	cout<<"Enter roll number of student = ";
	cin>>roll;
	cout<<"Enter semester number of student = ";
	cin>>sem;
}
void sub::dis()
{
	cout<<"Name \t Roll \r sem \n";
	cout<<name<<"\t"<<roll<<"\t"<<sem<<endl;
}

int main()
{
	sub t;
	t.input();
	t.dis();
}