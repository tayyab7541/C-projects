#include<iostream>
using namespace std;
class malik
{
    private:
    int day,month,year;
    public:
    malik(int d,int m,int y): day(d),month(m),year(y){}
    void show()
    {
        cout<<"The date is \n "<<day<<"-"<<month<<"-"<<year<<endl;
    }
};
int main()
{
    malik m(2,10,2006);
    m.show();
    return 0;
}