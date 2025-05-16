#include<iostream>
using namespace std;
template <class t>
class assign
{
    private:
    t day,month,year;
    public:
    assign() {} //default constructure 
    assign(t d,t m,t y): day(d),month(m),year(y) {}  //member initializer list
    assign<t> operator=(const assign<t> &other)
    {
        day=other.day;
        month=other.month;
        year=other.year;
        return *this;
    }
    void show()
    {
        cout<<"Date is \n";
        cout<<this->day<<"-"<<this->month<<"-"<<(*this).year<<endl;
    }
};

int main()
{
    assign <int> d1(2,11,2003),d2(3,7,2005),d3(2,10,2006);
    cout<<"Date 1 before assigning \n";
    d1.show();
    cout<<"Date 2 before assigning \n";
    d2.show();
    cout<<"Date 3 before assigning \n";
    d3.show();
    d1=d2=d3;
    cout<<"Date 1 after assigning \n";
    d1.show();
    cout<<"Date 2 after assigning \n";
    d2.show();
    cout<<"Date 3 after assigning \n";
    d3.show();
    return 0;
}