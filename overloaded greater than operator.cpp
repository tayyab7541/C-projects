#include<iostream>
using namespace std;
class malik 
{
    private:
     int day ,month ,year;
     public:
     malik(int d,int m ,int y ): day(d),month(m),year(y){}
     bool operator>(malik &m);

};
bool malik::operator>(malik &m)
{
    if(day>m.day && month>m.month && year>m.year)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int main()
{
    malik m1(2,10,2006),m2(3,11,2007);
    if(m1>m2)
    {
        cout<<"date 1 is greater \n";
    }
    else
    {
        cout<<"date 2 is greater \n";
    }
    return 0;
}