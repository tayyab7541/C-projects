#include<iostream>
#include"stack.h"

int main()
{
	stack<int> stk1(5);

	for (int i = 0; i < 7; ++i)
	{
		stk1.push(i + 1);
	}

	for (int i = 0; i < 7; ++i)
	{
		std::cout << stk1.top() << std::endl;
		try
		{
			stk1.pop();
		}
		catch (const char* e)
		{
			std::cout << e;
		}
		
	}

}