#include<iostream>
#include "forward-list.h"

int main()
{
	forward_list f;
	for (int i = 1; i <= 10; ++i)
	{
		f.push_front(i);
	}

	f.removeeven();

	while (!f.empty())
	{
		std::cout << f.front() << std::endl;
		f.pop_front();
	}
}