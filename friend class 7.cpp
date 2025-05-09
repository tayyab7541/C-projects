#include<iostream>
using namespace std;
class vector
{
    private:
    int x,y,z;
    public:
    vector() {}
    vector(int a,int b,int c)
    {
        x=a;
        y=b;
        z=c;
    }
    friend class b;
};
class b
{
    public:
    vector A,B;
    
    void mul()
    {
        cout<<"Dot product of two vector is = "<<A.x*B.x+A.y*B.y+A.z*B.z;

    }
};
int main()
{
    vector o1(3,4,0),o2(1,0,10);
    b obj;
    obj.A=o1;
    obj.B=o2;
    obj.mul();
    return 0;
}