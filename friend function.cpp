#include<iostream>
using namespace std;
class a;
class b
{
    private:
    int length,width;
    public:
    b()
    {
        length=10;
        width=10;
    }
    friend void fun(a o1,b o2);
};
class a
{
    private:
    int x1,y1;
    public:
    a()
    {
        x1=10;
        y1=5;
    }
    friend void fun(a o1,b o2);
};

void fun(a o1,b o2)
{
    int sum;
    sum=0;
    sum=o1.x1+o1.y1+o2.length+o2.width;
    cout<<"sum of all the private memebers of classes is ="<<sum;
}
int main()
{
    a c;
    b d;
    fun(c,d);
    return 0;
}
