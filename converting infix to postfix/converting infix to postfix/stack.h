#pragma once
struct postfix
{
	std::string ch;
	postfix* link;
};
class stack
{
	postfix *ar;
	int n;
public:
	stack()
	{
		n = 0;
		ar = nullptr;
	}

	void push(const std::string e)
	{
		postfix* temp;
		temp = new postfix; //TO Do delte in pop
		temp->ch = e;
		temp->link = ar;
		ar = temp;
		++n;
	}
	std::string top()const
	{
		if (n == 0)
		{
			throw("");
		}
		else
		{
			return ar->ch;
		}
		
	}
	void pop()
	{
		postfix* temp;
		temp = ar;
		ar = ar->link;
		delete temp;
		--n;
	}

	int size()const
	{
		return n;
	}
	bool empty()const
	{
		if (ar == nullptr)
		{
			return true;
		}
		else
		{
			return false;
		}

	}



};

int precedence(std::string ch)
{
	if (ch == "+")
	{
		return 1;
	}
	else if (ch == "-")
	{
		return 1;
	}
	else if (ch == "*")
	{
		return 2;
	}
	else if (ch == "/")
	{
		return 2;
	}
	else if (ch == "(")
	{
		return 0;
	}
	else if (ch == "^")
	{
		return 5;
	}

}