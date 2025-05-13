#include<iostream>
using namespace std;
void conversion(long num)
{
   int hr,min,sec;
   hr=num/3600;
   num=num%3600;
   min=num/60;
   sec=num%60;
   cout<<"Time is \n "<<hr<<":"<<min<<":"<<sec<<endl;
}

int main()
{
    long num=30336;
    conversion(num);
    return 0;
}