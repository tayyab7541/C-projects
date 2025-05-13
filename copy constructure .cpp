#include<iostream>
using namespace std;
class date
{
    private:
    int day,month,year;
    public:
    date() {}
    date(int d,int m,int y):day(d),month(m),year(y) {}
    date(const date &);//copy constructure 
    void show();//function to dsipaly values 
};

date::date(const date& date2)
{
    day=date2.day;
    month=date2.month;
    year=date2.year;

}
void date::show()
{
    cout<<"Date is \n";
    cout<<day<<"\t"<<month<<"\t"<<year<<endl;
}
int main()
{
    date d1(2,10,2006);
    date d2(d1);
    d2.show();
    return 0;
}