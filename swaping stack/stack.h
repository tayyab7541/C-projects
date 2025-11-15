#pragma once
class stack
{
private:
	int *ar;
	int _size;
	int _top;
public:
	stack(int n = 10)
	{

		_top = -1;
		_size = n;
		ar = new int[_size];
	}

	void push(int n)
	{
		++_top;
		ar[_top] = n;
	}
	int top()
	{
		return ar[_top];
	}


	void pop()
	{
		--_top;
	}

	int size()
	{
		return _top + 1;
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
	void swap(stack &o1)
	{
		
		int *temp;
		temp = o1.ar;
		o1.ar = ar;
		ar = temp;

		int s;
		s = _top;
		_top = o1._top;
		o1._top = s;
	}

	~stack()
	{
		//this is only destructure
		delete ar; //deleting array
	}

};
