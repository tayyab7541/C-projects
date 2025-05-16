#include<iostream>
#include<string>
using namespace std;
class str
{
    private:
    string nam;
    public:
    str() {}
    str(string name)
    {
        nam=name;
    }
    string operator+(const str &st)
    {
        return nam+st.nam;
    }
};
int main()
{
    str s1("Malik "), s2(" Tayyab Rafiq");
    string s3;
    s3=s1+s2;
    cout<<"After addition of string = "<<s3;
    return 0;
}