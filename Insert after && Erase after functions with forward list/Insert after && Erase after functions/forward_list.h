#pragma once
struct node
{
	int value;
	node* link;
	friend std::ostream& operator<< (std::ostream& o1, const node& n);
};
std::ostream& operator<<(std::ostream& o1, const node& n)
{
	o1 << n.value << "\n";
	return o1;
}

class forward_list
{
private:
	node *head;
	int n;
public:
	forward_list()
	{
		head = new node;
		head->link = nullptr;
		n = 0;
	}

	void push_front(const int& num)
	{
		node* nn;
		nn = new node;
		nn->value = num;
		nn->link = head->link;
		head->link = nn;
		++n;
	}


	int front()
	{
		return head->link->value;
	}


	void pop_front()
	{
		if (head->link != nullptr)
		{
			node* temp;
			temp = head->link;
			head->link = temp->link;
			delete temp;
			--n;
		}
		else
		{
			throw("list underflow \n");
		}
	}

	int size()const
	{
		return n;
	}
	bool empty()const
	{
		if (head->link == nullptr)
		{
			return true;
		}
		else
		{
			return false;
		}
	}


	class iterator
	{
		node* ptr;
		friend class forward_list;
	public:
		iterator& operator++()
		{
			ptr = ptr->link;
			return *this;
		}
		bool operator!=(const iterator& other)
		{
			if (ptr == other.ptr)
			{
				return false;
			}
			else
			{
				return true;
			}
		}
	   int& operator*()const
		{
			return ptr->value;
		}

	   node* operator->()const
		{
		   return ptr;
		}
	};

	iterator begin()
	{
		iterator it;
		it.ptr = head->link;
		return it;

	}

	iterator end()
	{
		iterator it;
		it.ptr = nullptr;
		return it;
	}

	iterator insert_after(const iterator& other, const int count,const int val)
	{
		node* pre, * head;
		iterator it;
		n += count;
		pre = nullptr;
		head = nullptr;
		for (int i = 1; i <= count; ++i)
		{
			node* nn;
			nn = new node;
			nn->value = val;
			nn->link = nullptr;
			if (head == nullptr)
			{
				head = nn;
			}
			else
			{
				pre->link = nn;
			}
			pre = nn;
		}
		if (count == 0)
		{
			throw("Invalid number given for number of copies");
		}
		else
		{
			pre->link = other.ptr->link;
			other.ptr->link = head;
			it.ptr = pre;
			return it;
		}
	}

	iterator erase_after(const iterator& other)
	{
		node* del;
		iterator it;
		del = other.ptr->link;
		other.ptr->link = del->link;
		delete del;
		--n;
		if (other.ptr->link == nullptr)
		{
			it.ptr = nullptr;
		}
		else
		{
			it.ptr = other.ptr->link;

		}
		return it;
	}
};
