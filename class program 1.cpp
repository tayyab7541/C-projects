#include<iostream>
#include<string>
using namespace std;
class student 
{
	private:
		    string name;
		    int age;
	public:
		   void get();
		   void dispaly();
};
int main()
{
	student st;
	st.get();
	st.dispaly();
	return 0;
	
}
void student::get()
{
	cout<<"Enter name of student = ";
	getline(cin,name);
	cout<<"Enter age of student = ";
	cin>>age;
}
void student::dispaly()
{
	cout<<"Name \t Age \n";
	cout<<name<<"\t"<<age;
}