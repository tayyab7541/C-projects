#pragma once
class stack
{
private:
	char *ar;
	int _top;
	int _size;
public:
	stack(int s = 100)
	{
		_size = s;
		_top = -1;
		ar = new char[_size];

	}
	void push(char ch)
	{
		++_top;
		ar[_top] = ch;

	}
	void pop()
	{
		--_top;
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

	char top()
	{
		return ar[_top];
	}

	int size()
	{
		return _top + 1;
	}
};