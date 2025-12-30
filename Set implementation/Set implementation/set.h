#pragma once
#include <utility>
struct node
{
	int val;
	node* left, * right, * parent;
	bool is_nill;
	node()
	{
		is_nill = false;
	}
};


class set
{
	node* head;
	int n;

	node* non_leaf(node* temp)
	{
		if (temp == head)
		{
			return 0;
		}
		if (temp->left == temp->right)
		{
			return temp->parent;
		}
		return non_leaf(temp->left); // we consider that the first non leaf node is in left subtree of root if we consider the first non leaf node on right of root then we should call non_leaf(temp->right) first  
	    return non_leaf(temp->right);
		
	
	}
	void count_leaves(node* temp, int& number)
	{
		if (temp == head)
		{
			return;
		}
		count_leaves(temp->left, number);
		count_leaves(temp->right, number);
		if (temp->left == temp->right)
		{
			++number;
		}
	}
	void counting(node* ptr, int& num,int val)
	{
		if (ptr == this->head)
			return;
		counting(ptr->left,num,val);
		counting(ptr->right, num,val);

		if (val == ptr->val)
		{
			++num;
		}

	}

	node* predecessor(node* ptr)
	{
		ptr = ptr->left;
		while (ptr->right != this->head)
		{
			ptr = ptr->right;
		}
		return ptr;
	}
	node* successor(node* ptr)
	{
		ptr = ptr->right;
		while (ptr->left != this->head)
		{
			ptr = ptr->left;
		}
		return ptr;
	}

	void clear_recursive(node *ptr)
	{
		if (ptr ==this->head)
		{
			return;

		}
		else
		{
			clear_recursive(ptr->left);
			clear_recursive(ptr->right);
			delete ptr;
		}
	}


	set& copy(node* temp)
	{
		if (temp != this->head)
		{
			node* nn;
			nn = new node;
			nn->val = temp->val;
			nn->left = nn->right = head;
			if (this->head->parent == this->head)
			{
				this->head->left = nn;
				this->head->right = nn;
				this->head->parent = nn;
				nn->parent = this->head;
			}
			else
			{
				node* m = this->head->parent;

				while (1)
				{
					if (m->val == nn->val)
					{
						break;
				    }
					else if (m->val > nn->val)
					{
						if (m->left != head)
						{
							m = m->left;
						}
						else
						{
							m->left = nn;
							nn->parent = m;
							if (head->left->val > nn->val)
							{
								head->left = nn;
							}
							break;
						}
					}
					else
					{
						if (m->right != head)
						{
							m = m->right;
						}
						else
						{
						
							m->right = nn;
							nn->parent = m;
							if (this->head->right->val < nn->val)
							{
								this->head->right = nn;
							}
							break;
						}
					}
				}
			}

		return 	copy(temp->left);
		return 	copy(temp->right);
		}
	}



	//this is obvious that we would use post order traversal in mergin of two sets 
	void merge_recursivly(node* ptr, set& this_s,set &other)
	{

		if (ptr == other.head)
			return;
		merge_recursivly(ptr->left, this_s,other);
		merge_recursivly(ptr->right, this_s,other);
		node* temp;
		temp = this_s.head->parent;
		while (1)
		{
			if (temp->val == ptr->val)
			{
				break;
			}
			else if (temp->val > ptr->val)
			{
				if (temp->left != this_s.head)
				{
					temp = temp->left;
				}
				else
				{
					if (ptr->parent ==other.head)
					{
						if (ptr->left == ptr->right)
						{
							head->parent == head;
							head->left == head;
							head->right == head;

							temp->left = ptr;
							ptr->parent = temp;
							ptr->left = ptr->right = this->head;

							++this_s.n;
							--other.n;
						}
						else if (ptr->left != other.head && ptr->right == other.head)
						{
							node* pre;
							pre = ptr->left;
							while (pre->right !=other.head)
							{
								pre = pre->right;
							}
							if (ptr == ptr->left)
							{
								other.head->parent = pre;
								other.head->right = pre;
								temp->left = ptr;
								ptr->parent = temp;
								ptr->left = ptr->right = this->head;

								++this_s.n;
								--other.n;
							}
							else
							{
								node* p = pre->parent;
								node* ch = pre->left;
								p->right = ch;
								if (ch != other.head)
								{
									ch->parent = p;
								}
								other.head->parent = pre;
								pre->left = ptr->left;
								pre->parent = ptr->parent;
								temp->left = ptr;
								ptr->parent = temp;
								ptr->left = ptr->right = this->head;

								++this_s.n;
								--other.n;
							}
						}
						else if (ptr->left ==other.head && ptr->right !=other.head)
						{
							node* succ;
							succ = ptr->right;
							while (succ->left != other.head)
							{
								succ = succ->left;
							}
							other.head->parent = succ;
							if (ptr == ptr->left)
							{
								other.head->parent =succ;
								other.head->left = succ;
								temp->left = ptr;
								ptr->parent = temp;
								ptr->left = ptr->right = this->head;

								++this_s.n;
								--other.n;
							}
							else
							{
								node* p = succ->parent;
								node* ch = succ->right;
								p->left = ch;
								if (ch != other.head)
								{
									ch->parent = p;
								}
								succ->right = ptr->right;
								succ->parent = ptr->parent;
								temp->left = ptr;
								ptr->parent = temp;
								ptr->left = ptr->right = this->head;

								++this_s.n;
								--other.n;
							}
						}
						else
						{
							node* succ;
							succ = ptr->right;
							while (succ->left != other.head)
							{
								succ = succ->left;
							}
							other.head->parent = succ;
							if (succ == ptr->right)
							{
								succ->left = ptr->left;
								ptr->left->parent = succ;
								succ->parent = ptr->parent;
								other.head->parent = succ;
								temp->left = ptr;
								ptr->parent = temp;
								ptr->left = ptr->right = this->head;

								++this_s.n;
								--other.n;
							}
							else
							{
								node* p = succ->parent;
								node* ch = succ->right;
								p->left = ch;
								if (ch != other.head)
								{
									ch->parent = p;
								}
								succ->left = ptr->left;
								succ->right = ptr->right;
								ptr->left->parent = succ;
								ptr->right->parent = succ;
								succ->parent = ptr->parent;
								other.head->parent = succ;
								temp->left = ptr;
								ptr->parent = temp;
								ptr->left = ptr->right = this->head;

								++this_s.n;
								--other.n;
							}
						}
					}

			else if (ptr == ptr->parent->left)
					{
						if(ptr->left==ptr->right)
						ptr->parent->left = other.head;
						else if (ptr->left == other.head && ptr->right != other.head)
						{
							ptr->parent->left = ptr->right;
							ptr->right->parent = ptr->parent;
						}
						else if (ptr->left != other.head && ptr->right == other.head)
						{
							ptr->parent->left = ptr->left;
							ptr->left->parent = ptr->parent;
						}
						else
						{
							ptr->parent->left = ptr->left;
							ptr->left->right = ptr->right;
							ptr->right->parent = ptr->left;
							ptr->left->parent = ptr->parent;
						}

					}
					else
					{
						if (ptr->left == ptr->right)
							ptr->parent->right = other.head;
						else if (ptr->left == other.head && ptr->right != other.head)
						{
							ptr->parent->right = ptr->right;
							ptr->right->parent = ptr->parent;
						}
						else if (ptr->left != other.head && ptr->right == other.head)
						{
							ptr->parent->right= ptr->left;
							ptr->left->parent = ptr->parent;
						}
						else
						{
							ptr->parent->right = ptr->left;
							ptr->left->right = ptr->right;
							ptr->right->parent = ptr->left;
							ptr->left->parent = ptr->parent;
						}
					}
					temp->left = ptr;
					ptr->parent = temp;
					ptr->left = ptr->right = this->head;

					++this_s.n;
					--other.n;
					break;

				}
			}
			else
			{
				if (temp->right != this_s.head)
				{
					temp = temp->right;
				}
				else
				{


					if (ptr->parent ==other. head)
					{
						if (ptr->left == ptr->right)
						{
							other.head->parent == head;
						    other.head->left == head;
						    other.head->right == head;

							temp->right = ptr;
							ptr->parent = temp;
							ptr->left = ptr->right = this->head;

							++this_s.n;
							--other.n;
						}
						else if (ptr->left != other.head && ptr->right ==other.head)
						{
							node* pre;
							pre = ptr->left;
							while (pre->right != other.head)
							{
								pre = pre->right;
							}
							if (ptr == ptr->left)
							{
								other.head->parent = pre;
								other.head->right = pre;
								temp->right = ptr;

								ptr->parent = temp;
								ptr->left = ptr->right = this->head;

								++this_s.n;
								--other.n;
							}
							else
							{
								node* p = pre->parent;
								node* ch = pre->left;
								p->right = ch;
								if (ch != other.head)
								{
									ch->parent = p;
								}
								other.head->parent = pre;
								pre->left = ptr->left;
								pre->parent = ptr->parent;
								temp->right = ptr;

								ptr->parent = temp;
								ptr->left = ptr->right = this->head;

								++this_s.n;
								--other.n;
							}
						}
						else if (ptr->left == other.head && ptr->right !=other.head)
						{
							node* succ;
							succ = ptr->right;
							while (succ->left != other.head)
							{
								succ = succ->left;
							}
							other.head->parent = succ;
							if (ptr == ptr->left)
							{
								head->parent = succ;
								head->left = succ;
								temp->right = ptr;

								ptr->parent = temp;
								ptr->left = ptr->right = this->head;

								++this_s.n;
								--other.n;
							}
							else
							{
								node* p = succ->parent;
								node* ch = succ->right;
								p->left = ch;
								if (ch != other.head)
								{
									ch->parent = p;
								}
								succ->right = ptr->right;
								succ->parent = ptr->parent;
								temp->right = ptr;

								ptr->parent = temp;
								ptr->left = ptr->right = this->head;

								++this_s.n;
								--other.n;
							}
						}
						else
						{
							node* succ;
							succ = ptr->right;
							while (succ->left != other.head)
							{
								succ = succ->left;
							}
							other.head->parent = succ;
							if (succ == ptr->right)
							{
								succ->left = ptr->left;
								ptr->left->parent = succ;
								succ->parent = ptr->parent;
								head->parent = succ;
								temp->right = ptr;

								ptr->parent = temp;
								ptr->left = ptr->right = this->head;

								++this_s.n;
								--other.n;
							}
							else
							{
								node* p = succ->parent;
								node* ch = succ->right;
								p->left = ch;
								if (ch != other.head)
								{
									ch->parent = p;
								}
								succ->left = ptr->left;
								succ->right = ptr->right;
								ptr->left->parent = succ;
								ptr->right->parent = succ;
								succ->parent = ptr->parent;
								other.head->parent = succ;
								temp->right = ptr;

								ptr->parent = temp;
								ptr->left = ptr->right = this->head;

								++this_s.n;
								--other.n;
							}
						}
					}


				else if (ptr == ptr->parent->left)
				{
					if (ptr->left == ptr->right)
						ptr->parent->left = other.head;
					else if (ptr->left == other.head && ptr->right != other.head)
					{
						ptr->parent->left = ptr->right;
						ptr->right->parent = ptr->parent;
					}
					else if (ptr->left != other.head && ptr->right == other.head)
					{
						ptr->parent->left = ptr->left;
						ptr->left->parent = ptr->parent;
					}
					else
					{
						ptr->parent->left = ptr->left;
						ptr->left->right = ptr->right;
						ptr->right->parent = ptr->left;
						ptr->left->parent = ptr->parent;
					}

					}
				else
				{
					if (ptr->left == ptr->right)
						ptr->parent->right = other.head;
					else if (ptr->left == other.head && ptr->right != other.head)
					{
						ptr->parent->right = ptr->right;
						ptr->right->parent = ptr->parent;
					}
					else if (ptr->left != other.head && ptr->right == other.head)
					{
						ptr->parent->right = ptr->left;
						ptr->left->parent = ptr->parent;
					}
					else
					{
						ptr->parent->right = ptr->left;
						ptr->left->right = ptr->right;
						ptr->right->parent = ptr->left;
						ptr->left->parent = ptr->parent;
					}
				}

					temp->right = ptr;
					ptr->parent = temp;
					ptr->left = ptr->right = this->head;
					++this_s.n;
					--other.n;
					break;
				}
			}

		}
	}
public:
	set()
	{
		head = new node;
		head->parent = head;
		head->left = head;
		head->right = head;
		head->is_nill = true;
		n = 0;
	}
	
	set(const set& other)
	{
		operator=(other);
	}
	~set()
	{
		this->clear_recursive(this->head->parent);
	}

	set& operator=(const set& other)
	{

		this->n = other.n;
	return copy(other.head->parent);

	}

	
	class iterator
	{
		node* ptr;
		friend class set;
	public:
		int operator*()
		{
			return ptr->val;
		}
		int* operator->()
		{
			return &(ptr->val);
		}
		iterator& operator++()
		{
			if (!ptr->right->is_nill)
			{
				ptr = ptr->right;
				while (!ptr->left->is_nill)
				{
					ptr = ptr->left;
				}
				return *this;
			}
			else
			{
				while (ptr == ptr->parent->right && ptr->parent->is_nill != true)
				{
					ptr = ptr->parent;
				}
				ptr = ptr->parent;
				return *this;
			}
		}
		iterator operator--()
		{
			if (!ptr->left->is_nill)
			{
				ptr = ptr->left;
				while (!ptr->right->is_nill)
				{
					ptr = ptr->right;
				}
				return *this;
			}
			else if (ptr == ptr->left->left)
			{
				throw("you cannot go beyond this limit");
			}
			else
			{

				while (ptr == ptr->parent->left && !ptr->parent->is_nill)
				{
					ptr = ptr->parent;
				}
				ptr = ptr->parent;
				return *this;
			}
		}
		bool operator!=(const iterator& other)
		{
			return this->ptr != other.ptr;
		}
		bool operator==(const iterator& other)
		{
			return this->ptr == other.ptr;
		}
	};

	iterator begin()const
	{
		iterator it;
		it.ptr = head->left;
		return it;
	}
	iterator end()const
	{
		iterator it;
		it.ptr = this->head;
		return it;
	}


	class reverse_iterator
	{
		node* ptr;
		friend class set;
	public:
		int operator*()
		{
			return ptr->val;

		}
		int* operator->()
		{
			return &(ptr->val);
		}
		reverse_iterator operator++()
		{
			if (!ptr->left->is_nill)
			{
				ptr = ptr->left;
				while (!ptr->right->is_nill)
				{
					ptr = ptr->right;
				}
				return *this;
			}
			else
			{
				while (ptr != ptr->parent->right && !ptr->parent->is_nill)
				{
					ptr = ptr->parent;
				}
				ptr = ptr->parent;
				return *this;
			}
		}
		bool operator!=(const reverse_iterator& other)
		{
			return this->ptr != other.ptr;
		}
		bool operator==(const reverse_iterator& other)
		{
			return this->ptr == other.ptr;
		}

	};


	reverse_iterator rbegin()const
	{
		reverse_iterator it;
		it.ptr = this->head->right;
		return it;
	}
	reverse_iterator rend()const
	{ 
		reverse_iterator it;
		it.ptr = this->head;
		return it;
	}
	bool empty()const
	{
		if (this->head->parent == this->head)
		{
			return true;
		}
		return false;
	}

	int size()const
	{
		return n;
	}

	void clear()
	{
		this->clear_recursive(this->head->parent);
		this->head->parent = this->head;
		this->head->left = head;
		this->head->right = this->head;
		n = 0;
	}


    std::pair<iterator,bool>  insert(const int& val)
	{
		node* nn;
		nn = new node;
		nn->val = val;
		nn->left = head;
		nn->right = head;
		iterator it;
		it.ptr = nn;
		if (this->head->parent == head)
		{
			this->head->parent = nn;
			this->head->left = nn;
			this->head->right = nn;
			nn->parent = this->head;
			++n;
			return {it,true};
		}
		else
		{
			node* temp = head->parent;
			while (1)
			{
				if (temp->val == nn->val)
				{
					it.ptr = temp;
					return { it,false };
				}
				else if (temp->val > nn->val)
				{
					if (temp->left != this->head)
					{
						temp = temp->left;

					}
					else
					{
						temp->left = nn;
						nn->parent = temp;
						if (this->head->left->val > nn->val)
						{
							this->head->left = nn;
						}
						++n;
						return { it,true };
					}
				}
				else
				{
					if (temp->right != this->head)
					{
						temp = temp->right;
					}
					else
					{
						temp->right = nn;
						nn->parent = temp;
						if (this->head->right->val < nn->val)
						{
							this->head->right = nn;
						}
						++n;
						return { it,true };
					}
				}
			}
		}
	}
	iterator erase(iterator pos)
	{
		node* del;
		del = pos.ptr;
		--n;

		if (del->parent != this->head)
		{
			if (del->left == del->right)
			{
				if (del == del->parent->left)
				{
					del->parent->left = this->head;
					delete del;
					pos.ptr = this->head;
					return pos;
				}
				else
				{
					del->parent->right = head;
					delete del;
					pos.ptr = head;
					return pos;
				}
			}


			else if (del->left!= head && del->right == head)
			{
				node* pre = predecessor(del);
				pos.ptr = pre;

				if (head->left == del)
				{
					head->left = pre;
				}
				else if (head->right == del)
				{
					head->right = pre;
				}
				if (del->left == pre)
				{
					if (del == del->parent->left)
					{
						del->parent->left = pre;
					}
					else
					{
						del->parent->right = pre;
					}
					pre->parent = del->parent;
					delete del;
				}
				else
				{
					node* p = pre->parent;
					node* ch = pre->left;
					p->right = ch;
					if (ch != head)
					{
						ch->parent = p;
					}
					pre->left = del->left;
					del->left->parent = pre;

					if (del == del->parent->left)
					{
						del->parent->left = pre;
					}
					else
					{
						del->parent->right = pre;
					}
					pre->parent = del->parent;
					delete del;
				}
				return pos;
			}
			else if (del->left == head && del->right != head)
			{
				node* succ = successor(del);

				if (head->right == del)
				{
					head->right = succ;
				}
				else if (head->left == del)
				{
					head->left = succ;
				}
				pos.ptr = succ;
				if (del == del->right)
				{
					if (del == del->parent->left)
					{
						del->parent->left = succ;
						succ->parent = del->parent;
						delete del;
					}
					else
					{
						del->parent->right = succ;
						succ->parent = del->parent;
						delete del;
					}
				}
				else
				{
					node* p = succ->parent;
					node* ch = succ->right;
					p->left = ch;
					if (ch != head)
					{
						ch->parent = p;
					}
					succ->right = del->right;
					del->right->parent = succ;
					succ->parent = del->parent;
					if (del == del->parent->left)
					{
						del->parent->left = succ;
					}
					else
					{
						del->parent->right = succ;
					}
					delete del;
				}
				return pos;
			}
			else
			{
				node* succ = this->successor(del);
				pos.ptr = succ;
				if (succ == del->right)
				{
					succ->left = del->left;
					del->left->parent = succ;
					if (del == del->parent->left)
					{
						del->parent->left = succ;
					}
					else
					{
						del->parent->right = succ;
					}
					succ->parent = del->parent;
					delete del;
				}
				else
				{
					node* p = succ->parent;
					node* ch = succ->right;
					p->left = ch;
					if (ch != this->head)
					{
						ch->parent = p;
					}
					succ->left = del->left;
					succ->right = del->right;
					del->right->parent = succ;
					del->left->parent = succ;
					if (del == del->parent->left)
					{
						del->parent->left = succ;
					}
					else
					{
						del->parent->right = succ;
					}
					succ->parent = del->parent;
					delete del;
				}
				return pos;
			}

		}
		else
		{
			
			if (del->left == del->right)
			{
				head->parent = head;
				head->left = head;
				head->right = head;
				pos.ptr = head;
				return pos;
			}
			else if (del->left == head && del->right != head)
			{
				node* succ = successor(del);
				succ = pos.ptr;
				if (succ == del->right)
				{
					head->left = succ;
					head->parent = succ;
					succ->parent = head;
					delete del;
				}
				else
				{
					head->left = succ;
					head->parent = succ;
					node* p = succ->parent;
					node* ch = succ->right;
					p->left = ch;
					if (ch != head)
					{
						ch->parent = p;
					}
					succ->right = del->right;
					del->right->parent = succ;
					succ->parent = head;
					delete del;
				}
				return pos;
			}
			else if (del->left != head && del->right == head)
			{

				node* pre = predecessor(del);
				pos.ptr = pre;
				if (pre == del->left)
				{
					head->parent = pre;
					head->right = pre;
					pre->parent = head;
					delete del;
				}
				else
				{
					head->parent = pre;
					head->right = pre;
					node* p = pre->parent;
					node* ch = pre->left;
					p->right = ch;
					if (ch != head)
					{
						ch->parent = p;
					}
					pre->left = del->left;
					del->left->parent = pre;
					pre->parent = head;
					delete del;

				}
				return pos;
			}
			else
			{
				node* succ = successor(del);
				pos.ptr = succ;
				if (succ == del->right)
				{
					succ->left = del->left;
					del->left->parent = succ;
					head->parent = succ;
					succ->parent = head;
					delete del;
				}
				else
				{
					node* p = succ->parent;
					node* ch = succ->right;
					p->left = ch;
					if (ch != head)
					{
						ch->parent = p;
					}
					succ->left = del->left;
					del->left->parent = succ;
					succ->right = del->right;
					del->right->parent = succ;
					succ->parent = head;
					head->parent = succ;
					delete del;
				}
				return pos;
			}
		}
	}

	void merge(set& other)
	{
		merge_recursivly(other.head->parent, *this, other);
	}

	int count(int val)
	{
		int number = 0;
		counting(this->head->parent, number, val);
		return number;
	}

	iterator find(const int val)
	{
		iterator it;
		it.ptr = this->head;

		node* temp;
		temp = this->head->parent;
		while (temp != head)
		{
			if (temp->val == val)
			{
				it.ptr = temp;
				return it;
			}
			else if (temp->val > val)
			{
				temp = temp->left;
			}
			else
			{
				temp = temp->right;
			}
		}
		return it;
	}

	bool conatins(const int val)
	{
		iterator it = find(val);
		if (it.ptr == this->head)
		{
			return false;
		}

		return true;
	}
	iterator upper_bound(const int val)
	{
		iterator it;
		it.ptr = this->head;
		node* temp = this->head->parent;
		while (temp != this->head)
		{
			if (temp->val == val)
			{
				node* succ;
				succ = temp->right;
				if (temp->right == head)
				{
					it.ptr = this->head;
					return it;
				}
				while (succ->left != this->head )
				{
					succ = succ->left;
				}
				it.ptr = succ;
				return it;
			}
			else if (temp->val > val)
			{
				temp = temp->left;
			}
			else
			{
				temp = temp->right;
			}
		}
		return it;
	}
	iterator lower_bound(const int val)
	{
		node* temp;
		temp = this->head->parent;
		iterator it;
		it.ptr = this->head;
		while (temp != this->head)
		{
			if (temp->val == val)
			{
				it.ptr = temp;
				return it;
			}
			else if (temp->val > val)
			{
				temp = temp->left;
			}
			else
			{
				temp = temp->right;
			}
		}
		return it;
	}

	int leaves()
	{
		int num = 0;
		count_leaves(this->head->parent, num);
		return num;
	}

	iterator first_non_leaf_node()
	{
		iterator it;
		it.ptr = non_leaf(this->head->parent);
		return it;
	}
};