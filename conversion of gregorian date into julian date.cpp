#include<iostream>
using namespace std;
class convert
{
    private:
    int day,month,year;
    public:
    convert() {} //default constructure 
    convert(int d,int m, int y): day(d),month(m),year(y) {} //initializer list
    void show()
    {
        cout<<day<<"/"<<month<<"/"<<year<<endl;
    } 
  operator long() const
  {
    int M,D,Y;
    M=month;
    D=day;
    Y=year;
    int MP,YP;
    if(M<=2)
    {
        MP=0;
        YP=Y-1;
    }
    else
        {
          MP=(0.4*M+2.3);
          YP=Y;
       }
       int T=YP/4-YP/100+YP/400;
       long juliandate= 365*Y+31*(M-1)+D+T-MP;
       return juliandate;
  }

};

int main()
{
    convert d1(1,31,2001),d2(3,16,2012);

    cout<<"First gregorian date \n ";
    d1.show();
    cout<<"Second gregorian date \n";
    d2.show();
    long jd=d1;
    cout<<"Julian date of frist gregorian date is = "<<jd<<endl;
    long jd1=d2;
    cout<<"Julian date of second gregorian date is= "<<jd1<<endl;
}