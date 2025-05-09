#include<iostream>
using namespace std;
class time
{  
private:	
	       int h,m,s;
public:
	  time(int a,int b,int c)
	  {
	  	h=a; m=b; s=c;
	  }
	  time(long t)
	  {
	  	int n;
	  	h=t/3600;
	  	n=t%3600;
	  	m=n/60;
	  	s=n%60;
	  }
	  void display()
	  {
	  	cout<<h<<":"<<m<<":"<<s<<endl;
	  }
	  void tick();
};
void time::tick()
{
	if(s==59)
	{
		s=0;
		if(m==59)
		{
			m=0;
			h=h+1;
		}
		else
		{
			m=m+1;
		}
	}
	else
	{
		s=s+1;
	}
	cout<<h<<":"<<m<<":"<<s<<endl;
}
int main()
{
	time t1(0,0,0),t2(28799);
	cout<<"for first object \n";
	t1.display();
	t1.tick();
	cout<<"for second object \n";
	t2.display();
	t2.tick();
	return 0;
	
}