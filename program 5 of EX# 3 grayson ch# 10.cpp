#include<iostream>
using namespace std;
class student 
{
 private:
         int id;
		 double grade[5];
 public:
        student()
		{
			id=0;
			for(int i=0;i<5;i++)
			{
				grade[i]=0;
			}
		}
		void input();
		void avg();	
};
void student::input()
{
	int i;
	cout<<"Enter id of student = ";
	cin>>id;
	for(i=0;i<5;i++)
	{
		cout<<"enter marks of student in subject "<<i+1<<" = ";
		cin>>grade[i];
	}
}
void student::avg()
{
	int i,sum;
	float a;
	
	sum=0;
	for(i=0;i<5;i++)
	{
		sum+=grade[i];
		
	}
	a=sum/i;
	cout<<id<<"\t"<<a<<endl;
}
int main()
{
	student st;
	st.input();
	st.avg();
	return 0;
}