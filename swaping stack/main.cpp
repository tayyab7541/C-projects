#include<iostream>
#include"stack.h"

int main()
{
	stack stk;
	stack object2;
	int num,num2;
	std::cout << "How many number you want ot enter in first stack  = ";
	std::cin >> num;
	int temp;
	std::cout << "for first stack \n";
	for (int i = 1;i <= num;i++) //taking input
	{
		std::cout << "Enter " << i << "number = ";
		std::cin >> temp;
		stk.push(temp);
	}
	
	std::cout << "How many number you want ot enter in second stack  = ";
	std::cin >> num2;
	std::cout << "for second stack \n";
	for (int i = 1;i <= num2;i++) //taking input
	{
		std::cout << "Enter " << i << "number = ";
		std::cin >> temp;
		object2.push(temp);
	}

	if (stk.empty()&&object2.empty())
	{
		std::cout << "Stack is empty";
	}


  	else  //if stack is not empty it will proceed further
 	{
		


		std::cout << "Size of stack 1= " << stk.size() << "\n";
		std::cout << "Size of stack 2= " << object2.size() << "\n";
	
		std::cout << "\n";
         //swappin values calling swap function
		object2.swap(stk);

		std::cout << "After swap \n";
		



		std::cout << "\n Size after swapping \n";

		std::cout << "Size of stack 1= " << stk.size() << "\n";
		std::cout << "Size of stack 2= " << object2.size() << "\n";

		std::cout << "First stack \n";
		while(!stk.empty())
		{
			std::cout << stk.top() << "\t";
			stk.pop();
		}
		std::cout << "\n";

		std::cout << "Second stack \n";
	   while(!object2.empty())
		{
			std::cout << object2.top() << "\t";
			object2.pop();
		}


		
	}

}