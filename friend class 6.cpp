#include<iostream>
using namespace std;
class complex
{
    private:
    int real,img;
    public:
    complex(){}
    complex(int a,int b)
    {
        real=a;
        img=b;
    }
    friend class b;
};
class b
{
    public:
    complex obj1,obj2;
    void sum()
    {
      int r;
      r=obj1.real+obj2.real;
      int i;
      i=obj1.img+obj2.img;
      if(i>0)
      {
        cout<<"sum of number is = "<<r<<" + "<<i<<"i"<<endl;
      }
      else
      {
        cout<<"sum of number is = "<<r<<" "<<i<<"i"<<endl;
      }
    }
};
int main()
{
    complex o1(4,5),o2(4,-7);
    b obj;
    obj.obj1=o1;
    obj.obj2=o2;
    obj.sum();
    return 0;
}