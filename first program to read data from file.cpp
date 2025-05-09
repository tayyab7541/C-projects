#include<iostream>
#include<fstream>
using namespace std;
int main()
{
	fstream file;
	file.open("F:\\programs\\File handling in c++ programs prac\\malik.txt");
	if(!file)
	{
		cout<<"cannot open file ";
	}
	else{
		cout<<"epening done ";
	}
	file.close();
}