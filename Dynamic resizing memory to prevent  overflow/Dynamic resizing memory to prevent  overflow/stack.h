#pragma once
template <typename t>
class stack
{
private:
	t* ar;
	int _size;
	int _top;
public:
	stack(int s = 10)
	{
		_size = s;
		_top = -1;
		ar = new t[_size];
	}
	void push(t ch )
	{
		if (_top == _size-1)
		{
			++_top;
			_size += _size;
			t* temp;
			temp = new t[_size];
			for (int i = 0; i <= _top; i++)
			{
				if (i < _top)
				{
					temp[i] = ar[i];
				}
			else if (i == _top)
				{
					temp[i] = ch;
				}
			}

			delete[] ar;
			ar = temp;
			temp = nullptr;
			
		}
		else
		{
			++_top;
			ar[_top] = ch;
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
			throw("Stack unerflow occured ");
		}
	}
	t top()const
	{
		return ar[_top];
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