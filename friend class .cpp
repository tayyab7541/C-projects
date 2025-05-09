#include<iostream>
using namespace std;
class c1
{
    private:
    int num;
    public:
    c1()
    {
        num=15;
    }
    friend class b;
};
class b
{
    public :
    c1 obj;
    void show()
    {
        cout<<"value in number of class one = "<<obj.num;
    }
};
int main()
{
    b obj1;
    obj1.show();
    return 0;
}