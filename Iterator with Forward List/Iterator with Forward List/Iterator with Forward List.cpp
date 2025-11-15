#include "Forward-list.h"
//#include "structure.h"
#include <iostream>

int main()
{

	forward_list f;
	forward_list::iterator it;
	for (int i = 1; i <= 5; ++i)
	{
		f.push_front(i);
	}
	it = f.begin();
	while (it!=f.end())
	{
		std::cout << *it << std::endl;
		//++it;
		it++;
	}
}