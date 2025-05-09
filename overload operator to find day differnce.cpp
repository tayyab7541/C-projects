#include<iostream>
using namespace std;
class malik
{
    private:
    int day,month,year;
    public:
    malik() {} //default constructure
    malik(int d,int m, int y):day(d),month(m),year(y){}
    int operator-(malik m);
};
int malik::operator-(malik m)
{
    int t1,t2;
    t1=day+month*30+year*360;
    t2=m.day+m.month*30+m.year*360;
   return t1-t2;
}
int main()
{
malik d1(2,10,2006),d2(3,10,2006);
int result;
result=d2-d1;
cout<<"difference in date is = "<<result<<" days\n ";
return 0;
}