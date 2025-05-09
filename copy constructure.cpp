#include<iostream>
using namespace std;
class malik
{   
    private:
    int day,month,year;
    public:
    malik(int d,int m,int y);//parameterized constructure 
    malik(malik&);//copy constructure
    void show();
};
malik::malik(int d,int m ,int y)
{
    day=d;
    month=m;
    year=y;
}
malik::malik(malik &m)
{
    day=m.day;
    month=m.month;
    year=m.year;
}
void malik::show()
{
    cout<<"date is \n";
    cout<<day<<"/"<<month<<"/"<<year<<endl;
}

int main()
{
    malik m(2,10,2006);
    malik m1(m);
    cout<<"calling function for fist object \n";
    m.show();
    cout<<"callling functioin for second object \n";
    m1.show();
    return 0;
}