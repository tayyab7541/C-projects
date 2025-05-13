#include<iostream>
using namespace std;
class date
{
    private:
    int day,month,year;
    public:
    date(){} //default constructure 
    date(int d,int m,int y): day(d),month(m),year(y){}
    void show()
    {
        cout<<day<<"-"<<month<<"-"<<year<<endl;
    }
    void swap(date *p)
    { 
        //swapping days
        int temp;
        temp=p->day;
        p->day= day;
        day=temp;
       //swaping month
       temp=p->month;
       p->month=month;
       month=temp;
       //swaping year
       temp=p->year;
       p->year=year;
       year=temp;
    }
};
int main()
{
    date tdob(2,10,2006),fdob(6,7,2008);
    cout<<"Tayyab date of birth \n";
    tdob.show();
    cout<<"Fahad date of birth \n";
    fdob.show();
    
    tdob.swap(&fdob);
    cout<<"After swaping Tayyab DOB \n";
    tdob.show();
    cout<<"After swaping Fahad DOB \n ";
    fdob.show();
    return 0;
}