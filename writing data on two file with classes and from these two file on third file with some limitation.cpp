#include<iostream>
#include<string>
#include<cstring>
#include<stdio.h>
#include<fstream>
using namespace std;

//void input(fstream &);
//	void write_on_file(fstream &,fstream &);
 //   void dis(fstream &);
class vehic
{
    protected:
	int reg_id;
	char owner_name[30];
	char owner_gender[15];
	public:
	void input(fstream &);
	void write_on_file(fstream &,fstream &);
    void dis(fstream &);
};



void vehic::input(fstream &file) //function to input data
{
	int i;
		
	for(i=0;i<2;i++)
	{
		cout<<"Enter name of owner = ";
    	 
        gets(owner_name);
		cout<<"Enter gender of owner = ";
		cin.getline(owner_gender,15);

		cout<<"enter registration id of vehicle = ";
		cin>>reg_id;
		cin.ignore();
		file.write((char*)&(*this),sizeof((*this)));
	}
	
}


void vehic::write_on_file(fstream &file1,fstream &combine) //function to write data on combine file 
{   
    int n;
	while(file1.read((char*)&(*this),sizeof((*this))))
	{
		n=strlen(owner_name);
		if((owner_name[n-1]=='s'&&owner_gender[0]=='f' )||owner_gender[0]=='F')
		{
			combine.write((char*)&(*this),sizeof((*this)));
		}
	}
}

void vehic::dis(fstream &file) //function to display records of combine file 
{

	while(file.read((char*)&(*this),sizeof((*this))))
	{
		cout<<owner_name<<"\t"<<owner_gender<<"\t"<<reg_id<<endl;
	}
}

int main()
{
	vehic v;
   fstream file1,file2,file3;
   file1.open("F:\\OOP Program\\vehicle1.dat",ios::binary|ios::out);
	if(file1)
	{
		v.input(file1);
	}
	else
	{
        cout<<"please check your file path \n";
		cout<<"sorry file cannot be opened to input data ";
	}
	file2.open("F:\\OOP Program\\vehicle2.dat",ios::binary|ios::out);
    if(file2)
    {
    	cout<<"Write data on second file \n";
    	v.input(file2);
	}
	else
	{
        cout<<"please check your file path \n";
		cout<<"sorry file cannot be opened to input data ";
	}
	file1.close();
	file2.close();
	file3.open("F:\\OOP Program\\combine.dat",ios::binary|ios::out|ios::trunc);
	if(file3)
	{
		cout<<"combine file opened \n";
	}
	else
	{
        cout<<"please check your file path \n";
		cout<<"check openening of combine file why fialed\n";
	}
	file1.open("F:\\OOP Program\\vehicle1.dat",ios::binary|ios::in);
	if(file1)
	{
		
		if(file3)
		{
			v.write_on_file(file1,file3);
		}	
	}
	else
	{
        cout<<"please check your file path \n";
		cout<<"file cannot be opened ";
	}
		file2.open("F:\\OOP Program\\vehicle2.dat",ios::binary|ios::in);
	if(file2)
	{
		v.write_on_file(file2,file3);
	}
	else 
	{
        cout<<"please check your file path \n";
		cout<<"sorry file cannot be opened \n";
	}
	
	file1.close();
	file2.close();
	file3.close();
	file3.open("F:\\OOP Program\\combine.dat",ios::binary|ios::in);
	if(file3)
	{
		v.dis(file3);
	}
	else
	{
        cout<<"please check your file path \n";
		cout<<"sorry file cannot be opened \n";
	}
	file3.close();
	return 0;
	
}

