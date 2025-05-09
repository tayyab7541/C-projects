#include<iostream>
#include<fstream>
#include<cstring>
#include<limits>
#include<cctype>
using namespace std;
struct student
{
	char name[50];
	int roll;
    int age;
    int semister;
    int gpa;
	
};
int main()
{
	fstream project;
	student st;
	bool found =1;
	char ch; int search;
	int num;
    project.open("F:\\test files\\malik.dat",ios::binary|ios::app);
    if(!project)
    {
        cout<<"file cannot be opened";
    }
    else
    {
        cout<<"file is opened now enter your choice";
        project.close();
    }

	do
	{
	cout<<"\n \n Main menue \n 1:To add record \n 2:To display all records \n 3:To search data from record \n 4:To delete record \n 5:To modify records\n 6:To sort records  \n 7:To exit \n Enter your choice = ";
		cin>>num;
		if(num==1)
		{
			project.open("F:\\test files\\malik.dat",ios::binary|ios::in);
			if(!project)
			{
				cout<<"file cannot be opened";
			}
			else
			{   
			 do
			 {

			 	bool c;
				  
				do
				{
					  c=0;
					cout<<"Enter name of student = ";
					cin.ignore();
					cin.getline(st.name,50);
					for(int i=0;st.name[i]!='\0';i++)
				  {
					if(!isalpha(st.name[i])&&st.name[i]!=' ')
			    {
				 cout<<"please enter alphabets in name \n\n";
					c=1;
					break;
				}
				 
				  }
				}while(c);
			
				//for roll number
				bool c1;
				student temp;
				do
				{
					 c1=0;
					cout<<"Enter roll number of student = ";
					cin>>st.roll;
					if(cin.fail()||st.roll<=0)
					{
						cin.ignore(numeric_limits<streamsize>::max(),'\n');
						cout<<"Enter number only \n";
						c1=1;
						break;
					}
					while(project.read((char*)&temp,sizeof(temp)))
                     {
                     	if(temp.roll==st.roll)
                     {
                     	cout<<"This roll number already exists \n\n ";
                     	c1=1;
                     	break;
					 }
				      }
				}while(c1);
                cout<<"enter Age of student = ";
                cin>>st.age;
                cout<<"enter semester numer of student = ";
                cin>>st.semister;
                cout<<"enter gpa of student = ";
                cin>>st.gpa;
                project.close();
                project.open("F:\\test files\\malik.dat",ios::binary|ios::app);
                if(!project)
                {
                    cout<<"file cannot be opened \n";
                }
                else
                {
				
			     project.write((char*)&st,sizeof(st));
                }    
				cout<<"Do you want to enter more records[y/N] =";
				cin>>ch;
				
			}while(ch=='y'||ch=='Y');
			
			project.close();
	    	}
     	}
     	else if(num==2)
     	{
     		project.open("F:\\test files\\malik.dat",ios::binary|ios::in);
     		if(!project)
     		{
     			cout<<"file cannot be opened for dispaly";
			 }
			 else
			 { 
                cout<<"Roll# \t Name \t Age \t sem \t Gpa \n";
			 	while(project.read((char*)&st,sizeof(st)))
			 	{
			 		cout<<st.roll<<"\t"<<st.name<<"\t"<<st.age<<"\t"<<st.semister<<"\t"<<st.gpa<<endl;
				 }
			 }
			 project.close();
		 }
         else if(num==3)
         {
            project.open("F:\\test files\\malik.dat",ios::binary|ios::in);
            if(!project)
            {
                cout<<"File cannot be opened to search data";
            }
            else
            {
               
                bool c2=0;
                cout<<"Enter roll number to search record = ";
                cin>>search;
                while(project.read((char*)&st,sizeof(st)))
                {
                    if(st.roll==search)
                    {
                        cout<<st.roll<<"\t"<<st.name<<"\t"<<st.age<<"\t"<<st.semister<<"\t"<<st.gpa<<endl;
                        c2=1;
                        break;
                    }
                    
                }
                if(!c2)
                {
                    cout<<"\n sorry record cannot be founded";
                }
                project.close();
            }
         }
         //for deletion
         else if(num==4)
         {
            fstream temp;
            temp.open("F:\\test files\\temp.dat",ios::binary|ios::out);
            project.open("F:\\test files\\malik.dat",ios::binary|ios::in);
            if(!project)
            {
                cout<<"file cannot be opened";
            }
            else
            {
                if(!temp)
                {
                    cout<<"temp file cannot be opened";

                }
                else
                {
                    bool c3=0;
                    cout<<"enter roll number to delete = ";
                    cin>>search;
                    while(project.read((char*)&st,sizeof(st)))
                    {
                        if(st.roll!=search)
                        {
                            temp.write((char*)&st,sizeof(st));
                        }
                        else
                        {
                            c3=1;
                            continue;
                        }
                    }
                    if(c3)
                    {
                        cout<<"record deleted successfuly";
                    }
                    else
                    {
                        cout<<"record cannot be deleted";
                    }
                    project.close();
                    temp.close();
                    remove("F:\\test files\\malik.dat");
                    rename("F:\\test files\\temp.dat","F:\\test files\\malik.dat");
                }
            }

         }
         else if(num==5)
         {   int i;
             int n=0;
             int size=0;
             student *temp;
             project.open("F:\\test files\\malik.dat",ios::binary|ios::in);
       if(!project)
                  {
                   cout<<"Sorry file cannot be opened \n";
                  }
           
        else
           {
           
            project.seekg(0,ios::end);
            n=project.tellg();
            project.seekg(0,ios::beg);
            size=n/sizeof(st);
            cout<<"number of records in file = "<<size<<endl;
            temp=new student[size];
             i=0;
            while(project.read(reinterpret_cast<char*>(&st),sizeof(st)))
            {
            		
                strcpy(temp[i].name,st.name);
                temp[i].roll=st.roll;
                temp[i].age=st.age;
                temp[i].semister=st.semister;
                temp[i].gpa=st.gpa;
                i++;
            }
            project.close();
           }
           int search;
           cout<<"Enter roll number to modify record = ";
           cin>>search;
           bool check=0;
         for(i=0;i<size;i++)
         {
            if(search==temp[i].roll)
            {
                check=1;
                bool c;
                do
                {
                    c=0;
                    cout<<"Enter name of student = ";
                    cin.ignore();
                    cin.getline(temp[i].name,50);
                   for(int j=0; temp[i].name[j]!='\0';j++)
                   {
                    if(!isalpha(temp[i].name[j])&&temp[i].name[j]!=' ')
                    {
                        cout<<"Please enter name in alphabets";
                        c=1;
                        break;
                    }
                   }
                }while(c);
                bool c1;
                do
                { 
                    c1=0;
                    cout<<"enter roll number of student = ";
                    cin>>temp[i].roll;
                    for(int k=0; k<size;k++)
                    {
                        if(i!=k)
                        {
                       if(temp[i].roll==temp[k].roll)
                        {
                            c1=1;
                            cout<<"This roll number already exists try again\n";
                            break;
                        }
                       }
                       else
                       {
                        continue;
                       }
                    }

                } while (c1);
                cout<<"Enter age of student = ";
                cin>>temp[i].age;
                cout<<"Enter semester number of studnet = ";
                cin>>temp[i].semister;
                cout<<"Enter gpa of student = ";
                cin>>temp[i].gpa;

                
            }
            
         }
        
         if(check)
         {
            project.open("F:\\test files\\malik.dat",ios::binary|ios::out);
            if(!project)
            {
                cout<<"file cannot be opened \n";
            }
            else
            {
                for(i=0;i<size;i++)
                {
                    project.write((char*)&temp[i],sizeof(temp[i]));
                }
               
            }
            project.close();
         }
         else
         {
            cout<<"Sorry the roll number you enterd cannot be found \n";
         }
         delete[] temp;
          
         }
       
         else if(num==6)
         {
            student *ar;
            int size,c;
            project.open("F:\\test files\\malik.dat",ios::binary|ios::in);
            if(!project)
            {
                cout<<"sorry file cannot be opened \n";
            }
            else
            {
               project.seekg(0,ios::end);
               c=project.tellg();
               project.seekg(0,ios::beg);
               size=c/sizeof(st);
               cout<<"number of records = "<<size;
               ar=new student[size];
               int i=0;
               while(project.read(reinterpret_cast<char*>(&st),sizeof(st)))
               {
                strcpy(ar[i].name,st.name);
                ar[i].roll=st.roll;
                ar[i].age=st.age;
                ar[i].semister=st.semister;
                ar[i].gpa=st.gpa;
                i++;
               }
               student temp;
               for(int i=0;i<size-1;i++)
               {
                for(int j=0;j<size-i;j++)
               {
                       if(ar[j].roll>ar[j+1].roll)
                       {
                        temp=ar[j];
                        ar[j]=ar[j+1];
                        ar[j+1]=temp;
                       }
               }
               }
               project.close();
               project.open("F:\\test files\\malik.dat",ios::binary|ios::out);
               if(!project)
               {
                cout<<"file cannot be opened to write sorted records \n";
               }
               else
               {
               for(int i=0;i<size;i++)
               {
                project.write((char*)&ar[i],sizeof(ar[i]));
               }
               cout<<"\n to display the records sorted in file press 2";
               project.close();
               }
            }

         }
     	else if(num==7)
     	{
     		found=0;
		 }
		 else
		 {
		 	cout<<"Invalid input";
		 }
	}while(found);
}
