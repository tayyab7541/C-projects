#include<iostream>
#include<string>
using namespace std;
class vehicle
{
    public:
    string name ;
    int reg_num;
    int model;
   

    void input()
    {
    cout<<"Name of vehicle = ";
    getline(cin,name);
    cout<<"Registration number of vehicle = ";
    cin>>reg_num;
    cout<<"Model of vehicle = ";
    cin>>model;
    }
};
class car:public virtual vehicle
{   public:
    
    void dis()
    {
        input();


        cout<<"\n \n "<<name<<"\t "<<reg_num<<"\t"<<model<<endl;
    }
};
class truck :public virtual vehicle 
{
     public:
void dis()
{
    input();


    cout<<"\n \n "<<name<<"\t "<<reg_num<<"\t"<<model<<endl;
}
 };
int main()
{
    car c;
    truck tr;
    c.dis();
    cout<<"\n \n \n ";
    tr.dis();
    return 0;

}
