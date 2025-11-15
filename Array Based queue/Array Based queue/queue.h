#pragma once
class queue
{
	int f, b, s, n, * ar;
public:
	queue(int c = 10)
	{
		s = c + 1;
		f = b = n = 0;
		ar = new int[s];
	}
	~queue()
	{
		delete[] ar;
	}
	void push(const int& num)
	{
		if ((b + 1) % s != f)
		{
			++n;
			b = (b + 1) % s;
			ar[b] = num;
		}
		else
		{
			throw("Queue overflow \n");
		}
	  }
	int front()const
	{
		return ar[(f + 1) % s];
	}
	void pop()
	{
		if (f != b)
		{
			f = (f + 1) % s;
			--n;
		}
		else
		{
			throw("queue underflow ");
		}
	}
	int size()const
	{
		return n;
	}
	bool empty()const
	{
		if (f == b)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	queue& operator=(const queue& other)
	{
		this->ar = nullptr;
		delete[] ar;

		this->ar = new int[other.s];

		int s1 = other.f;
		for (int i = 0; i <other.n; ++i)
		{
			this->ar[(s1 + 1) % other.s] = other.ar[(s1 + 1) % other.s];
			s1 =( s1 + 1) % other.s;
		}

		this->f = other.f;
		this->b = other.b;
		this->n = other.n;
		this->s = other.s;
		return *this;

	}

	friend bool operator==(const queue& lhs, const queue& rhs);

};

bool operator==(const queue& lhs, const queue& rhs)
{
	int s1, s2;
	s1 = lhs.size();
	s2 = rhs.size();
	if (s1 != s2)
	{
		return false;
	}
	else
	{
		bool found = false;
		int f1 = lhs.f;
		int f2 = rhs.f;
		for (int i = 1; i <= s1; ++i)
		{
			if (lhs.ar[(f1 + 1) % s1] == rhs.ar[(f1 + 1) % s1])
			{
				f1 = (f1 + 1) % s1;
				f2 = (f2 + 1) % s1;

			}
			else
			{   
				return false;
			}
		}

		if (!found)
		{
			return true;
		}
	}

}