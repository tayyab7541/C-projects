#include<iostream>
using namespace std;
class a
{
    private:
    int num1,num2;
    public:
    void input()
    {
        cout<<"Enter number 1 = ";
        cin>>num1;
        cout<<"Enter number 2 = ";
        cin>>num2;
    }
    friend class b;
};
class b
{
    public:
    int num3;
    a obj;
    void sum()
    {
        obj.input();
        cout<<"enter number of second class = ";
        cin>>num3;
        cout<<"Sum of three number is = "<<obj.num1+obj.num2+num3;

    }
};
int main()
{
    b obj2;
    obj2.sum();
    int main();
}