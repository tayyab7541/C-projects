#include<iostream>
using namespace std;
class malik 
{
    int real;
    public:
    malik() {}
    malik (int r): real(r){}
    friend bool operator==(malik& other,malik o2)
    {
         if(o2.real==other.real)
         {
            return 1;
         }
         else
         return 0;
    }
};
int main()
{
    malik m1(5),m2(5);
    if(m1==m2)
    {
        cout<<"both objects are equal \n ";
    }
    else
    {
        cout<<"objects are not equal \n ";

    }
    return 0;
}