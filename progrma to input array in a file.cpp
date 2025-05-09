#include<iostream>
#include<fstream>
using namespace std;
int main()
{
	fstream file;
	
	int size,i;
	cout<<"please enter the size of aray = ";
	cin>>size;
	int ar[size];
	file.open("F:\\OOP Program\\Input arra in file .txt",ios::out);
	if(!file)
	{
		cout<<"file cannot be created !";
	}
	else 
	{
	for(i=0;i<size;i++)
	{
		cout<<"enter "<<i+1<<" value = ";
		cin>>ar[i];
	}
	for(i=0;i<size;i++)
	{
		file<<"value number "<<i+1<<" is = "<<ar[i]<<endl;
	}
	
    }
    file.close();
}