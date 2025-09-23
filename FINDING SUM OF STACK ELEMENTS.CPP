#include<iostream>
#include<stack>

int main()
{
	std::stack<int> obj;
	int num;
	std::cout << "You want to find sum of how many number = ";
	std::cin >> num;
	int sum = 0;
	int temp;
	for (int i = 1; i <= num; i++)
	{
		std::cout << "enter  " << i << "number = ";
		std::cin >> temp;
		obj.push(temp);
	}
	for (int i = 1; i <= num; i++)
	{
		sum += obj.top();
		obj.pop();
	}
	std::cout << "Sum = " << sum;
}
