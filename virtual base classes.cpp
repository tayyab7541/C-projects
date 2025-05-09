#include<iostream>
using namespace std;
class a
{
	public:
		void show()
		{
			cout<<"This is the function of class a\n";
		}
};
class b:public virtual a
{public:
};
class c:public virtual a
{
	public:
};
class d:public b,public c
{
	public :
};
int main()
{
	d obj;
	obj.show();
	return 0;
}