#include<iostream>
#include<string>
using namespace std;
class student
{
    private:
    string name;
    double grade;
    public:
    student() {}
    student(string nam,double gr)
    {
        name=nam;
        grade=gr;
    }

    friend class b;
};
class b
{
    public:
    student s;
    void show()
    {
        cout<<"Name of student = "<<s.name;
        cout<<"\n grade of student = "<<s.grade;
    }
};
int main()
{
    student st("Malik Tayyab",3.7);
    b obj;
    obj.s=st;
    obj.show();
    return 0;
}