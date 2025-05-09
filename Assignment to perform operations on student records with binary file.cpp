#include<iostream>
#include<fstream>
#include<cstring>
using namespace std;
struct student
{
	char name[50];
	int roll;
};
void add(fstream &file);  //function to add records to file
void dis(fstream &file);  //function to display records from file
void search(fstream &file); //function to search records from file
void del(fstream &file); //function to delete records from file
void sort(fstream &file); //function to sort records in file
void mod(fstream &file); //function to modify records in file


int main()
{
	fstream file;
	int num;
	bool found=1;
	file.open("F:\\OOPs\\midproject.dat",ios::binary|ios::out);
	if(!file)
	{
		cout<<"File cannot be opened please press number to exit and try again \n" ;

	}
	file.close();
	do
	{
		cout<<" 1:To add records \n 2:To display records \n 3:To search records\n 4:To delete records \n 5:To sort records \n 6:To modify records \n 7:To exit program \n\n make your choice = ";
		cin>>num;
		if(num==1)
		{
          file.open("F:\\OOPs\\midproject.dat",ios::binary|ios::app);
		  if(!file)
		  {
			cout<<"file cannot be opened to write data \n";

		  }
		  else
		  {
			add(file); //calling add function

		  }
		  file.close();
		}
		else if (num==2)
		{
			file.open("F:\\OOPs\\midproject.dat",ios::binary|ios::in);
			if(!file)
			{
				cout<<"file cannnot be opened \n";
			}
            else
			{
				dis(file);//calling display functioni
			}
			file.close();
		}
	else if(num==3)
	{
		file.open("F:\\OOPs\\midproject.dat",ios::binary|ios::in);
		if(!file)
		{
			cout<<"file cannnot be opened \n";
		}
		else
		{
			search(file);//calling search function
		}
		file.close();
	}
	else if(num==4)
	{
		file.open("F:\\OOPs\\midproject.dat",ios::binary|ios::in|ios::out);
			if(!file)
			{
				cout<<"file cannnot be opened \n";
			}
            else
			{
				del(file);//calling delete function
			}
			file.close();
	}
	else if(num==5)
	{
		file.open("F:\\OOPs\\midproject.dat",ios::binary|ios::in);
			if(!file)
			{
				cout<<"file cannnot be opened \n";
			}
            else
			{
				sort(file);//calling sort function
			}
			file.close();
	}
	else if(num==6)
	{
		file.open("F:\\OOPs\\midproject.dat",ios::binary|ios::in|ios::out);
			if(!file)
			{
				cout<<"file cannnot be opened \n";
			}
            else
			{
				mod(file);//calling modify function
			}
			file.close();
	}
	else if(num==7)//exit condition
	{
		found=0;
	}
	else
	{
		cout<<"please try again with valid number \n";
	}
	} while (found);
	return 0;
}

void add(fstream &file)//defining add function
{
	student st;
    char ch;
	do
	{
		cout<<"Enter name of student = ";
		cin.ignore();
		cin.getline(st.name,50);
		cout<<"Enter roll number of student = ";
		cin>>st.roll;
		file.write((char*)&st,sizeof(st));
		cout<<"DO you want to enter more records [y/N] = ";
		cin>>ch;
	} while (ch=='y'||ch=='Y');
	
}

void dis(fstream &file)//defining display function
{
	student st;
	while(file.read((char*)&st,sizeof(st)))
	{
		cout<<st.name<<"\t"<<st.roll<<endl;
	}
}

void search(fstream &file)//defining searhc function
{
	student st;
	int r;
	bool t=0;
	cout<<"enter roll number of student to find record = ";
	cin>>r;
	while(file.read((char*)&st,sizeof(st)))
    {
		if(r==st.roll)
		{
			cout<<st.name<<"\t"<<st.roll<<endl;
			t=1;
			break;
		}
	}
	if(t)
	{
      cout<<"record deleted successfully \n";
	}
	else
	{
		cout<<"record cannot be found \n";
	}

}

void del(fstream &file)//defining delete function
{
	student st;
	fstream temp;
	
	int r;
	bool find=0;
	temp.open("F:\\OOPs\\temp.dat",ios::binary|ios::out);
	if(temp)
	{
	cout<<"Enter roll number of student to delete record = ";
	cin>>r;
	while(file.read((char*)&st,sizeof(st)))
	{
       if(r!=st.roll)
	   {
		temp.write((char*)&st,sizeof(st));
		
	   }
	   else
	   {
		find=1;
	   }
	}
	if(find)
	{
		file.close();
		temp.close();
		cout<<"record delete successfully \n";
		remove("F:\\OOPs\\midproject.dat");
		rename("F:\\OOPs\\temp.dat","F:\\OOPs\\midproject.dat");
		
	}
	else
	{
		temp.close();
		cout<<"record cannot be found in file \n";
	}
    }

	else
	{
		cout<<"find cannot be opened check within the del function \n";
	}
}

void sort(fstream &file) //defining function to sort records 
{
	student swap,*ar,st;
	file.seekg(0,ios::end);
	int n,size,i;
    i=0;
	n=file.tellg();
	size=n/sizeof(student);
	cout<<"total records = "<<size<<endl;;
	ar=new student[size];
	file.seekg(0,ios::beg);
	while(file.read((char*)&st,sizeof(st)))
	{
      strcpy(ar[i].name,st.name);
	  ar[i].roll=st.roll;
	  i++;
	}
	int j,k;
	for(j=0;j<size-1;j++)
	{
		for(k=0;k<size-1-j;k++)
		{
			if(ar[k].roll>ar[k+1].roll)
			{
				swap=ar[k];
				ar[k]=ar[k+1];
				ar[k+1]=swap;
			}
		}
	}	
	file.close();
	file.open("F:\\OOPs\\midproject.dat",ios::binary|ios::out);
	if(file)
	{
	file.seekp(0,ios::beg); //setting write pointer to begining
	for(j=0;j<size;j++)
	{
		file.write((char*)&ar[j],sizeof(ar[j]));
	}
    }
else
{
	cout<<"sorry error in file opening \n";
}
	delete [] ar;
}
void mod(fstream &file) //defining modify function
{
	int r;
	bool t=0;
	cout<<"Enter name of student of which record is to modify = ";
	cin>>r;
	student st;
	while(file.read((char*)&st,sizeof(st)))
	{
		if(r==st.roll)
		{
			cout<<"Enter name of new student = ";
			cin.ignore();
			cin.getline(st.name,50);
			cout<<"Enter roll number of student = ";
			cin>>st.roll;
		   file.seekp(-sizeof(st),ios::cur);
		   file.write((char*)&st,sizeof(st));
		   t=1;
		   break;

		}
	}
	if(t)
	{
		cout<<"congrat modification done \n";

	}
	else
	{
		cout<<"record cannot be found in file \n" ;
	}

}