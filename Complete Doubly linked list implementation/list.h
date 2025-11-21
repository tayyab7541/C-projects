#pragma once
struct node
{
	int value;
	node* next, * pre;
};


class list
{
	node *head;
	int n;
public:

	//iterator class starting here

	class iterator
	{
		friend class list;
		node* ptr;
	public:
		int& operator*()
		{
			return ptr->value;
		}
		iterator& operator++()
		{
			ptr = ptr->next;
			return *this;
		}
		iterator operator++(int)
		{
			iterator it;
			it.ptr = ptr;
			ptr = ptr->next;
			return it;
		}

		iterator& operator--()
		{
			ptr = ptr->pre;
			return *this;
		}
		iterator operator--(int)
		{
			iterator it;
			it.ptr = ptr;
			ptr = ptr->pre;
			return it;
		}
		bool operator==(const iterator& other)
		{
			if (this->ptr == other.ptr)
			{
				return true;
			}
			else
			{
				return false;
			}
		}
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
		int* operator->()
		{
			return &(ptr->value);
		}

	};

	//Reverse iterator class starting here 

	class reverse_iterator
	{
		friend class list;
		node* ptr;
	public:
		int& operator*()
		{
			return ptr->value;
		}

		reverse_iterator operator++()
		{
			ptr = ptr->pre;
			return *this;
		}
		reverse_iterator operator++(int)
		{
			reverse_iterator it;
			it.ptr = ptr;
			ptr = ptr->pre;
			return it;
		}
		reverse_iterator operator--()
		{
			ptr = ptr->next;
			return *this;
		}
		reverse_iterator operator--(int)
		{
			reverse_iterator it;
			it.ptr = ptr;
			ptr = ptr->next;
			return it;
		}

		int* operator->()
		{
			return &(ptr->value);
		}
		bool operator==(const reverse_iterator& other)
		{
			if (this->ptr == other.ptr)
			{
				return true;
			}
			else
			{
				return false;
			}

		}
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
	};


	//methods starting from here

	list()
	{
		head = new node;
		head->next = head;
		head->pre = head;
		n = 0;
	}
	list(const list& other)
	{
		this->head = new node;
		head->next = head;
		head->pre = head;
		operator=(other);
	}
	~list() 
	{
		while (head->next != head)
		{
			node* temp;
			temp = head->next;
			head->next = temp->next;
			temp->next->pre = temp->pre;
			delete temp;
			--n;

		}
	}
	list& operator=(const list& other)
	{
		node* temp;
		temp = other.head->pre;
		this->~list();
		while (temp != other.head)
		{
			push_front(temp->value);
			temp = temp->pre;

		}
		this->n = other.n;
		return *this;
	}

	int front()const
	{
		if (head->next != head)
		{
			return head->next->value;
		}
		else
		{
			throw("List underflow ");
		}
	}
	int back()const
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


	reverse_iterator rend()const
	{
		reverse_iterator it;
		it.ptr = head;
		return it;
	}

	int size()const
	{
		return n;
	}


	bool empty()const
	{
		if (head->next == head)
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	void push_front(const int& num)
	{
		node* nn;
		nn = new node;
		nn->value = num;
		nn->next = head->next;
		head->next = nn;
		nn->pre = head;
		nn->next->pre = nn;
		++n;
	}
	void push_back(const int& num)
	{
		node* nn;
		nn = new node;
		nn->value = num;
		nn->next = head->pre->next;
		head->pre->next = nn;
		nn->pre = head->pre;
		head->pre = nn;
		++n;
	}

	

	void pop_front()
	{
		if (head->next != head)
		{
			node* temp;
			temp = head->next;
			head->next = temp->next;
			temp->next->pre = temp->pre;
			delete temp;
			--n;
		}
	}
	void pop_back()
	{
		if (head->pre != head)
		{
			node* temp;
			temp = head->pre;
			temp->pre->next = temp->next;
			head->pre = temp->pre;
			delete temp;
		}
	}

	

	
	void clear()
	{
		while (head->next != head)
		{
			node* temp;
			temp = head->next;
			head->next = temp->next;
			temp->next->pre = head;
			delete temp;
			--n;
		}
	}

	void insert(const iterator& pos, const int& num)
	{
		node* temp;
		temp = new node;
		temp->value = num;
		temp->pre = pos.ptr->pre;
		pos.ptr->pre->next = temp;
		pos.ptr->pre = temp;
		temp->next = pos.ptr;
		++n;
	}

	iterator erase(const iterator pos)
	{
		if (pos.ptr != head)
		{
			iterator it;
			node* del;
			pos.ptr->pre->next = pos.ptr->next;
			pos.ptr->next->pre = pos.ptr->pre;
			it.ptr = pos.ptr->next;
			del = pos.ptr;
			--n;
			delete del;
			return it;

		}
	}

	void resize(const int& count)
	{
		if (count == n)
		{
			//do nothing 
		}
		else if (count > n)
		{
			int diff = count - n;
			for (int i = 1; i <= diff; ++i)
			{
				node* nn;
				nn = new node;
				nn->value = int();
				nn->pre = head->pre;
				nn->next = head->pre->next;
				head->pre->next = nn;
				head->pre = nn;
				++n;
			}
		}
		else
		{
			while (n != count)
			{
				node* temp;
				temp = head->pre;
				temp->pre->next = temp->next;
				head->pre = temp->pre;
				--n;
				delete temp;
			}
		}
	}

	void swap(list& other)
	{
		std::swap (this->head, other.head);
		std::swap(this->n, other.n);

	}

	void merge(list& other)
	{
		node* t1, * t2;
		t2 = other.head->next; // if other is empty it will automatically exit
		t1 = this->head->next;
		while (t1 != this->head && t2 != this->head)
		{
			t2 = other.head->next;
			if (t1->value > t2->value)
			{
				other.head->next = t2->next;
				t2->next->pre = t2->pre;
				t1->pre->next = t2;
				t2->next = t1;
				t2->pre = t1->pre;
				t1->pre = t2;
			}
			else
			{
				t1 = t1->next;
			}

		}
		if (other.head->next != other.head)
		{
			this->head->pre->next = other.head->next;
			this->head->pre->next->pre = head->pre;
			this->head->pre = other.head->pre;
			other.head->pre->next = this->head;
			other.head->pre = other.head;
			other.head->next = other.head;
			
		}
		this->n += other.n;
		other.n = 0;
	}


	void splice(const iterator &pos, list &other)
	{
		node* nn;
		nn = pos.ptr->next;
		pos.ptr->next = other.head->next;
		pos.ptr->next->pre = pos.ptr;
		node* temp;
		temp = pos.ptr->next;
		while (temp->next != other.head)
		{
			temp = temp->next;
		}
		temp->next = nn;
		nn->pre = temp;
		other.head->next = other.head;
		other.head->pre = other.head;
		this->n += other.n;
		other.n = 0;

   }

	int remove(const int& num)
	{
		node* temp;
		int removed=0;
		temp = head->next;
		while (temp != this->head)
		{
			if (temp->value == num)
			{
				temp->pre->next = temp->next;
				temp->next->pre = temp->pre;
				node* del;
				del = temp;
				temp = temp->next;
				delete del;
				++removed;
				--n;
			}
			else
			{
				temp = temp->next;
			}
		}
		return removed;
	}


	void reverse()
	{
		node* t1;
		t1 = head->next;
		while (t1->next != head)
		{
			node* nn;
			nn = head->next;
			head->next = t1->next;
			t1->next->pre = head;
			t1->next = t1->next->next;
			head->next->next = nn;
			t1->next->pre = t1;
			nn->pre = head->next;
			if (t1->pre == head)
			{
				t1->pre = head->next;
			}
		}
	}

	int unique()
	{
		int r = 0;
		node* t;
		t = head->next;
		while (t->next != head)
		{
			if (t->value == t->next->value)
			{
				node* del;
				del = t->next;
				t->next = t->next->next;
				t->next->pre = t;
				delete del;
				--n;
				++r;
			}
			else
			{
				t = t->next;
			}
		}
		return r;
	}

	void sort()
	{
		node* t1, * t2;
		t1 = head->next;
		while (t1 != head)
		{
			t2 = t1->next;
			while (t2 != head)
			{
				if (t1->value > t2->value)
				{
					int num;
					num = t1->value;
					t1->value = t2->value;
					t2->value = num;
				}
				t2 = t2->next;
			}
			t1 = t1->next;
		}
	}

	friend bool operator==(const list& l1, const list& l2);
	friend bool operator>(const list& l1, const list& l2);
	friend bool operator<(const list& l1, const list& l2);
	friend bool operator>=(const list& l1, const list& l2);
	friend bool operator<=(const list& l1, const list& l2);
	friend bool operator!=(const list& l1, const list& l2);
	friend void swap(list& l1, list& l2);
	friend int erase(list& l1, const int value);

};


bool operator==(const list& l1, const list& l2)
{
	int s1, s2;
	s1 = l1.size();
	s2 = l2.size();
	if (s1 == s2)
	{
		node* t1, * t2;
		t1 = l1.head->next;
		t2 = l2.head->next;
		while (t1 != l1.head) // as both lists are equal 
		{
			if (t1->value == t2->value)
			{
				t1 = t1->next;
				t2 = t2->next;
			}
			else
			{
				return false;
			}
		}
		return true;  //if return statement given above is not executed it means all values are equal 
	}

	else
	{
		return false;
	}
}


bool operator>(const list& l1, const list& l2)
{
	node* t1, * t2;
	t1 = l1.head->next;
	t2 = l2.head->next; 
	while (t1 != l1.head && t2 != l2.head)
	{
		if (t1->value > t2->value)  //as in lexicographical comparison we compare values upto shortest list
			                        // if all values are equal than longer list is greater 
		{
			return true; 
		}
		else if(t1->value==t2->value)
		{
			t1 = t1->next;
			t2 = t2->next;
		}
		else
		{
			return false;
		}
	}

	if (t1 != l1.head && t2 == l2.head) // checking if l2 had ended than l1 is longer 
	{
		return true;
	}
	else
	{
		return false;
	}

}

bool operator<(const list& l1, const list& l2)
{
	node* t1, * t2;
	t1 = l1.head->next;
	t2 = l2.head->next; 
	while (t1 != l1.head && t2 != l2.head)
	{
		if (t1->value < t2->value)
		{
			return true;
		}
		else if (t1->value > t2->value)
		{
			return false;

		}
		else
		{
			t1 = t1->next;
			t2 = t2->next;
		}
	}
	if (t1 == l1.head && t2 != l2.head) //if values in both lists are equal upto shorter lenght then the list having shorter length is smaller 
	{
		return true;
	}
	else //if l2 has larger length or both have equal length and equal values then
	{
		return false;
	}

}

bool operator>=(const list& l1, const list& l2)
{
	node* t1, * t2; 
	t1 = l1.head->next;
	t2 = l2.head->next;

	while (t1 != l1.head && t2 != l2.head)
	{
		if (t1->value > t2->value)
		{
			return true;
		}
		else if(t1->value == t2->value)
		{
			t1 = t1->next;
			t2 = t2->next;
		}
		else
		{
			return false;
		}
	}

	if (t2 == l2.head && t1 != l1.head)
	{
		return true;
	}
	else if (t1 == l1.head && t2 == l2.head)
	{
		return true;
	}
	else
	{
		return false;
	}

}

bool operator<=(const list& l1, const list& l2)
{
	node* t1, * t2;
	t1 = l1.head->next;
	t2 = l2.head->next;
	while (t1 != l1.head && t2 != l2.head)
	{
		if (t1->value < t2->value)
		{
			return true;
		}
		else if(t1->value==t2->value)
		{
			t1 = t1->next;
			t2 = t2->next;
		}
		else
		{
			return false;
		}
	}

	if (t1 != l1.head && t2 == l2.head)
	{
		return true;
	}
	else 
	{
		return true;
	}
}

bool operator!=(const list& l1, const list& l2)
{
	node* t1, * t2;
	t1 = l1.head->next;
	t2 = l2.head->next;
	while (t1 != l1.head && t2 != l2.head)
	{
		if (t1->value != t2->value)
		{
			return true;
		}
		else
		{
			t1 = t1->next;
			t2 = t2->next;
		}

	}

	if (t1 == l1.head && t2 == l2.head) // if both lists have same lengths and values 
	{
		return false;
	}
	else
	{
		return true;
	}
}

void swap(list& l1, list& l2)
{
	std::swap(l1, l2);
}

int erase( list& l1, const int value) // erases all the nodes that have value equal to value given as parameter
{
	int removed;
	removed = 0;
	node* t1;
	t1 = l1.head->next;
	while (t1 != l1.head)
	{
		if (t1->value == value)
		{
			node* del;
			t1->pre->next = t1->next;
			t1->next->pre = t1->pre;
			del = t1;
			t1 = t1->next;
			delete del;
			++removed;
			--l1.n;
		}
		t1 = t1->next;
		
	}
	return removed;

}