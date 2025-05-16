#include<iostream>
using namespace std;
class date
{
    private:
    int day,month[12],year,sizeo,months;
    public:
    date() {}
    date(int d,int mo,int y,int size,int m[])
    {
        day=d;
        int i;
        months=mo;
        sizeo=size;
        for(i=0;i<size;i++)
        {
            month[i]=m[i];
        }
        year=y;
    }

    void show()
    {
        cout<<"Date after addition is \n "<<day<<"-"<<months<<"-"<<year<<endl;
    }
    date operator+(int m)
    {
        date temp;
        temp.day=day+m;
        temp.sizeo=sizeo;
        temp.months=months;
        temp.year=year;
        for(int j=0;j<sizeo;j++)
        {
            temp.month[j]=month[j];
        }
        int i=0;
        while(temp.day>temp.month[i])
        {
           temp.months++;
           temp.day-=temp.month[i];
           if(temp.months>12)
           {
            temp.year++;
            temp.months-=12;
            i=0;
            continue;
           }
           i++;
        }
        
        return temp;
    }
};

int main()
{
    const int size=12;
    int month[size]={31,28,31,30,31,31,31,30,30,31,31,31};
   
    date d(2,10,2006,size,month),d2;
    d.show();
    d2=d+300;
    d2.show();
    return 0;

}