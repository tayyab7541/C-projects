#include<iostream>
using namespace std;
template <class t,int size>
class malik
{   private:
	
	t ar[size];
	t ar1[size];
	public:
	malik(t ar2[])
	{
		for(int i=0;i<size;i++)
		{
		 ar[i]=ar2[i];	
		}
	}
	void acpy()
	{
		for(int j=0;j<size;j++)
		{
			ar1[j]=ar[j];
		}
		
	}
	void dis()
	{
		for(int i=0;i<size;i++)
		{
			cout<<ar1[i]<<"\t";
		}
	}
};
int main()
{
	int ar[]={1,2,3,4,5};
	malik <int, 5>m(ar);
	m.acpy();
	m.dis();
	return 0;
}