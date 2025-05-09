#include<iostream>
#include<fstream> //file handler
#include<cstring>
using namespace std;
int main()
{
	char name[40];
	int age ,semester;
	fstream file; //file pointer
	file.open("F:\\OOPs\\malik.txt",ios::out);
	if(!file)
	{
		cout<<"sorry file cannot be opened ";
	}
	else
	{
		cout<<"file is opened ";
		cout<<"enter name  =";
	    cin.getline(name,40);
	    cout<<"enter age = ";
	    cin>>age;
	    cout<<"enter semester = ";
	    cin>>semester;
	    file<<name<<"\t"<<age<<"\t"<<semester<<endl;		
	}
	file.close();
	fstream f;
	f.open("F:\\OOPs\\malik.txt",ios::in);
	string l;
	while(getline(f,l))
	{
		cout<<l;
	}
	f.close();
	return 0;
}