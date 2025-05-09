#include<iostream>
using namespace std;
class time
{
	private:
		int hour,minute,second;
		public:
			time(int a,int b,int c)
			{
				hour=a;minute=b;second=c;
			}
			time(long);
			void show();
};
int main()
{
	time t(0,0,0),t1(20340);
	t.show();
	cout<<"second time \n";
	t1.show();
	return 0;
}
time::time(long hms)
{
	hour=int(hms/10000);
	int n=int(hms%10000);
	minute=n/100;
	second=n%100;
}
void time::show()
{
	cout<<"Time is \n"<<hour<<"/"<<minute<<"/"<<second<<endl;
}