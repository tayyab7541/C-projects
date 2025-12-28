#include <iostream>
#include "set.h"
int main()
{

	set<int> m;
	set<int>::iterator it;
	set<int>::reverse_iterator rev;

	m.insert(5);
	m.insert(7);
	m.insert(3);
	m.insert(4);
	m.insert(6);
	m.insert(9);

	it = m.begin();
	rev = m.rbegin();
	while(it != m.end())
	{
		std::cout << *it << std::endl;
		++it;
	}

	while (rev != m.rend())
	{
		std::cout << *rev << std::endl;
		++rev;
	}

	//set<int> m2(m);

	m.clear();
}

