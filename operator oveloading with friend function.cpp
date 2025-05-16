#include<iostream>
using namespace std;
template <class t>
class date
{
    t day,month,year;
    public:
    date()   {}  //default constructure
    date(t d,t m,t y)
    {
    day=d;
    month=m;
    year=y;
    }
    friend bool operator==(const date<t> &obj1 ,const date<t> &obj2)
    {
          if(obj1.day==obj2.day&&obj1.month==obj2.month&&obj1.year==obj2.year)
    {
        return 1;
    }
    else
    {
        return 0;
    }
    }
};


int main()
{
    date <int> d1(2,10,2006),d2(2,10,3006);
    if(d1==d2)
    {
        cout<<"both dates are equal \n";

    }
    else
    {
        cout<<"dates are not equal \n";

    }
    return 0;
}

