#include<iostream>
#include<string>
#include "stack.h"
int main()
{

	stack stk;
	std::string expression;
	std::cout << "Enter your expression = ";
	std::getline(std::cin, expression);

	int size = expression.length();
	std::string *array;
	array = new std::string[size];

	int j = 0;
	for(int i=0;i<size;i++)
	{   
		
		if (isdigit(expression[i]))
		{
			while (isdigit(expression[i]))
			{
				array[j] += expression[i];
				++i;
			}
			--i;
			++j;
		}
	 if (expression[i] == '+' || expression[i] == '-' || expression[i] == '/' || expression[i] == '*' || expression[i] == '^'|| expression[i] == '('|| expression[i] == ')')
		{
			array[j] = expression[i];
			++j;
		}

		
		
		
	}

	for (int h = 0; h < j; h++)
	{
		try
		{
			stoi(array[h]);

			std::cout << array[h]<<",";
		}
		catch (std::invalid_argument a)
		{

			if (array[h] == "(")
			{
				stk.push(array[h]);
			}
			else if (array[h] == ")")
			{
				while (stk.top() != "(")
				{
					try
					{
						std::cout<<stk.top()<<",";
						stk.pop();
					}
					catch (const char* e)
					{
						break;
					}
				}
				stk.pop();
			}
			else

			{


				std::string c;
				bool found = false;
				try
				{
					c = stk.top();
				}
				catch (const char* e)
				{
					found = true;
				}
				if (!found)
				{
					int check = precedence(c);
					int check1 = precedence(array[h]);
					if (check > check1)
					{
						stk.pop();
						std::cout << c;
						stk.push(array[h]);
					}

					else if (check == check1)  //if operators have same precedence it will remove already existing and put new 
					{
						stk.pop();
						std::cout << c;
						stk.push(array[h]);
					}
					else
					{
						stk.push(array[h]);
					}
				}
				else
				{
					stk.push(array[h]);
				}

			}

		}

		
      
	}

	while (!stk.empty())
	{
		std::cout << stk.top()<<",";
		stk.pop();
	}

}

