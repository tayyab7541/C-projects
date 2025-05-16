#include<iostream>
using namespace std;
class vehicle
{
    protected:
    int speed;
    public:
    vehicle(){}
    vehicle(int a)
    {
        speed=a;
    }
};
class car:public virtual vehicle
{};
class boat:public virtual vehicle
{};
class amphibious_vehicle:public car,public boat
{
    public:
   amphibious_vehicle (int s):vehicle(s) {}
    void dis()
    {
        cout<<"The speed of vehicle is = "<<speed<<endl;
    }
};
int main()
{
    amphibious_vehicle ve(45);
    ve.dis();
    return 0;
}