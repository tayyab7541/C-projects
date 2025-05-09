#include<iostream>
using namespace std;
int fun(int i);
int main()
{
    int num;
    cout<<"enter number to find factorial = ";
    cin>>num;
    cout<<"factorial of given number is = "<<fun(num);
}
int fun(int i)
{
    if(i==0)
    {
      return 1;
    }
    else
    {
        return i*fun(i-1);

    }
}