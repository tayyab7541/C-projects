#include<iostream>
#include<cstring>
#include<algorithm>


class stack
{
private:
	char** ar;
	int _top;
	int _size;
public:
	stack(const int& s = 10)
	{
		int col = 40;
		_top = -1;
		_size = s;
		ar = new char* [_size];
		for (int i = 0; i < _size; i++)
		{
			ar[i] = new char[col];
		}
	}

	void push(char w[])
	{
		++_top;
	 strcpy_s(ar[_top],40, w);
	}
	void pop()
	{
		--_top;
	}
	char* top()
	{
		return ar[_top];
	}
	bool empty()
	{
		if (_top == -1)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
};

int main()
{
	stack obj(20);
	char name[40];
	std::cout << "Good name ";

	for (int i = 0; i < 3; i++)
	{
		std::cout << "Enter name = ";
		std::cin.getline(name, 40);
		obj.push(name);
	}

	for (int i = 0; i < 3; i++)
	{
		if (obj.empty())
		{
			std::cout << "Stack is empty";
			break;
		}
		else
		{

			std::cout << obj.top() << std::endl;
			obj.pop();
		}
	}

}
