#include<iostream>
#include "stack.h"
#include <string>



int main()
{
	stack stk1;
	char* ar;
	std::string st;
	std::cout << "Enter String = ";
	std::getline(std::cin, st);
	int size;
	for (char ch : st)
	{
		if (ch >= 'a' && ch <= 'z' || ch >= 'A' && ch <= 'Z')
		{
			try
			{
				stk1.push(ch);
			}
			catch (const char* e)
			{
				std::cout << e << std::endl;
			}
		}
	}

	size=stk1.size();
	ar = new char[size];
	for (int i = 0; i < size; i++)
	{
		try
		{
			ar[i] = stk1.top();
		}
		catch (const char* e)
		{
			std::cout << e;
		}
		try
		{
			stk1.pop();
		}
		catch (const char* e)
		{
			std::cout << e;
		}
	}


	if (compare(st, ar, size))
	{
		std::cout << "string is palindrome \n ";
	}
	else
	{
		std::cout << "string is not palindrome \n";
	}
}
