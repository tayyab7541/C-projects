#include<iostream>
using namespace std;
class malik
{
    private:
    int day,month ,year;
    public:
    malik() //default constructure 
    {

    }
    malik(int d,int m,int y);
    void show();

};

malik::malik(int d,int m,int y)
{
    day=d;
    month =m;
    year=y;

}
void malik::show()
{
    cout<<"date is \n"<<day<<"/"<<month<<"/"<<year<<endl; 
}

int main()
{
    malik m(2,10,2006);
    malik m1;
    m1=m;
    m.show();
    m1.show();
    return 0;
}