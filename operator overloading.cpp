#include<iostream>
using namespace std;
class date
{
    private:
    int d,m,y;
    public:
    date() {}
    date(int d,int m,int y)
    {
        this->d=d;
        this->m=m;
        this->y=y;
    }
    bool operator==(const date &);

};
bool date::operator==(const date &date2)
{
    if(d==date2.d&&m==date2.m&&y==date2.y)
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
    date date1(2,10,2006),date2(2,10,2007);
    if(date1==date2)
    {
        cout<<"Dates are equal \n ";

    }
    else
    {
        cout<<"Dates are not equal \n";
    }
}