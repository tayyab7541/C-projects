#include<iostream>
#include "forward_list.h"


int main()
{
	forward_list f;
	forward_list::iterator it;



	for (int i = 1; i <= 10; ++i)
	{
		f.push_front(i);
	}	

	it = f.begin();
	int i = 1;
	while (it != f.end())
	{
		if (i % 2 != 0)
		{
			try
			{
				it = f.insert_after(it, 3, -9);
			}
			catch (const char* ch)
			{
				std::cout << ch;
			}
			
		}
		++it;
		++i;
	}


	std::cout << "size after insert = " << f.size() << std::endl;
	it = f.begin();
	while (it != f.end())
	{
		std::cout << *it << "\n";
		++it;
	}
	it = f.begin();
	++it;
	++it;
	it=f.erase_after(it);
		it = f.begin();
    std::cout << "last value is = " << it->value << std::endl;


}