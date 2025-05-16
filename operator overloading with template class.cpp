#include<iostream>
using namespace std;
template <class t>
class cartesian
{
    private:
    t x,y;
    public:
    void input();
    void show();
    void operator=(const cartesian &);
};
template<class t> void cartesian<t>::input()
{
    cout<<"Enter x = ";
    cin>>x;
    cout<<"Enter y = ";
    cin>>y;
}
template<class t> void cartesian<t>::show()
{
    cout<<"Value of x = "<<x<<endl<<"Value of y = "<<y<<endl;
}
template<class t> void cartesian<t>::operator=(const cartesian & obj)
{
    x=obj.x;
    y=obj.y;
}
int main()
{
   cartesian <int> obj1,obj2;
   obj1.input();
   obj2=obj1; 
   cout<<"Value in obj1 are \n";
   obj1.show();
   cout<<"Value in obj2 are \n ";
   obj2.show();
   return 0;
}