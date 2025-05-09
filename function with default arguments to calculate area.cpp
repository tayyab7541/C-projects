#include<iostream>
#include<stdio.h>
#include<cstring>
using namespace std;
void printdetails(char name[],int age=18,float height=4.6);
int main()
{
	char nam[40];
	cout<<"please enter your name =";
	gets(nam);
	printdetails(nam);
	return 0;
}
void printdetails(char name[],int age,float height)
{
	int i;
	i=strlen(name);
	for(i=0;name[i]!='\0';i++)
	{
		cout<<name[i];
	}
	cout<<"\t "<<age<<"\t"<<height<<endl;
	
}