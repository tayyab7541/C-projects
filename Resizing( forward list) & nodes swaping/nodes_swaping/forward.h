#pragma once
struct node
{
	int value;
	node* link;
};
class forward
{
private:
	node* head;
	int n;
public:
	forward()
	{
		head = new node;
		head->link = head;
		n = 0;
	}
	forward(const forward& other)
	{
		head = new node;
		head->link = head;
		n = 0;
		this->operator=(other);
	}
	~forward()
	{
		while (head->link != head)
		{
			node* temp;
			temp = head->link;
			head->link = temp->link;
			delete temp;
		}
	}

	void push_front(int num)
	{
		node* nn;
		nn = new node;
		nn->value = num;
		nn->link = head->link;
		head->link = nn;
		++n;
	}
	int front()const
	{
		if (head != head->link)
		{
			return head->link->value;
		}
		else
		{
 			throw("List underflow ");
		}
	}
	void pop_front()
	{
		if (head != head->link)
		{
			node* temp;
			temp = head->link;
			head->link = temp->link;
			delete temp;
			--n;
		}
		else
		{
			throw("Underflwo ");
		}
	}

	int size()const
	{
		return n;
	}
	bool empty()const
	{
		if (head == head->link)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	forward& operator=(const forward& other)
	{
		this->~forward();
		node* temp;
		temp = other.head->link;
		node* h, * pre;
		h = pre = nullptr;
		while (temp != other.head)
		{
			node* nn;
			nn = new node;
			nn->value = temp->value;
			//nn->link = nullptr;
			if (pre == nullptr)
			{
				h = nn;
			}
			else
			{
				pre->link = nn;
			}
			pre = nn;
			temp = temp->link;
		}
		this->head->link = h;
		pre->link = this->head;
		this->n = other.n;
		return *this;
	}


	void resize(int count)
	{
		if (count == 0)
		{
			this ->~forward();
			n = 0;
		}

		else if (count == n)
		{
			//do nothing 
		}

		else if (count > n)
		{
			int size = n;
			node* temp;
			temp = head->link;
			for (int i = 1; i < count; ++i)
			{
				if (i >= size)
				{
					node* nn;
					nn = new node;
					nn->value = int();
					nn->link = temp->link;
					temp->link = nn;
					temp = nn;
					++n;
					continue;
				}

				temp = temp->link;
			}
		}

		else if (count < n)
		{
			node* temp, * temp1;
			temp1 = nullptr;
			int size = n;
			temp = head->link;
			for (int i = 0; i < size; ++i)
			{
				if (i >= count)
				{
					node* del;
					temp1->link = temp->link;
					del = temp;
					temp = temp->link;
					delete del;
					--n;
					continue;
				}
				temp1 = temp;
				temp = temp->link;
			}
		}

	}

	void swaping()
	{
		node* temp1, * temp2;
		temp2 = nullptr;
		temp1 = head->link;
		while (temp1 != head)
		{
			if (temp2 != nullptr && temp1->value == 3 && temp2->value == 4)
			{
				node* nn;
				nn = new node;
				nn->link = temp1->link;
				nn->value = temp1->value;
				temp1->link = head->link;
				temp1->value = temp2->value;
				head->link = temp2;
				temp2->value = nn->value;
				temp2->link = nn->link;
				delete nn;
				break;
			}
			temp2 = temp1;
			temp1 = temp1->link;
		}
	}
};