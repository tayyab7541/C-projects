#include<iostream>
using namespace std;
class animal
{
    protected:
    void sound()
    {
        cout<<"This is sound of animal \n";
    }
};
class mammal:public virtual animal
{};
class bird :public virtual animal
{};
class bat:public mammal,public bird
{};
class flyingbat:public bat
{
    public:
    void dis()
    {
        sound();
    }
};

int main()
{
    flyingbat f;
    f.dis();
    return 0;
}