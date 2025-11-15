#pragma once

class stack
{
private:
	char* ar;
	int s;
	int t;
public:
	stack(int si = 100)
	{
		s = si;
		t = -1;
		ar = new char[s];
	}

	void push(const char& a)
	{
		if (t < s - 1)
		{
			++t;
			ar[t] = a;
		}
		else
		{
			throw("Stack overflow");
		}
	}
	char top()const
	{
		if (t >= 0)
		{
			return ar[t];
	   }
		else
		{
			throw("stack underflow \n");
		}
	}

	void pop()
	{
		if (t >= 0)
		{
			--t;
		}
		else
		{
			throw("Stack underflow");
		}
	}
	int size()const
	{
		return t + 1;
	}
};


bool compare(std::string st, char *e, const int size)
{
	int i = 0;
	bool found;

	for (char ch : st)
	{
		found = false;
		if (ch >= 'a' && ch <= 'z' || ch >= 'A' || ch <= 'Z')
		{
			if (ch == e[i])
			{
				found = true;
				++i;
				continue;
			}
			else
			{
				return false;
			}

			
		}
	}

	if (found)
	{
		return true;
	}
}