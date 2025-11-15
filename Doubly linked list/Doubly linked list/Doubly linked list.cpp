#include<iostream>
#include "ADT code.h"

int main()
{
	list<int> l1;
	list<int>::iterator it;
	list<int>::reverse_iterator it1;

	
	for (int i = 0; i < 5; ++i)
	{
		l1.push_front(i);
	}
	/*it = l1.begin();
	++it;
	std::cout << *it << std::endl;
	it1 = l1.rbegin();
	++it1;
	++it1;

	std::cout<<"R begin = "<<*it1<<std::endl;*/

	//l1.clear();
	std::cout << "Size of list  1= " << l1.size() << std::endl;

	list<int> l2(l1);

	//l2.resize(6);
	std::cout << "Size of list 2= " << l2.size() << std::endl;

	while (!l2.empty())
	{
		try
		{
			std::cout << l2.back() << std::endl;

		}
		catch (const char* e)
		{
			std::cout << e << std::endl;
		}
		try
		{
			l2.pop_back();
		}
		catch (const char* e)
		{
		std::cout<<e<<std::endl;
		}
		
	}

}