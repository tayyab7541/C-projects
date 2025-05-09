#include<iostream>
using namespace std;
class time
{
	private:
		    int s,m,h;
	public:
		time(int x,int y,int z)
		{
			s=x;
			m=y;
			h=z;
		}
		void show();
};

void time::show()
{
	cout<<"Time is now \n ";
	cout<<h<<":"<<m<<":"<<s<<endl;
	
}
int main()
{
	int a,b,c;
	cout<<"Enter hours = ";
	cin>>c;
	cout<<"Enter minutes = ";
	cin>>b;
	cout<<"Enter seconds = ";
	cin>>a;
	time t(a,b,c);
	t.show();
	return 0;
}