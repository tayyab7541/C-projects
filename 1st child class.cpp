#include<iostream>
using namespace std;
class malik //parent class
{   
    protected:
	string t="mucch nahi to kuch nahi";

};

//child class 
class m:protected malik
{
	public:
	void display()
	{
		cout<<t<<endl;
	}	
};

int main() //main program
{
	m tayyab; //object of child class
	tayyab.display();
	return 0;
}
