#include<iostream>
using namespace std;
class malik
{
	private:
		char ch;
		int num;
		double d;
		public:
			malik(char ch,int num,double d):ch(ch),num(num),d(d){};
			void show()
			{
				cout<<ch<<"\t"<<num<<"\t"<<d<<endl;
			}
};
int main()
{
	malik m('T',45,4.5);
	m.show();
	return 0;
}