#include<iostream>
#include<cmath>
using namespace std;
class point 
{
    protected:
    int x1,y1,x2,y2;
    public:
    point(){} //default constructure 
    point(int a,int b,int c,int d)
    {
      x1=a;
      y1=b;
      x2=c;
      y2=d;
    }
    
    int area() //function to return only 0
    {
        return 0;
    }
   double distance() //function to calculate distance
   {
    int num1,num2;
    num1=x2-x1;
    num2=y2-y1;
    return sqrt(num1*num1+num2*num2);
   }

};

class circle :public point //derived class
{
    public:
    circle(int a,int b,int c,int d):point(a,b,c,d){} //base class is assigned values using last derived class

};
int main()
{
 
    circle c(5,6,7,2);
   cout<<"Area given by point class is  = "<< c.point::area()<<endl;
   cout<<"Distance provided by base class is = "<<c.point::distance();
   return 0;


}