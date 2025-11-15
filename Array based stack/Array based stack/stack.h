#pragma once

class stack
{
private:
	int* ar;
	int _size;
	int _top;
public:
	stack(int s = 10)
	{
		_size = s;
		_top = -1;
		ar = new int[_size];
	}

	~stack()
	{
		delete ar;
	}
	void push(int n)
	{
		if (_top < _size - 1)
		{
			++_top;
			ar[_top] = n;
		}
		else
		{
			throw("Overflow occured \n");
		}
	}

	int top()const
	{
		if (_top != _size)
		{
			return ar[_top];
		}
		else
		{
			throw("Underflow occured \n");
		}
	}

	void pop()
	{
		if (_top >= 0)
		{
			--_top;
		}
		else
		{
			throw("Underflow occured \n");
		}
	}

	int size()const
	{
		return _top + 1;
	}

	bool empty()const
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