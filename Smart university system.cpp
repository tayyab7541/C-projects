

#include<iostream> 
#include<string>
#include<cmath>
#include<stdio.h>

using namespace std;

int calsum(int n1,int n2 ); //recursive function to calculate sum of two numbers 
double powercal(int num,int pow); //recursive function to calculate power of number
class course; // this is forward declaration


template <class t>
class calculator
{
    protected:
    int num_of_subject;
    t *marks,*credit_h;
    public:
    calculator() //defualt constructure
    {}

     void in(t *ar,t *credit,t n,t i); // recusive function to input data 
     t cal(t *ar,t *credit,t n,t i,t gpa);  //recursive function to calculate gpa

    void input() 
    { 
        t gpa,gp;
        gp=0;
        cout<<"Enter number of subjects = ";
        cin>>num_of_subject;
        marks=new t[num_of_subject];
        credit_h=new t[num_of_subject];
        in(marks,credit_h,num_of_subject,0); //calling recursive function to input
        gpa=cal(marks,credit_h,num_of_subject,0,gp);  //calling recursive function to calculate gpa
        cout<<"your gpa is = "<<gpa<<endl;
     }
     

};





class User  // parent class
{
    protected: //data members
    string name;
    int id;
    static int count_user; //static member to count users

    public:
    User() //default constructure
    {
        count_user++;
    } 
    virtual void displayinfo()=0;
    virtual void calculate_performane()=0;
    static int getvalue()
    {
        return count_user;
    }
};

int User::count_user=0; //initializing static data member
class student:public User  //first child class
{
     protected:
     double fee;
     int semester;
     public:
     void inputinfo(); //it is used to input data members of student class  
     void displayinfo() //overriding pure virtual function
     {
    cout<<"Name  \t ID  \t Fee \t semester# \n";
    cout<<name<<"\t"<<id<<"\t"<<fee<<"\t"<<semester<<endl;
      }

      void calculate_performane()//overriding pure virtual function
      {
           calculator<int> c;
           c.input();
      }

    friend void fun(student&,course&); //declaration of friend function

};
class teacher:public User  //this is second child class
{
    protected:
    int year_of_experience;
    double pay;
    public:
    void inputinfo();
    void calculate_performane()//overriding pure virtual function
    {

    }
    void displayinfo() //overriding pure virtual function
    {
       cout<<"Name \t         ID \t years of exp \t pay \n";
     cout<<name<<"\t \t"<<id<<"\t"<<year_of_experience<<"\t \t"<<pay<<endl;

    }
};



class course
{
    protected:
              string name;
              int id;
              double fee;
              int semester;
              public:
              void input();
              friend void fun(student&,course&);
            friend  ostream operator<<(ostream &st,course& c)
            {
                st<<c.name<<"\t"<<c.id<<"\t"<<c.fee<<"\t"<<c.semester<<endl;
            }


};


//Main starts here


int main()
{
    bool found=1;
    int num;
    do
    {
        cout<<"Welcome to Smart University Managment system \n =============================================== \n 1.To creat student \n 2. To creat professor  \n 3. To calculate GPA \n 4. To assign course \n 5. To find sum to two numbers recursively  \n 6 . To find power of number\n7:To calculate performance of student\n8:to calculate performance of teacher \n9. To exit \n  Enter your coice = ";
        cin>>num;
        if(num==1)
        {
         User  *u; //pointer of parent class as it is abstract class

          student st; // object of first child class
          u=&st;
          st.inputinfo();
          st.displayinfo();
          cout<<endl;
          cout<<"Number of users = "<<u->getvalue()<<endl;
          delete u;
        }
        else if(num==2)
        {
            teacher tech; //object of second child class
            tech.inputinfo();
            tech.displayinfo();
            cout<<endl;
            cout<<"Number of users = "<<tech.getvalue()<<endl;
        }

        else if(num==3)
        {
             calculator<int>  cu; // clreating object of claculator class with int data type
             cu.input();
        }
        else if(num==4)
        {
            course c;
            student st;
            c.input();
            fun(st,c);
            cout<<c;
            cout<<"Students record displayin via student class function \n";
            st.displayinfo();
            
        }

        else if(num==5)
        {
            int n1,n2;
            cout<<"Enter first number = ";
            cin>>n1;
            cout<<"Enter second number = ";
            cin>>n2;
            cout<<"sum of two numbers = "<<calsum(n1,n2)<<endl;
        }
        else if(num==6)
        {
            int num1,num2;
            cout<<"Enter number = ";
            cin>>num1;
            cout<<"Enter power of number = ";
            cin>>num2;
            cout<<"so power of number is = "<<powercal(num1,num2)<<endl;
        }
        else if(num==7)
        {
            student st;
            st.calculate_performane();
            st.displayinfo();

        }



        else if(num==9)
        {
            found=0; 
        }
        else
        {
            cout<<"Enter correct number \n";
        }

    }while(found);

}

template<class t> void calculator<t>::in(t *ar,t *credit,t n,t i) //recursive function to input marks and credit hours 
{
  if(n==0)
  {
    return ;
  }
  if(i==n)
  {
    return ;
  }
  else
  {
    cout<<"Enter your marks in "<<i+1<<" subjec = ";
    cin>>ar[i];
    cout<<"Enter credit hours of that course = ";
    cin>>credit[i];
    in(ar,credit,n,i+1);
  }
}

template <class t>t calculator<t>::cal(t *ar,t *credit,t n,t i,t gpa) //recursive function to calculate gpa 
{
    if(n==0)
    {
        return 0;
    }
    if(i==n)
    {
        int sum=0;
        for(int j=0;j<n;j++)
        {
            sum+=credit[j];
        }
        return gpa/sum;
    }
    else
    {
        if(ar[i]>=80&&ar[i]<=100)
        {
            return  cal(ar,credit,n,i+1,gpa+=credit[i]*4);
        }
        else if(ar[i]>=75&&ar[i]<80)
        {
            return  cal(ar,credit,n,i+1,gpa+=credit[i]*3.5);
        }
        else if(ar[i]>=70&&ar[i]<75)
        {
           return  cal(ar,credit,n,i+1,gpa+=credit[i]*3);
        }
        else if(ar[i]>=65&&ar[i]<70)
        {
            return cal(ar,credit,n,i+1,gpa+=credit[i]*2.5);
        }
        else if(ar[i]>=60&&ar[i]<65)
        {
            return cal(ar,credit,n,i+1,gpa+=credit[i]*2);
        }
        else if(ar[i]>=55&&ar[i]<60)
        {
            return cal(ar,credit,n,i+1,gpa+=credit[i]*1.5);
        }
        else if(ar[i]>=50&&ar[i]<55)
        {
            return cal(ar,credit,n,i+1,gpa+=credit[i]*1);
        }
        else 
        {
            return  cal(ar,credit,n,i+1,gpa+=credit[i]*0);
        }
    }
}

int calsum(int n1,int n2) //recursive function to calculate sum of two numbers 
{
    if(n2==0)
    {
        return n1;
    }
    if(n2>0)
    {
        return calsum(n1+1,n2-1);
    }
    else
    {
        return calsum(n1-1,n2+1);
    }
}


double powercal(int num1,int pow) //recursive function to calculate powere of number 
{
    if(pow==0)
    {
        return 1;
    }
    if(pow>0)
    {
    return num1* powercal(num1,pow-1);
    }
    else
    {
        return 1/powercal(num1,-pow);
    }
}

void student::inputinfo()  //method of student class to input data members 
{

    cout<<"Enter name of student = ";
    cin.ignore();
    getline(cin,name);
    cout<<"Enter ID of student = ";
    cin>>id;
    cout<<"Enter Fee of student = ";
    cin>>fee;
    cout<<"Enter current semester of student = ";
    cin>>semester;
}
void teacher::inputinfo() //method of teacher class to input data 
{
    cout<<"Enter name = ";
    cin.ignore();
    getline(cin,name);
    cout<<"Enter id of teacher = ";
    cin>>id;
    cout<<"Enter year of experience = ";
    cin>>year_of_experience;
    cout<<"Enter you pay = ";
    cin>>pay;
}

void fun(student& st,course& other) 
{
    st.name=other.name;
    st.id=other.id;
    st.fee=other.fee;
    st.semester=other.semester;
}

void course::input()  //function to input data in course class
{
    cout<<"Enter student name = ";
    cin.ignore();
    getline(cin,name);
    cout<<"Enter id = ";
    cin>>id;
    cout<<"enter fee = ";
    cin>>fee;
    cout<<"enter semester number = ";
    cin>>semester;
}