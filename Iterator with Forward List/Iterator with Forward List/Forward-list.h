#pragma once 
struct node
{
	int value;
	node *link;
	bool ishead;
	node() {
		ishead = false;
	}
};
class forward_list
{
private:
	node *h;
public:
	forward_list()
	{
		h = new node;
		h->link = h;
		h->ishead = true;

	}
	~forward_list()
	{
		delete h;
	}
	void push_front(int num)
	{
		node* nn;
		nn = new node;
		nn->value = num;
		nn->link = h->link;
		h->link = nn;

	}
	int front()const
	{
		return h->link->value;

	}
	void pop_front()
	{
		if (h != h->link)
		{
			node* temp;
			temp = h->link;
			h->link = temp->link;
			delete temp;
		}
		else
		{
			throw("Underflow occured ");
		}
	}
	bool empty()const
	{
		if (h == h->link)
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	int size()
	{
		node *temp;
		temp = h->link;
		int s = 0;
		while (temp != h)
		{
			++s;
			temp = temp->link;
		}
		return s;
	}
 
	
class iterator
	{
	node* ptr;
	node* fix;
	friend class forward_list;
	public:
		
		int& operator*()
		{
			return this->ptr->value;
		}
		iterator operator++()
		{
			if (!ptr->link->ishead)
			{
				this->ptr = this->ptr->link;
				return *this;
			}
			else
			{
				this->ptr = nullptr;
				return *this;
			}
		}

		iterator operator++(int)
		{
			if (ptr->link != fix)
			{
				ptr = ptr->link;
				return *this;
			}
			else
			{
				ptr = nullptr;
				return *this;
			}
		}

		bool operator!=(const iterator & other)
		{
			if (this->ptr == other.ptr)
			{
				return false;
			}
			else
			{
				return true;
			}

		}
	};


	iterator end()const
	{
		iterator it{};
		it.ptr = nullptr;
		return it;
	}
	iterator before_begin()const
	{
		iterator it{};
		it.ptr = h;
		it.fix = h;
		return it;
	}
	iterator begin()const
	{
		iterator it{};
		it.ptr = h->link;
		return it;
   }

};

