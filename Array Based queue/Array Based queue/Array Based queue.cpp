#include<iostream>
#include "queue.h"
int main()
{
	queue q1,q2;
	q1.push(5);
	q2 = q1;
	std::cout << q2.front() << std::endl;

	q2.push(10);
	if (q1 == q2)
	{
		std::cout << "queues are equal ";
	}
	else
	{
		std::cout << "queues are not equal ";
	}
}