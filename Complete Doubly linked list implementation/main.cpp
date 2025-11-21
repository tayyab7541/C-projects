// COMPLETE DOUBLY LINKED LIST.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include"list.h"
int main()
{
	list l1,l2;
	list::iterator it;
	list::reverse_iterator itr;
	
	l1.push_front(20);
	l1.push_front(19);
	l1.push_front(17);
	l1.push_front(10);
	l1.push_front(1);

	l2 = l1;
	l2.push_back(7);
	//l1.merge(l2);

	//itr = l1.rbegin();
	 //it = l1.begin();
	//std::cout << *l1.erase(it);
	//l1.clear();
	//l1.resize(10);
	 //l1.splice(it, l2);
	 //std::cout << "Number of values removed  =" << l1.unique() << std::endl;
	std::cout << "Size of list 1 = " << l1.size()<<std::endl;
	if (l1.empty())
	{
		std::cout << "List one is empty \n";
	}
	else
	{
		std::cout << "list is not empty \n";
	}
	/*l1.reverse();
	l1.sort();
	swap(l1, l2);
	std::cout << "Number of values erased from list 2 = " << erase(l2, 1) << std::endl;*/

	if (l1 == l2)
	{
		std::cout << "list 1 is equal to list 2 \n";
	}
	else
	{
		std::cout << "list 1 is not equal to list 2 \n";

	}
	if (l1 != l2)
	{
		std::cout << "list 1 is not equal to list 2 \n";
	}
	else
	{
		std::cout << "list 1 is equal to list 2 \n";

	}
	if (l1 > l2)
	{
		std::cout << "list 1 is greater than list 2 \n";
	}
	else
	{
		std::cout << "list 1 is not greater than list 2 \n";

	}
	if (l1 < l2)
	{
		std::cout << "list 1 is smaller than list 2 \n";
	}
	else
	{
		std::cout << "list 1 is not smaller than list 2 \n";

	}
	if (l1 <= l2)
	{
		std::cout << "list 1 is smaller than or equal to list 2 \n";
	}
	else
	{
		std::cout << "list 1 is not smaller than or equal to list 2 \n";

	}
	if (l1 >= l2)
	{
		std::cout << "list 1 is greater than or equal to list 2 \n";
	}
	else
	{
		std::cout << "list 1 is not greater than or equal to list 2 \n";

	}
}

