#include<iostream>
#include<string>
using namespace std;
class person
{
    protected:
    string name;

};
class student:public virtual person
{};
class employee:public virtual person
{};
class teaching_assistant:public student,public employee
{
    public :
    void input()
    {
        cout<<"Enter name of person = ";
        getline(cin,name);
    }
    void dis()
    {
        cout<<"Name of person is = "<<name<<endl;
    }
};
int main()
{
    teaching_assistant ta;
    ta.input();
    ta.dis();
    return 0;
}