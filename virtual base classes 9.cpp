#include<iostream>
using namespace std;
class resources
{
    private:
    int id;
    protected:
    void allocate()
    {
      cout<<"Enter id = ";
      cin>>id;
    }
    void show()
    {
        cout<<"Id you enter is = "<<id;
    }
};

class file:public virtual resources
{};
class network:public virtual resources
{};
class remotfile:public file,public network
{
    public:
    void input()
    {
        allocate();
    }
    void dis()
    {
        show();
    }
};

int main()
{
    remotfile r;
    r.input();
    r.dis();

    return 0;
}