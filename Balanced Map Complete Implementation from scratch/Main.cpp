
#include <iostream>
#include "map.h"
#include "pair.h"
int main()
{
	map<int, std::string> m;
	map<int, std::string>::iterator it;


	m.insert({ 2,"malik" });
	m.insert({ 4,"malik" });
	m.insert({ 9,"malik" });
	m.insert({ 6,"malik" });
	m.insert({ 5,"malik" });
	std::cout << "size of map = " << m.size() << std::endl;


	map<int, std::string> m1(m);

	//m.clear();

	it = m.begin();
	++it;
	++it;
	/*try
	{
		m.erase(it);

	}
	catch (const char* e)
	{
		std::cout << e << std::endl;
	}

	if (m.empty())
	{
		std::cout << "map is empty \n";

	}
	else
	{
		std::cout << "map is not emtpy \n";
	}

	try
	{
		std::cout << m.at(7) << std::endl;

	}
	catch (const char* e)
	{
		std::cout << e << std::endl;
	}
	it = m.begin();*/

	//std::cout << m[7] << std::endl;
	//std::cout << "calling count function to check number of times key 1 exists = " << m.count(1) << std::endl;
	std::cout << "value found at the key = " << it->second << std::endl;
	/*if (m.contains(1))
	{
		std::cout << "Key 1 exists in map \n";
	}
	else
	{
		std::cout << "Key 1 not exists in map \n";


	}*/
}

