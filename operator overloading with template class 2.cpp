#include<iostream>
using namespace std;
template <class t>
class fraction
{
    private:

    t num,denum;

    public:
    fraction() {} //default constructure
    fraction(t n1,t n2)  // parametrized constructure 
    {
        num=n1;
        denum=n2;
    }
    void operator+(const fraction &f)
    {
        t num1,num2;
        num1= num*f.denum+denum*f.num;
        num2= denum*f.denum;
        cout<<"Addition of two fractions = "<<num1<<"/"<<num2<<endl;
    }
    void operator-(const fraction &f)
    {
         t num1,num2;
        num1= (num*f.denum-denum*f.num);
        num2= denum*f.denum;
        cout<<"subtraction of two fractions = "<<num1<<"/"<<num2<<endl;
    }
    void operator*(const fraction &f)
    {
        t num1,num2;
        num1=num*f.num;
        num2=denum*f.denum;
        cout<<"Multiplication of two fractions = "<<num1<<"/"<<num2<<endl;
    }
    void operator/(const fraction &f)
    {
         t num1,num2;
         num1=(num*f.denum);
         num2= (denum*f.num);
         cout<<"Division of two fractions  = "<<num1<<"/"<<num2<<endl;
    }
};

int main()
{
    fraction <int> obj1(5,4),obj2(7,3);
    obj1+obj2;
    obj1-obj2;
    obj1*obj2;
    obj1/obj2;
    return 0;
}