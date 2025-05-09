#include<iostream>
#include<string>
using namespace std;
class light
{
	private:
		string color;
		
		public:
			light():color("red") {} ; //constructure
			void change()
			{
				if(color=="red")
				{
					color="green";
					
				}
				else if(color=="green")
				{
					color="yellow";
				}
				else if(color=="yellow")
				{
					color="blue";
					
				}
				else if(color=="blue")
				{
					color="red";
				}
			}
			string display() const
			{
				return color;
			}
};
int main()
{
	light t;
	cout<<"initial color = ";
	cout<<t.display()<<endl;
    cout<<"after first change =";
    t.change();
    cout<<t.display()<<endl;
    cout<<"after second change = ";
    t.change();
    cout<<t.display()<<endl;
    cout<<"after third change =";
    t.change();
    cout<<t.display()<<endl;
    cout<<"after fourth change = ";
    t.change() ;
    cout<<t.display()<<endl;
    cout<<"after fifth change = ";
    t.change() ;
    cout<<t.display()<<endl;
    return 0;
}