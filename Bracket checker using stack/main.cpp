#include<iostream>
#include<fstream>
#include "stack.h"

int main(int argc, char **argv)
{
	if (argc == 2)
	{
		stack stk;
		std::ifstream file;
		file.open(argv[1], std::ios::in);
		if (file.is_open())
		{    
			int count_closing;
			int count ;
			char temp;
			while (file.good())
			{
				file >> temp;
				if (temp == '{')
				{
					stk.push(temp);
					count++;
				}
				else if (temp == '}')
				{ 
					if (!stk.empty())
					{
						stk.pop();
						++count_closing;
					}
					else
					{
						break;
					}
				}
			}
			if (stk.size() == 0)
			{
				std::cout << "Braces are equal ";
			}
			
			
		}
	}
	else
	{
		std::cout << "You can enter only file name ";
	}

}
