#include<iostream>
#include<iomanip>
#include<fstream>
#include<cstring>
#include<stdio.h>
#include<cstdlib>
#include<string>
using namespace std;

 //structure 
 struct student 
      {
        char name[40];
        int id;
        int age;
        int semister;
        float gpa;
      };
      int n=0;

void add(student[],int size);
void display(student[],int size );
void namesort(student[],int size);
void binarysort(student[],int size);
void sorting(student[],int size);
void namesearch(student[],int size);
void idsearch(student [],int size);
void search(student [],int size);
void del(student[],int size);
void modify(student[],int size);
void namedel(student[],int size);
void iddel(student[],int size);
      //main starts here

  int main()
      {
       const int s=50;
        student std[s];
        char ch;
        bool found =1;
        do 
        {
            cout<<"\n enter (A) to add record= \n";
            cout<<"\n enter (D) to display record= \n";
            cout<<"\n enter (S) to sort recods= \n";
            cout<<"\n enter (O) to search records= \n";
            cout<<"\n enter (T) to delete record of a student: \n";
            cout<<"\n enter (M) to modify the record of student : \n";
            cout<<"\n please enter (E) to exit= \n";
            cout<<"please enter your choice=>";
            cin>>ch;
            if(ch=='A'||ch=='a') 
            {
                add(std,s);
            }
            else if(ch=='D'||ch=='d')
            {
                display(std,s);
            }
            else if(ch=='s'||ch=='S')
            {
                sorting(std,s);
            }
            else if(ch=='o'||ch=='O')
            {
                search(std,s);
            }
            else if(ch=='t'||ch=='T')
            {
                del(std,s);
            }
            else if(ch=='m'||ch=='M')
            {
                modify(std,s);
            }
            else if(ch=='E'||ch=='e')
            {
                found=0;
            }
            else
             {
                cout<<"please enter the number from given choice:";
            }

        }
        while(found);
      }

      //functions 
      void add(student ad[],int size)
      {  
        char ide[7],ag[5],semister[8],gp[9],ch;
        do
        {  
            if(n<size)
            {
        cout<<"please enter the record: \n";
        cin.ignore();   
         cout<<"please enter the name of student:";
        cin.getline(ad[n].name,40);
          cout<<"please enter your id:";
           cin.getline(ide,7);
          ad[n].id=atoi(ide);
          cout<<"enter the age of student:";
          cin.getline(ag,5);
          ad[n].age=atoi(ag);
          cout<<"enter semister of student:";
          cin.getline(semister,8);
          ad[n].semister=atoi(semister);
          cout<<"enter gpa of the student :";
          cin.getline(gp,9);
           ad[n].gpa=atof(gp);
            }

        n++;
        cout<<"if you want to go in main menu please enter Y if no then N";
        cin>>ch;
        }while(ch=='N'||ch=='n');

      }
      //display function
      void display(student dis[],int size)
      {
        if(n>0)
        {  cout<<"********************************************\n";
                cout<<"**********************************************\n";
             cout<<"name \tid  age \t semester  \t gpa\n";
             cout<<"***********************************************\n";                   cout<<"***************************************************\n";
        int i;
        for(i=0;i<n;i++)
        {
            cout<<dis[i].name<<"\t \t"<<dis[i].id<<"\t \t"<<dis[i].age<<"\t \t"<<dis[i].semister
            <<"\t \t"<<dis[i].gpa<<endl;
        }
        }
        else 
      {
        cout<<"no record enterd";
      }

      }

      //function to sort by name
      void namesort(student nsort[],int size)
      {
          int i;
         student temp;
           if(n>1)
          {
        for(i=0;i<n-1;i++)
        {
            if(strcmp(nsort[i].name,nsort[i+1].name)>0)
            {
                temp=nsort[i];
                nsort[i]=nsort[i+1];
                nsort[i+1]=temp;
            }
        }
        cout<<"************************************************\n";
              cout<<"************************************************\n";

          cout<<"name \t id \t age \t semester \t gpa  \n";
          cout<<"******************************************************\n";
                 cout<<"******************************************************\n";
        for(i=0;i<n;i++)
        {
            cout<<nsort[i].name<<"\t \t"<<nsort[i].id<<"\t \t"<<nsort[i].age
            <<"\t"<<nsort[i].semister<<"\t \t"<<nsort[i].gpa<<endl;
        }
          }
          else
          {   i=0;
            cout<<"name \t id \t age \t semester \t gpa  \n";
            cout<<nsort[i].name<<"\t"<<nsort[i].id<<"\t"<<nsort[i].age
            <<"\t"<<nsort[i].semister<<"\t"<<nsort[i].gpa<<endl;
          }
      }

      //function to sort from binary number
      void binarysort(student bsort[],int size)
      { 
        student temp;
        int i;
        if(n>1)
        {
        for(i=0;i<n-1;i++)
        {
           if(bsort[i].id>bsort[i+1].id)
           {
            temp=bsort[i];
            bsort[i]=bsort[i+1];
            bsort[i+1]=temp;
           }
        }

        cout<<"***********************************************\n";
               cout<<"***********************************************\n";

        cout<<"name \t id  \t age \t semester \t gpa \n";
        cout<<"***********************************************\n";
              cout<<"***********************************************\n";
        for(i=0;i<n;i++)
        {
            
            cout<<bsort[i].name<<"\t \t"<<bsort[i].id<<"\t \t"<<bsort[i].age<<"\t \t"
            <<bsort[i].semister<<"\t \t"<<bsort[i].gpa<<endl;
        }
        }
        else 
        { 
            i=0;
             cout<<"****************************************************\n";
                   cout<<"*****************************************************\n";
             cout<<"name \t id\t age \t semester \t gpa  \n";
             cout<<"******************************************************\n";
                    cout<<"*******************************************************\n";
            cout<<bsort[i].name<<"\t \t"<<bsort[i].id<<"\t\t "<<bsort[i].age<<"\t \t"
            <<bsort[i].semister<<"\t \t"<<bsort[i].gpa<<endl;
        }
        
      } 
    //main function of sorting
      void sorting(student s[],int size)
      {
        char ch;
        bool found =1;
        if(n>0)
        {
        do
        {
            cout<<"enter (N) for name sorting = \n";
            cout<<"enter (I) for id sorting = \n";
            cin>>ch;
            if(ch=='n'||ch=='N'||ch=='i'||ch=='I')
            {
                found=0;
            }
            else 
            {
                cout<<"please enter correct number=";
            }
           
        }while(found);

        if(ch=='n'||ch=='N')
        {
            namesort(s,size);
        }
        else if(ch=='i'||ch=='I')
        {
            binarysort(s,size);
        }
        }
        else
        {
            cout<<"there is no record yet";
        }

      }
      //function to search the records by name
      void namesearch(student nsearch[],int size)
      {
        int i;
        char nam[40];
        cout<<"enter the name you want to search=";
        gets(nam);
        for(i=0;i<n;i++)
        {
            if(strcmp(nam,nsearch[i].name)==0)
            {   
                cout<<"The name you enterd is present in the record";
            }
            else
            {
                cout<<"The name you enterd is not present";
            }
        }
      }
      //function to sort the records from id
void idsearch(student id[],int size)
{
    int i,num;
    cout<<"please enter the ID you want to search :";
    cin>>num;
    for(i=0;i<n;i++)
    {
        if(num==id[i].id)
        {
            cout<<"The Id you enterd is found ";
        }
        else 
        {
            cout<<"The Id you enterd is not found ";
        }
    }
}
  
  //main function to search the records
void search(student search[],int size)
{
    char ch;
    
    bool found;
    found=1;
    if(n>0)
    {
    do
    { 
        cout<<"Enter (N) to search by name \n Enter the (I) to search by ID=";
        cin>>ch;
        if(ch=='n'||ch=='N'||ch=='i'||ch=='I')
        {
            found=0;
        }
        else 
        {
        cout<<"please enter the correct letter:";
        }
    }while(found);

   //calling function of searching

   if(ch=='n'||ch=='N')
   {
    namesearch(search,size);
   }
   else
   {
    idsearch(search,size);
   }
    }
    else
    {
        cout<<"you have not enterd any record";
    }
}
//function to delete the records
//function to modify the values in records
void modify(student mod[],int size)
{
    int num,k,i;
    
    char nam[40];
  char L[10],ag[9],sem[9],gp[9];
    if(n>0)
    {
        char ch;
        cout<<"enter n for name and i for id=";
        cin>>ch;
        if(ch=='n'||ch=='N')
        {
             
        cout<<"enter the name of which record is to be modified=";
        cin.ignore();
        cin.getline(nam,40);
        for(i=0;i<n;i++)
        {
            if(strcmp(nam,mod[i].name)==0)
            { 
    cout<<"***************************************************\n";
          cout<<" ****************************************************\n";
  cout<<"name \t ID\t age \t semester \t gpa  \n ";
  cout<<"*******************************************************\n";
      cout<<"********************************************************\n";
    cout<<mod[i].name<<"\t \t"<<mod[i].id<<"\t \t"<<mod[i].age<<"\t \t"
    <<mod[i].semister<<"\t \t"<<mod[i].gpa<<endl;
    cout<<"now enter the new record:";
    cin.ignore();
  cout<<"\n enter the name of student: ";
 gets(mod[i].name);
  cout<<"enter the id of student : ";
  cin.getline(L,10);
  mod[i].id=atoi(L);
  cout<<"enter the age of stdent:";
  cin.getline(ag,9);
  mod[i].age=atoi(ag);
  cout<<"enter semester of the student:";
  cin.getline(sem,9);
  mod[i].semister=atoi(sem);
  cout<<"enter the gpa of student:";
  cin.getline(gp,9);
  mod[i].gpa=atof(gp);
  
            }
            else
            {
                cout<<"The name you enterd is not present";
            }
        }
        }
        else if(ch=='i'||ch=='I')
        {
            cout<<"enter the id of student of which data is to be modified:";
            cin>>k;
    for(i=0;i<n;i++)
    {
        if(k==mod[i].id)
        {
             cout<<"************************************************* \n";
            cout<<"************************************************** \n";
  cout<<"name \t ID\t age \t semester \t gpa  \n ";
  cout<<"*****************************************************\n";
        cout<<" *****************************************************\n";
    cout<<mod[i].name<<"\t \t"<<mod[i].id<<"\t\t"<<mod[i].age<<"\t\t"
    <<mod[i].semister<<"\t\t"<<mod[i].gpa<<endl;
    cout<<"now enter new record of student:";
     cin.ignore();
  cout<<"\n enter the name of student: ";
 gets(mod[i].name);
  cout<<"enter the id of student : ";
  cin.getline(L,10);
  mod[i].id=atoi(L);
  cout<<"enter the age of stdent:";
  cin.getline(ag,9);
  mod[i].age=atoi(ag);
  cout<<"enter semester of the student:";
  cin.getline(sem,9);
  mod[i].semister=atoi(sem);
  cout<<"enter the gpa of student:";
  cin.getline(gp,9);
  mod[i].gpa=atof(gp);
  cout<<"\n \n now record has been modified";

        }
        else 
        {
            cout<<"The Id you enterd is not found ";
        }
    }
        }

    }
}

void namedel(student nam[],int size)
{
    int i,j;
    char ch[40],c;
    bool found=0;
    cout<<"please enter the name of student of which record is be deleted:";
    cin.ignore();
    cin.getline(ch,40);
    cout<<"Are you surre you want to delete record (y of N) : ";
    cin>>c;
    if(c=='y'||c=='Y')
    {
    
    for(i=0;i<n;i++)
    {
        if(strcmp(ch,nam[i].name)==0)
        {
            for(j=i;j<n-1;j++)
            {
                nam[j]=nam[j+1];
            }
            found=1;
            n--;
          break; 
        }
    }
    if(found==1)
    {
        cout<<"name \t id \t age \t semister \t gpa\n";
        for(j=0;j<n;j++)
        {
            cout<<nam[j].name<<"\t"<<nam[j].id<<"\t"<<nam[j].age<<"\t"<<nam[j].semister<<"\t"<<nam[j].gpa<<endl;
        }

    }
    else
    {
            cout<<"the name you enterd is not found";
    }
    }
}
 
 void iddel(student id[],int size)
 {
    int i,j,num;
    char ch;
    bool found=0;
     cout<<"enter the id of student of which record is to be deleted";
     cin>>num;
     cout<<"Are you surre you want to delete record(y of N): ";
     cin>>ch;
     if(ch=='Y'||ch=='y')
     {
     for(i=0;i<n;i++)
     {
        if(num==id[i].id)
        {
            for(j=i;j<n-1;j++)
            {
               id[j]=id[j+1];
            }
            found=1;
             n--;
            break;
           
        }
     }
     if(found==1)
    {
        cout<<"name \t id \t age \t semister \t gpa\n";
        for(j=0;j<n;j++)
        {
            cout<<id[j].name<<"\t"<<id[j].id<<"\t"<<id[j].age<<"\t"<<id[j].semister<<"\t"<<id[j].gpa<<endl;
        }

    }
    else
    {
            cout<<"the id you enterd is not found";
    }
     }
     

 }
 void del(student d[],int size)

  {  
     if(n>0)
     {
     char ch;
    cout<<"enter your choice delete record of student with name or id (N to delete by name and I to delete by id)=";
    cin>>ch;
    if(ch=='n'||ch=='N')
    {
        namedel(d,size);
    }

    else if(ch=='i'||ch=='I')

    {
        iddel(d,size);
    }
else 
{
    cout<<"you enterd incorrect input ";
}
     }
     else
     {
        cout<<"There is no record to be deleted";
     }
 }