#include<iostream>
#include<string>
#include<cstring>
#include<fstream>
#include<stdio.h>
using namespace std;
struct vehic
{
	int reg_id;
	char owner_name[30];
	char owner_gender[15];
	
};
void input(fstream &file);
void write_on_file(fstream &file1,fstream &combine);
void dis(fstream &file);

int main()
{
	fstream file1,file2,file3;
	// int size=20;
	file1.open("F:\\OOP Program\\vehicle1.dat",ios::binary|ios::out);
	if(file1)
	{
		input(file1);
	}
	else
	{
        cout<<"Please check path of file ";
		cout<<"sorry file cannot be opened to input data ";
	}
    
    file2.open("F:\\OOP Program\\vehicle2.dat",ios::binary|ios::out);
    if(file2)
    {
    	cout<<"Write data on second file \n";
    	input(file2);
	}
	else
	{
        cout<<"Please check path of file ";
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
		cout<<"check openening of combine file \n";
        cout<<"Please check path of file ";
	}
	file1.open("F:\\OOP Program\\vehicle1.dat",ios::binary|ios::in);
	if(file1)
	{
		
		if(file3)
		{
			write_on_file(file1,file3);
		}
	
	
	}
	else
	{
		cout<<"file cannot be opened ";
        cout<<"Please check path of file ";
	}
	
	file2.open("F:\\OOP Program\\vehicle2.dat",ios::binary|ios::in);
	if(file2)
	{
		write_on_file(file2,file3);
	}
	else 
	{
		cout<<"check opening of file 2 for read mode \n";
	}
	file1.close();
	file2.close();
	file3.close();
	file3.open("F:\\OOP Program\\combine.dat",ios::binary|ios::in);
	if(file3)
	{
		dis(file3);
	}
	else
	{
        cout<<"Please check path of file ";
		cout<<"sorry file cannot be opened \n";
	}
	file3.close();
	return 0;
	
	
}

void input(fstream &file) //function to input data
{
	vehic v;
	int i;
		
	for(i=0;i<2;i++)
	{
		cout<<"Enter name of owner = ";
    	 
//		cin.getline(v.owner_name,30);
        gets(v.owner_name);
		cout<<"Enter gender of owner = ";
		cin.getline(v.owner_gender,15);
//		cin.ignore();
		cout<<"enter registration id of vehicle = ";
		cin>>v.reg_id;
		cin.ignore();
		file.write((char*)&v,sizeof(v));
	}
	
}
void write_on_file(fstream &file1,fstream &combine) //function to write data on combine file 
{   
    int n;
	vehic v;
	while(file1.read((char*)&v,sizeof(v)))
	{
		n=strlen(v.owner_name);
		if((v.owner_name[n-1]=='s'&&v.owner_gender[0]=='f' )||v.owner_gender[0]=='F')
		{
			combine.write((char*)&v,sizeof(v));
		}
	}
}
void dis(fstream &file) //function to display records of combine file 
{
	vehic v;
	while(file.read((char*)&v,sizeof(v)))
	{
		cout<<v.owner_name<<"\t"<<v.owner_gender<<"\t"<<v.reg_id<<endl;
	}
}


