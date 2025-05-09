#include<iostream>
#include<limits>
#include<cctype>
#include<cstring>
#include<fstream>
using namespace std;
struct student
{
	char name[40];
	int roll;
	
};
int main()
{
	fstream file;
	int num;
	student st;
	bool found=1;
	do
	{
		cout<<"\n \n Main menue \n 1:To add record \n 2:To display all records \n 3:To search data from record \n 4:To delete record \n 5:To modify records\n 6:To sort records  \n 7:To exit \n Enter your choice = ";
		cin>>num;
		if(num==1)
		{
			file.open("F:\\OOP Program\\check.dat",ios::binary|ios::in);
			if(!file)
			{
				cout<<"file cannot be opened";
			}
			else
			{
				bool c=0;
				do
				{
					cout<<"please enter the name =";
					cin.getline(st.name,40);
					for(int i=0;st.name[i]!='\0';i++)
					{
	                if(!isalpha(st.name[i])&&st.name[i]!=' ')
	                {
	                	cout<<"enter valid name \n\n";
	                	c=1;
	                	break;
					}
				    }
				}while(c);
				//to check taht roll number is valid
					bool c1=0;
				do
				{
				
					student temp;
					cout<<"Please enter roll number of student =";
					cin>>st.roll;
					if(cin.fail()||st.roll<0)
					{
						cin.ignore(numeric_limits<streamsize>::max(),'\n');
						cout<<"enter valid digits \n \n";
					     c1=1;	
					}
					while(file.read((char*)&temp,sizeof(temp)))
					{
						if(temp.roll==st.roll)
						{
							cout<<"this roll number already exists enter again\n \n";
							c1=1;
							break;
						}
					}
					
				}while(c1);
				file.close();
			}
		}
		else if(num==6)
		{
			found =0;
		}
		else
		{
			cout<<"invalid input";
		}
	}while(found);
}