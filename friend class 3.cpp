#include<iostream>
using namespace std;
class rectangle
{
    private:
    int length,width;
    public:
    void input()
    {
        cout<<"Enter length of rectangle = ";
        cin>>length;
        cout<<"Enter width of rectangle = ";
        cin>>width;

    }
    friend class b;
};
class b
{
    rectangle obj;
    public:
    void area()
    {
        obj.input();
        cout<<"Area of rectangle is = "<<obj.length*obj.width;

    }
};
int main()
{
    b obj;
    obj.area();
    return 0;

}