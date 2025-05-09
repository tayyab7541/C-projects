#include<iostream>
#include<fstream>
#include<cstring>
using namespace std;
int main()
{
	fstream file;
	char name[40];
	int age,roll;
	file.open("F:\\OOPs\\Tayyab.txt",ios::out);
	if(!file)
	{
	cout<<"file cannot be opened";	
	}
	else
	{
		cout<<"file is opened \n";
		 cout<<"enter name of student  = ";
		 cin.getline(name,40);
		 cout<<"enter age of student  =" ;
		 cin>>age;
		 cout<<"enter roll of student = ";
		 cin>>roll;
		 file<<name<<"\t"<<age<<"\t"<<roll<<endl;
	}
	file.close();
	fstream f;
	f.open("F:\\OOPs\\Tayyab.txt",ios::in);
	if(!f)
	{
		cout<<"file cannot be opened in reading mode ";
	}
	else
	{
		cout<<"file is opened for reading  \n";
		string n;
		int a,r;
		while(	f>>n>>a>>r)
		{
		
			cout<<n<<"\t"<<a<<"\t"<<r<<"\n";
		}
	}
	f.close();
}