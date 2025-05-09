#include<iostream>
using namespace std;
class ar
{
	private:
	int size,*p;

	public:
		ar(int a):size(a) 
		{
				p=new int[size];
		}
		~ar()
		{
			delete [] p;
		}
	void input()
	{
		int i;
		for(i=0;i<size;i++)
		{
			cout<<"enter Value "<<i+1<<" = ";
			cin>>p[i];
		}
	}
	int member()const
	{
		return p[2];
	}
	int me()
	{
			return p[2] +10;
	}
};
int main()
{
	ar a(5);
	a.input();
	cout<<"value of element of array without modification = "<<a.member()<<endl;
    cout<<"value of element of array with modification = "<<a.me()<<endl;
	return 0;
	
}