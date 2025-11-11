#pragma once
template <typename t>
struct node
{
	t operand;
	node *link;
};

template <typename t>
class stack
{
	node<t> *array;

public:
	stack()
	{
		array = nullptr;
	}
	~stack()
	{
		while (array != nullptr)
		{
			node<t>* temp;
			temp = array;
			array = array->link;
			delete temp;
		}
	}
	void push(const t& num)
	{
		node<t> *temp;
		temp = new node<t>;
		temp->operand = num;
		temp->link = array;
		array = temp;
	}

	t top()const
	{
		if (array != nullptr)
		{
			return array->operand;
		}
		else
		{
			throw("Invalid Expression ");
		}
	}
	void pop()
	{
		if (array != nullptr)
		{
			node<t>* temp;
			temp = array;
			array = array->link;
			delete temp;
		}
		else
		{
			throw("Invalid Expression ");
		}

		
	}

	bool empty()const
	{
		if (array == nullptr)
		{
			return true;
		}
		else
		{
			return false;
		}
	}



};


int math(int num1, int num2, std::string ope)
{
	if (ope == "+")
	{
		return num1 + num2;
	}
	else if (ope == "-")
	{
		return num1 - num2;
	}
	else if (ope == "*")
	{
		return num1 * num2;
	}
	else if (ope == "/")
	{
		if (num2 != 0)
		{
			return num1 / num2;
		}
		else
		{
			throw("Invalid operation Division by Zero\n");
		}
	}
	else if (ope == "^")
	{
		return std::pow(num1, num2); //thisfunction id defined below
	}
	else
	{
		throw("Invalid operator");
	}
}

 


int precedence(std::string ope)
{
	if (ope == "+" || ope == "-")
	{
		return 1;
	}
	else if (ope == "*" || ope == "/")
	{
		return 2;
	}
	else if (ope == "(")
	{
	 return 3;
	}
	else if (ope == "^")
	{
		return 4;
	}

}