#include<iostream>
#include "stack.h"

int main()
{
	stack stk1(5);

	for (int i = 1; i <= 5; i++)
	{
		try
		{
			stk1.push(i);
		}
		catch (const char* e)
		{
			std::cout << e << std::endl;
		}
	}

	std::cout<<"Size of stack = " << stk1.size() << std::endl;
	for (int i = 1; i <= 5; ++i)
	{
		try
		{
			std::cout << stk1.top() << std::endl;
		}
		catch (const char* e)
		{
			std::cout << e << std::endl;
		}

		try
		{
			stk1.pop();
		}
		catch (const char* e)
		{
			std::cout << e << std::endl;
		}
	}

	if (stk1.empty())
	{
		std::cout << "Stack is empty \n ";
	}
	else
	{
		std::cout << "stack is not empty ";
	}
}