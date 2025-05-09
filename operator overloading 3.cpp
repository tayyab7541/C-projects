#include<iostream>
using namespace std;
class date
{
    private:
    int day,month,year;
    public:
    date()
    {

    }
    date(int d,int m,int y);
    date operator+(int );
    void show();
};
void date::show()
{
    cout<<day<<"\t"<<month<<"\t"<<year<<endl;
}
date::date(int d,int m,int y)
{
    day=d;
    month=m;
    year=y;
}
date date::operator+(int d)
{
    date temp;
     temp.day=day+d;
    temp.month=month;
    temp.year=year;
          while(temp.day>30)
          {
            temp.month++;
            temp.day-=30;
          }
          while(temp.month>12)
          {
            temp.year++;
            temp.month-=12;
          }
          return temp;
}
int main()
{
    date old_date(2,10,2021),new_date;
    old_date.show();
    new_date=old_date+300;
    new_date.show();
    return 0;

}
