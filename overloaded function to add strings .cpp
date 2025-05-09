#include<iostream>
#include<string>
using namespace std;
class malik
{
    public:
    string name;
    void input()
    {
        cout<<"enter name = ";
        cin.ignore();
        getline(cin,name);

    }
    malik operator+(malik &m1);
};
malik malik::operator+(malik& m1)
{
  malik m2;

  m2.name=this->name+m1.name;
  return m2;
}
int main()
{
    malik m1,m2,m3;
    m1.input();
    m2.input();
    m3=m1+m2;
    cout<<"sum of two objects "<<m3.name<<endl;
    return 0;
    
}