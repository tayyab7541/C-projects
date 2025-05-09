#include<iostream>
using namespace std;
template <class t ,int size>
class malik
{ 
   private:
	t ar[size];
	public:
		malik() {}
		void input()
		{
			for(int i=0;i<size;i++)
			{
				cout<<"enter number = ";
				cin>>ar[i];
			}
			
		}
		void dis()
		{
			for(int i=0;i<size;i++)
			{
				cout<<ar[i]<<"\t";
			}
		}
};

int main()
{
	malik <int , 5> m;
	m.input();
	m.dis();
	return 0;
}