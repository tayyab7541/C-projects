#include<iostream>
using namespace std;
class date
{
    private:
    int day,month,year;
    public:
    date() {}
    date(int d,int m,int y)
    {
        day=d;
        month=m;
        year=y;
    }
    friend class b;

};
class b
{
    public:
    date d1,d2;
    void check()
    {
        double num,num1;;
        num=d1.day+d1.month*30+d1.year*12*30;
        num1=d2.day+d2.month*30+d2.year*12*30;
         if((num==num1))
         {
            cout<<"Both dates are equal ";
         }
         else if(num>num1)
         {
            cout<<d1.day<<"-"<<d1.month<<"-"<<d1.year<<"is greater date \n";
         }
         else
         {
            cout<<"date "<<d2.day<<"-"<<d2.month<<"-"<<d2.year<<" is greater \n";
         }
    }
};
int main()
{
    date d1(2,10,2006),d2(4,10,2006);
    b obj;
    obj.d1=d1;
    obj.d2=d2;
    obj.check();
    return 0;
}