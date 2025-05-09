#include<iostream>
#include<cstring>
using namespace std;

class single //parent class
{
	protected:
		 char name[40];
		 float roll;
		 int semester;
		 
};

class sub:protected single //child class
{
	public:
	void input()
	{
				cout<<"Enter name of student = ";
		cin.getline(name,40);
		cout<<"Enter roll number = ";
		cin>>roll;
		cout<<"enter semister number = ";
		cin>>semester; 
	}
	void dis()
	{
		cout<<"Name \t Roll \t semester # \n";
		cout<<name<<"\t"<<roll<<"\t"<<semester<<"\n";
		
	}
};

//main program
int main()
{
	sub s; //creating object of sub class
	s.input();
	s.dis();
}