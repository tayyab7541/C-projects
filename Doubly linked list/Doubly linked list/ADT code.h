#pragma once
template <typename t>
struct  node
{
	t value;
	node *next, *pre;
};

template <typename t>
class list
{
	node<t> *head;
	int _size;

public:
	list()
	{
		head = new node<t>;
		head->next = head;
		head->pre = head;
		_size = 0;
	}

	list(const list& other)
	{

		head = new node<t>;
		head->next = head;
		head->pre = head;
		_size = 0;

		operator=(other);
	}
	~list()
	{
		while (head->next != head)
		{
			node<t>* temp;
			temp = head->next;
			temp->next->pre = temp->pre;
			head->next = temp->next;
			
			delete temp;
		}
	}

	list& operator=(const list& other)
	{
		node<t>* temp;
		this->~list();
		temp = other.head->pre;

		while (temp != other.head)
		{
			this->push_front(temp->value);
			temp = temp->pre;
		}
		this->_size = other._size;
		return *this;
	}

	t& front()const
	{
		if (head->next != head)
		{
			return head->next->value;
		}
		else
		{
			throw("List underflow \n");
		}

	}
	t& back()const
	{
		if (head->pre != head)
		{
			return head->pre->value;
		}
		else
		{
			throw("List underflow \n");
		}
	}


	//iterator class 
	class iterator
	{
	private:
		node<t> *ptr;
		friend class list<t>;
	public:

		bool operator!=(const iterator& other)
		{
			if (this->ptr != other.ptr)
			{
				return true;
			}
			else
			{
				return false;
			}
		}
		int&  operator*()
		{
			return ptr->value;
		}
		iterator operator++()
		{
			ptr = ptr->next;
			return *this;
		}
		iterator operator--()
		{
			ptr = ptr->pre;
			return *this;
		}
		/*t* operator<<()
		{
			return ptr;
		}*/
	};
	class reverse_iterator
	{
	private:
		node<t> *ptr;
		friend class list<t>;
	public:

		bool operator!=(const reverse_iterator& other)
		{
			if (this->ptr != other.ptr)
			{
				return true;
			}
			else
			{
				return false;
			}
		}
		int& operator* ()
		{
			return ptr->value;
		}
		reverse_iterator operator++()
		{
			ptr = ptr->pre;
			return *this;
		}
		reverse_iterator operator--()
		{
			
			ptr = ptr->next;
			return *this;
		}
		/*t* operator<<()
		{
			return ptr;
		}*/
	};

	iterator begin()const
	{
		iterator it;
		it.ptr = head->next;
		return it;
	}
	iterator end()const
	{
		iterator it;
		it.ptr = head;
		return it;
	}
	reverse_iterator rbegin()const
	{
		reverse_iterator it;
		it.ptr = head->pre;
		return it;
	}
	reverse_iterator rend()
	{
		reverse_iterator it;
		it.ptr = head;
		return it;
	}

	int size()const
	{
		return _size;
	}



	bool empty()const
	{
		if (head->next == head && head->pre==head)
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	void clear()
	{
		while (head->next != head)
		{
			node<t>* temp;
			temp = head->next;
			temp->next->pre = temp->pre;;
			head->next = temp->next;
			delete temp;
		}
	_size= 0;
	}

	iterator erase(iterator pos)
	{
		node<t>* temp;
		temp = pos.ptr;
		temp->pre->next = temp->next;
		temp->next->pre = temp->pre;
		pos.ptr = pos.ptr->next;
		iterator it;
		it = pos.ptr;
		delete temp;
		--_size;
		return it;
	}

	void push_back(const t& num)
	{
		node<t>* nn;
		nn = new node<t>;
		nn->value = num;
		nn->pre = head->pre;
		head->pre = nn;
		nn->next = head;
		nn->pre->next = nn;
		++_size;
	}
	void push_front(const t& num)
	{
		node<t>* nn;
		nn = new node<t>;
		nn->value = num;
		nn->next = head->next;
		nn->pre = nn->next->pre;
		nn->next->pre = nn;
		nn->pre->next = nn;
		++_size;
	}
	void pop_back()
	{
		if (head->next == head)
		{
			throw("list underflow \n");
		}
		else
		{

			node<t>* temp;
			temp = head->pre;
			temp->pre->next = temp->next;
			head->pre = temp->pre;
			delete temp;
			--_size;
		}
	}

	void pop_front()
	{
		if (head->next == head)
		{
			throw("list underflow \n");
		}
		else
		{
			node<t>* temp;
			temp = head->next;
			temp->next->pre = temp->pre;
			temp->pre->next = temp->next;
			delete temp;
			--_size;
		}
	}

	void resize(const int new_size)
	{
		if (new_size == _size)
		{
			//do nothing
			return;
		}
		else if (new_size == 0)
		{
			this->~list();
		}
		else if (new_size > _size)
		{
			for (int i = _size; i < new_size; ++i)
			{
				node<t>* nn;
				nn = new node<t>;
				nn->value = int();
				nn->next = head;
				nn->pre = head->pre;
				head->pre = nn;
				nn->pre->next = nn;
			}
			_size = new_size;
		}
		else if (new_size < _size)
		{
			node<t>* temp;
			int num = _size - new_size;
			temp = head->pre;
			for (int i = num; i > 0; --i)
			{
				node<t>* del;
				del = temp;
				temp = temp->pre;
				delete del;
				--_size;
			}
			head->pre = temp;
			temp->next = head;
		}


	}

	//void merge(list& other)
	//{
	//	if() //to do next
	//}


};