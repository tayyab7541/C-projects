#include "set.h"
#include <iostream>

int main()
{

	set s;
	s.insert(15);
	s.insert(10);
	s.insert(1);
	s.insert(120);
	s.insert(150);
	s.insert(130);
	s.insert(160);

	set::iterator it;

	it = s.first_non_leaf_node();

	
	/*
	std::cout << "number of leaves = " << s.leaves() << std::endl;
	set::iterator it;
	it = s.upper_bound(160);

	it = s.find(160);

	if (s.conatins(160))
	{
		std::cout << "100 is available in set\n";
	}
	else
	{
		std::cout << "100 is not available in set\n";


	}
	std::cout<<s.count(11) << std::endl;
	set s2;
	s2.insert(14);
	s2.insert(20);
	s2.insert(5);
	s2.insert(1);

	s.merge(s2);

	set::iterator it;
	it = s.begin();

	++it;
	++it;

	 it = s.erase(it);
	while (it != s.end())
	{
		std::cout << *it << std::endl;
		++it;
	}

	set::reverse_iterator it3;
	it3 = s.rbegin();
	while (it3 != s.rend())
	{
		std::cout << *it3 << std::endl;
		++it3;
	}
	s.clear();*/
}
