#include<iostream>
using namespace std;
class a
{
    public:
    a()
    {
        cout<<"This is class a's constructure \n";
    }
    ~a()
    {
        cout<<"This is class a's destructure \n";
    }
};
class b :public virtual a
{
    public:
    b()
    {
        cout<<"This is class b's constructure \n";
    }
    ~b()
    {
        cout<<"This is class b's destructure \n";
    }
};
class c :public virtual a
{
    public:
    c()
    {
        cout<<"This is class c's constructure \n";
    }
    ~c()
    {
        cout<<"This is class c's destructure \n";
    }

};
class d :public b ,public c
{
    public :
    d()
    {
        cout<<"This is class d's constructure \n";
    }
    ~d()
    {
        cout<<"This is class d's destructure \n";
    }
};

int main()
{
    d obj;
    return 0;
}
