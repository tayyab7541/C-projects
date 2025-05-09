#include<iostream>
using namespace std;
class malik
{
    private:
    int day,month;
    public:
    malik() {} //default constructure 
    friend istream& operator>>(istream& in, malik &obj);
    void show()
    {
        cout<<"number is \n"<<day<<" + "<<month<<"i"<<endl;

    }
};

istream& operator>>(istream& in ,malik &obj)
{
    cout<<"enter real part = ";
    in>>obj.day;
    cout<<"enter imaginary pert = ";
    in>>obj.month;
}
int main()
{
    malik m;
    cin>>m;
    m.show();
    return 0;
}