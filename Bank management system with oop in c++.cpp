#include<iostream>
#include<cstring>
#include<string>

using namespace std;   int n=0;


class user
{
    protected:
    char name[40];
    string contact_number;

    public:
   
    virtual void transaction(user* a)=0;
    virtual string accounts()=0;
};

class customer:public user
{  
    protected:
    double account_number,balance;
    string account_type;

    public:

    void operator==(customer *p);
     void transaction(user * a) override
     {
        customer *p=(customer*)a;
          char ch;
          int i;
           double pin,amount;
          bool found=1;
          if(n>0) //to ensure that there should be atleat one record of customer
          {
          do
          {
          cout<<"D:To deposite money in account\nW:To withdraw money from account\nV:To view balance\nC:To close menue\nEnter your choice = ";
          cin>>ch;
          if(ch=='d'||ch=='D')
          {
            cout<<"Enter pin of your account to continue = ";
            cin>>pin;
            for(i=0;i<n;i++)
            {
                if(pin==p[i].account_number)
                {
                    cout<<"Enter amount = ";
                    cin>>amount;
                    if(amount>0)
                    {
                    p[i].balance +=amount;
                    }
                    else
                    {
                        cout<<"you can enter balance greater than zero \n ";
                    }
                }
             
            }
          }

          else if(ch=='w'||ch=='W')
        {
            bool check=0;
            cout<<"Enter pin to acces your account =";
            cin>>pin;
            for(i=0;i<n;i++)
            {
                if(pin==p[i].account_number)
                {
                    cout<<"Enter amount to withdraw = ";
                    cin>>amount;
                    if(amount>0&&p[i].balance>amount)
                    {
                        p[i].balance-=amount;
                        cout<<"Withdrawl done ";
                        check=1;
                        break;
                    }

                }

            }

            if(!check)
            {
              cout<<"Your transaction could not be completed \n ";
            }
        }


        else if(ch=='v'||ch=='V')
        {
            cout<<"Enter pin to view your balance = ";
            cin>>pin;
            for(i=0;i<n;i++)
            {
                if(pin==p[i].account_number)
                {
                     cout<<"Your account balance = "<<p[i].balance<<endl;
                }
            }
        }

        else if(ch=='c'||ch=='C')
        {
            found =0;
        }
        }while(found);
     }
     else
     {
        cout<<"There is no account first creat an account then you can proceed this function \n";
     }
     }
     string accounts()
     {
        string ac;
        
         cout<<"Enter your account type [saving, current] enter in small alphabets =";
         cin>>ac;
         return ac;
        
     }
     void add(customer u[],int size);
    void del(customer u[]);
    void mod(customer u[]);
    void dis(customer u[]);

};


int main()
{ const int size=50;
    customer c[size];
    int num;
    bool found=1;
    do
    {
        cout<<"1:To add account \n2:To modify account \n3:To delete account \n4:To display all records\n5:To perform operation on account balance\n6:To compare balance of accounts\n7:To exit \nEnter your choice =";
        cin>>num;
        if(num==1)
        {
            c[0].add(c,size);
        }
        else if(num==2)
        {
            c[0].mod(c);
        }
        else if(num==3)
        {
            c[0].del(c);
        }
        else if(num==4)
        {
            c[0].dis(c);
        }
        else if(num==5)
        {
            c[0].transaction(c);
        }
        else if(num==6)
        {
            c[0]==c;
        }
        else if(num==7)
        {
            found =0;
        }
    } while (found);
    
    return 0;
}



 void customer::dis(customer u[])  //method to display records 
 {
    int i;
    if(n>0)
    {
    for(i=0;i<n;i++)
    { 
        cout<<"For "<<i+1<<" customer \n";
        cout<<"Name of customer = "<<u[i].name<<endl;
        cout<<"contact number of customer = "<<u[i].contact_number<<endl;
        cout<<"Account type = "<<u[i].account_type<<endl;
        cout<<"Pin of account = "<<u[i].account_number<<endl;
        cout<<"current balance in your account = "<<u[i].balance<<endl;
    cout<<"=========================\n========================= \n";

    }
   
   }
   else 
   {
    cout<<"No account found \n ";
   }
 }


 void customer::add(customer u[],int size) //method to add records 
{
    int num;

    do
    {
      if(n<size)
      {
        cout<<"Enter Account holder name = ";
        cin.ignore();
        cin.getline(u[n].name,40);

           bool c;
        do //to make pin unique for every account 
        {
            c=0;

        cout<<"Enter Pin you want to use to secure your account = ";
        cin>>u[n].account_number;
        for(int i=0;i<n;i++)
        {
           if(i!=n&&u[n].account_number==u[i].account_number)
           {
            cout<<"Enter different pin it already exist for an account \n";
            c=1;
            break;
           }
        }
        }while(c);


        u[n].account_type=accounts();  //calling pure virtual fuction to get account type 
        cout<<"Enter balance = ";
        cin>>u[n].balance;
    if(u[n].account_type=="saving") //if your account is saving then it will add interest for five years in your acount
        {
            for(int i=0;i<5;i++)
            {
                u[n].balance+=u[n].balance*0.03;
            }
        }



        do
        {

             bool found=false;
            cout<<"please enter your contact number = ";
            cin>>u[n].contact_number;
            for(int i=0;i<n;i++)
            {
                if(u[i].contact_number==u[n].contact_number) //checking if contact number already exists 
                {
                    found =1;
                }
            }
            if(found)
            {
                cout<<"please enter different number \n";
                continue;
            }
            else 
            {
                break;
            }
           
            
        } while (1);
        
        n++;
      }
      cout<<"To enter more record press 1 = ";
      cin>>num;

    } while (num==1);
    
}

void customer::del(customer u[])
{
    int i,j,pin;
    bool found=0;
    cout<<"Enter pin of account number to be deleted = ";
    cin>>pin;
    for(i=0;i<n;i++)
    {
        if(pin==u[i].account_number)
        {
            for(j=i;j<n-1;j++)
            {
                u[j]=u[j+1];
            }
            found =1;
            n--;
        }
    }
    if(found)
    {
        cout<<"Your account has been deleted \n";
    }
    else
    {
        cout<<"Account is not found in list \n";
    }
}



void customer::mod(customer u[])
{
    int i,pin;
    bool check=0;
    cout<<"Enter pin of account to modif account info = ";
    cin>>pin;
    for(i=0;i<n;i++)
    {
        if(pin==u[i].account_number)
        {
            check=1;
          cout<<"Enter Account holder name = ";
          cin.ignore();
        cin.getline(u[i].name,40);
        cout<<"Enter Pin you want to use to secure your account = ";
        cin>>u[i].account_number;
        u[i].account_type=accounts();
        cout<<"Enter balance = ";
        cin>>u[i].balance;
         if(u[i].account_type=="saving")
        {
            for(int j=0;j<5;j++)
            {
                u[i].balance+=u[i].balance*0.03;
            }
        }



        do
        {

             bool found=false;
            cout<<"please enter your contact number = ";
            cin>>u[i].contact_number;
            for(int j=0;j<n;j++)
            {
                if((j!=i)&&(u[i].contact_number==u[j].contact_number))
                {
                    found =1;
                }
            }
            if(found)
            {
                cout<<"please enter different number \n";
                continue;
            }
            else 
            {
                break;
            }
           
            
        } while (1);
        
        }
    }


    if(check)
    {
        cout<<"Your account has been modified \n";
    }
    else
    {
        cout<<"You enter wrong account number \n";
    }
}


void customer::operator==(customer* p)
{
    if(n>1)
    {
    for(int i=1;i<n;i++)
    {
    if(this->balance==p[i].balance)
    {
        cout<<"Yes balance of first customer is equal to Balance of "<<i+1<<" customer \n";
         cout<<"For "<<i+1<<" customer \n";
        cout<<"Name of customer = "<<p[i].name<<endl;
        cout<<"contact number of customer = "<<p[i].contact_number<<endl;
        cout<<"Account type = "<<p[i].account_type<<endl;
        cout<<"Pin of account = "<<p[i].account_number<<endl;
        cout<<"current balance in your account = "<<p[i].balance<<endl;
    cout<<"=========================\n========================= \n";
        break;
    }
    }
   }
   else
   {
    cout<<"There must to be at least two accounts to compare balance \n ";
   }
}
