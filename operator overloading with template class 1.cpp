#include<iostream>
using namespace std;
template <class t>
class time
{
    private:
    t hrs,min,sec;
    public:
    time():hrs(0),min(0),sec(0){}
    void show();
    void operator=(const time&);
};

template<class t> void time<t>::show()
{
    cout<<"Time is now \n";
    cout<<hrs<<":"<<min<<":"<<sec<<endl;
}
template<class t> void time<t>::operator=(const time& obj)
{
    hrs=obj.hrs;
    min=obj.min;
    sec=obj.sec;
}
int main()
{
    time <int> t,t1;
    t=t1;
    t.show();
    t1.show();
    return 0;
}