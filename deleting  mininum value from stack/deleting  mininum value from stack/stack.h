#pragma once
struct node
{
	int value;
	node* link;
};
class stack
{
	node* _top;
	int n;
public:
	stack()
	{
		_top = nullptr;
		n = 0;
	}
	~stack()
	{
		while (_top != nullptr)
		{
			node* del;
			del = _top;
			_top = _top->link;
			delete del;
		}
	}
	void push(const int num)
	{
		node* nn;
		nn = new node;
		nn->value = num;
		nn->link = _top;
		_top = nn;
		++n;
	}
	void pop()
	{
		if (_top != nullptr)
		{
			node* del;
			del = _top;
			_top = _top->link;
			delete del;
			--n;
		}
		else
		{
			throw("Stack underflow \n");
		}
	}
	int top()const
	{
		return _top->value;
	}
	int size()const
	{
		return n;
	}

	bool empty()const
	{
		if (_top == nullptr)
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	void del_min()
	{
		int min = INT_MAX;
		node* temp, *pre;
		temp = _top;
		while (temp != nullptr)
		{
			if (min > temp->value)
			{
				min = temp->value;
			}
			temp = temp->link;
		}

		temp = _top;
		pre = nullptr;
		while (temp != nullptr)
		{
			if (temp->value == min && pre == nullptr)
			{
				node* del;
				del = temp;
				_top = temp->link;
				temp = temp->link;
				delete del;
				--n;
				continue;
			}
			else if (temp->value == min)
			{
				node* del;
				del = temp;
				pre->link = temp->link;
				temp = temp->link;
				delete del;
				--n;
				continue;
			}
			pre = temp;
			temp = temp->link;
		}

	}

};