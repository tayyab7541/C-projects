#pragma once
#include "struct.h"
template <typename value>
class set
{
	node<value> *head;
	int _size;

	void destroy_set(node<value>* ptr)
	{
		if (ptr != this->head)
		{
			destroy_set(ptr->left);
			destroy_set(ptr->right);
			delete ptr;
			--_size;
		}
	}

	node<value>* successor(node<value>* temp)
	{
		temp = temp->right;
		while (temp->left != this->head)
		{
			temp = temp->left;
		}
		return temp;
	}

	node<value>* predecessor_find(node<value>* temp)
	{
		temp = temp->left;
		while (temp->right != this->head)
		{
			temp = temp->right;
		}

		return temp;
	}
public:

	// iterator class starting here
	class iterator
	{
		friend class set<value>;
		node<value>* ptr;
	public:

		value& operator*()
		{
			return ptr->val;
		}

		value* operator->()
		{
			return &ptr->val;
		}


		bool operator!=(const iterator& other)
		{
			if (this->ptr != other.ptr)
			{
				return true;
			}
			return false;  // if codition will be true then control will not come here 
		}


		bool operator==(const iterator& other)
		{
			if (this->ptr == other.ptr)
			{
				return true;
			}
			return false;
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
				while (ptr != ptr->parent->left && ptr->parent->is_nill != true)
				{
					ptr = ptr->parent;
				}
				ptr = ptr->parent;
				return *this;
			}
		}
		iterator operator++(int)
		{
			iterator  temp;
			temp.ptr = this->ptr;
			if (!ptr->right->is_nill)
			{
				ptr = ptr->right;
				while (!ptr->left->is_nill)
				{
					ptr = ptr->left;
				}
				return temp;
			}
			else
			{
				while (ptr != ptr->parent->left && ptr->parent->is_nill != true)
				{
					ptr = ptr->parent;
				}
				ptr = ptr->parent;
				return temp;
			}
		}

	};



	//reverse iterator class starting here 
	class reverse_iterator
	{
		friend class set<value>;
		node<value>* ptr;
	public:

		value& operator*()
		{
			return ptr->val;
		}

		value* operator->()
		{
			return &ptr->val;
		}


		bool operator!=(const reverse_iterator& other)
		{
			if (this->ptr != other.ptr)
			{
				return true;
			}
			return false;  // if codition will be true then control will not come here 
		}

		bool operator==(const reverse_iterator& other)
		{
			if (this->ptr == other.ptr)
			{
				return true;
			}
			return false;
		}

		reverse_iterator& operator++()
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

		reverse_iterator operator++(int)
		{
			reverse_iterator it;
			it.ptr = this->ptr;

			if (!ptr->left->is_nill)
			{
				ptr = ptr->left;
				while (!ptr->right->is_nill)
				{
					ptr = ptr->right;
				}
				return it;
			}
			else
			{
				while (ptr != ptr->parent->right && !ptr->parent->is_nill)
				{
					ptr = ptr->parent;
				}
				ptr = ptr->parent;
				return it;
			}
		}



	};

	set()
	{
		head = new node<value>;
		head->is_nill = true;
		head->left = head;
		head->right = head;
		head->parent = head;
		_size = 0;
	}
	set(const set& other)
	{
		head = new node<value>;
		head->is_nill = true;
		head->left = head;
		head->right = head;
		head->parent = head;
		_size = 0;
		operator=(other);
	}

	~set()
	{
		destroy_set(head->parent);
	}
	 

	set& operator=(const set& other) //TO DO IMPLEMENT  
	{
		this->destroy_set(this->head->parent);
		this->_size = other._size;
		
		return *this;
	}

	std::pair<iterator, bool> insert(const value& val)
	{

		iterator it;
		it.ptr = this->head;
		node<value>* nn;
		nn = new node<value>;
		nn->val = val;
		nn->left = head;
		nn->right = head;

		if (this->head->parent == this->head)
		{
			this->head->left = nn;
			this->head->right = nn;
			this->head->parent = nn;
			nn->parent = this->head;
			it.ptr = nn;
			++_size;
			return {it, true};

		}
		else
		{
			node<value>* ptr;
			ptr = this->head->parent;

			while (1)
			{
				if (ptr->val == nn->val)
				{
					return { it,false };
				}

				else if (ptr->val > nn->val)
				{
					if (ptr->left != this->head)
					{
						ptr = ptr->left;
					}
					else
					{
						ptr->left = nn;
						nn->parent = ptr;
						if (head->left->val > nn->val)
						{
							head->left = nn;
						}
						it.ptr = nn;
						++_size;
						return { it,true };
					}
				}
				else
				{
					if (ptr->right != this->head)
					{
						ptr = ptr->right;
					}
					else
					{
						ptr->right = nn;
						nn->parent = ptr;
						if (head->right->val < nn->val)
						{
							head->right = nn;
						}
						it.ptr = nn;
						++_size;
						return { it,true };
					}
				}
			}
		}

	}
	iterator begin()
	{
		iterator it;
		it.ptr = this->head->left;
		return it;
	}
	iterator end()
	{
		iterator it;
		it.ptr = this->head;
		return it;
	}
	reverse_iterator rend()
	{
		reverse_iterator it;
		it.ptr=this->head;
		return it;
	}
	reverse_iterator rbegin()
	{
		 
		reverse_iterator it;
		it.ptr = this->head->right;
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
	size_t size()const
	{
		return _size;
	}
	void clear()
	{
		destroy_set(this->head->parent);
		head->parent = head;
		head->left = head;
		head->right = head;
    }


	//erase function implementation


	iterator erase(iterator pos)
	{
		node<value>* del;
		del = pos.ptr;
		iterator it = this->head;
		if (del->parent == this->head)  // when the node to be delete is head node
		{
			if (del->left == del->right) // when there is only one node in set
			{
				this->head->parent = this->head;
				this->head->left = this->head;
				this->head->right =this->head;
				--_size;
				delete del;
				return it;
			}
			else if (del->left == this->head && del->right != this->head) //when root node has only right child 
			{
				node<value>* succ;
				--_size;
				succ = successor(del);
				head->left = succ;
				if (succ == del->right)
				{
					succ->parent = del->parent;
					this->head->parent = succ;
					it.ptr = succ;
					return it;
				}
				else
				{
					succ->parent->left = succ->right;
					if (succ->right != this->head)
					{
						succ->right->parent = succ->parent;
					}
					succ->parent = this->head;
					this->head->parent = succ;
					succ->right = del->right;
					succ->right->parent = succ;
					delete del;
					it.ptr = succ;
					return it;
				}
			}

			else if (del->left != this->head && del->right == this->head) //when root node has only left child 
			{
				iterator it;
				node<value> *_predecessor;
				_predecessor = predecessor_find(del);
				it.ptr = _predecessor;
				this->head->right = _predecessor;
				--_size;
				if (_predecessor == del->left)
				{
					_predecessor->parent = this->head;
					this->head->parent = _predecessor;
					delete del;
				}
				else
				{
					_predecessor->parent->right = _predecessor->left;
					if (_predecessor->left != this->head)
					{
						_predecessor->left->parent = _predecessor->parent;
					}
					_predecessor->parent = this->head;
					this->head->parent = _predecessor;
					_predecessor->left = del->left;
					_predecessor->left->parent = _predecessor;
					delete del;
				}
				return it;
			}  
			else //when root node has both child 
			{ 
				iterator it;
				node<value>* succ;
				--_size;
				succ = successor(del);
				it.ptr = succ;
				if (succ = del->right)
				{
					succ->left = del->left;
					succ->left->parent = succ;
					succ->parent = del->parent;
					this->head->parent = succ;
					delete del;
				}
				else
				{
					succ->parent->left = succ->right;
					if (succ->right != this->head)
					{
						succ->right->parent = succ->parent;
					}
					succ->parent = this->head;
					this->head->parent = succ;
					succ->left = del->left;
					succ->left->parent = succ;
					succ->right = del->right;
					succ->right->parent = succ;
					delete del;
				}
				return it;
			}
		} 
		else //if node to be deleted is not head node
		{
			if (del->right == del->left)
			{
				iterator it;
				it.ptr = this->head;
				if (del == del->parent->left)
				{
					del->parent->left = this->head;
					delete del;
				}
				else
				{
					del->parent->right = this->head;
					delete del;
				}
				--_size;
				return it;
			}
			else if (del->right == this->head && del->left != this->head)
			{
				node<value>* pre;
				pre = predecessor_find(del);
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
		}

	}
};