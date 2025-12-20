#pragma once
#include"pair.h"
template <typename t1, typename t2>
struct  node
{
	node* left, * right, * parent;
	std::pair<t1, t2> data;
	int height;
	bool is_nill;
	node()
	{
		is_nill = false;
		height = 0;
	}
};



template <typename t1, typename t2>
class map
{
	node<t1, t2>* head;
	int _size;


	void clear_recursive(node<t1, t2>* ptr)  //deletes all the nodes in map
	{
		if (ptr != head)
		{
			clear_recursive(ptr->left);
			clear_recursive(ptr->right);
			delete ptr;
			--_size;
		}
	}


	int max(int a, int b) //function that returns max of two numbers 
	{
		if (a > b)
		{
			return a;
		}
		else
		{
			return b;
		}
	}

	void rotate_right(node<t1, t2>* ptr) //as name suggests rotates a node to right
	{
		node<t1, t2>* temp, * lc;
		lc = ptr->left;
		temp = ptr;

		if (ptr->parent == head)
		{
			ptr->parent->parent = ptr->left;

		}
		else
		{
			if (ptr == ptr->parent->left)
			{
				ptr->parent->left = lc;
			}
			else
			{
				ptr->parent->right = lc;
			}
		}
		ptr->left = lc->right;
		if (lc->right != head)
		{
			lc->right->parent = ptr;
		}
		lc->parent = ptr->parent;
		lc->right = ptr;
		ptr->parent = lc;
		while (temp != head)
		{
			int n = max(temp->left->height, temp->right->height);
			temp->height = n + 1;
			temp = temp->parent;


		}
	}



	void rotate_left(node<t1, t2>* ptr)
	{
		node<t1, t2>* temp, * rc;
		temp = ptr;
		rc = ptr->right;
		if (ptr->parent == head)
		{
			head->parent = rc;
			rc->parent = ptr->parent;

		}
		else
		{
			if (ptr->parent->left == ptr)
			{
				ptr->parent->left = ptr->right;
				rc->parent = ptr->parent;
			}
			else
			{
				ptr->parent->right = ptr->right;
				rc->parent = ptr->parent;
			}
		}
		node<t1, t2>* r;
		r = rc->left;
		rc->left = ptr;
		ptr->parent = rc;
		ptr->right = r;
		if (r != head)
		{
			r->parent = ptr;
		}
		temp = ptr;
		while (temp != head)
		{
			int n = max(temp->left->height, temp->right->height);
			temp->height = n + 1;
			temp = temp->parent;
		}

	}



public:


	map()  //constructure
	{
		head = new node<t1, t2>;
		head->parent = head;
		head->left = head;
		head->right = head;
		head->is_nill = true;
		_size = 0;
	}

	map(const map& other) //copy constructure
	{
		this->head = new node<t1, t2>;
		head->parent = head;
		head->left = head;
		head->right = head;
		head->is_nill = true;
		_size = 0;
		operator=(other);
	}

	class iterator   //iterator class 
	{
		node<t1, t2>* ptr;
		friend class map;

	public:

		std::pair<const t1, t2>& operator*()
		{
			return ptr->data;
		}

		bool operator==(const iterator& compare)
		{
			if (compare.ptr == this->ptr)
			{
				return true;
			}
			return false;
		}
		bool operator!=(const iterator& compare)
		{
			if (compare.ptr != this->ptr)
			{
				return true;
			}
			return false;
		}

		std::pair<t1, t2>* operator->()
		{
			return  &(ptr->data);
		}

		bool operator != (const iterator& it)
		{
			if (this->ptr != it.ptr)
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
			else if (ptr == ptr->parent->left)
			{
				ptr = ptr->parent;
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
	};

	//end of iterator class 

	iterator begin()const  //it gives iterator of node containing smallest value
	{
		iterator it;
		it.ptr = head->left;
		return it;
	}

	iterator end()const //it gives iterator that contains link of head node
	{
		iterator it;
		it.ptr = head;
		return it;
	}


	pair<iterator, bool> insert(std::pair<t1, t2> p)
	{
		node<t1, t2>* nn, * temp;
		pair<iterator, bool> return_pair;
		return_pair.first.ptr = head;
		nn = new node<t1, t2>;
		nn->data.first = p.first;
		nn->data.second = p.second;
		nn->left = head;
		nn->right = head;
		if (head->parent == head)
		{
			++_size;
			nn->parent = head;
			head->parent = nn;
			head->left = nn;
			head->right = nn;
			return_pair.first.ptr = nn;
			return_pair.second = true;

		}
		else
		{
			++_size;
			temp = head->parent;
			while (1)
			{
				if (temp->data.first == nn->data.first)
				{
					return_pair.first.ptr = nn;
					return_pair.second = false;
					return return_pair;

				}
				else if (temp->data.first > nn->data.first)
				{
					if (temp->left != head)
					{
						temp = temp->left;

					}
					else
					{
						temp->left = nn;
						nn->parent = temp;
						if (head->left->data.first > nn->data.first)
						{
							head->left = nn;

						}
						return_pair.first.ptr = nn;
						return_pair.second = true;
						break;
					}
				}
				else
				{
					if (temp->right != head)
					{
						temp = temp->right;
					}
					else
					{
						temp->right = nn;
						nn->parent = temp;
						if (head->right->data.first < nn->data.first)
						{
							head->right = nn;
						}
						return_pair.first.ptr = nn;
						return_pair.second = true;
						break;
					}
				}
			}
		}
		temp = nn;
		while (temp != head)
		{
			int n = max(temp->left->height, temp->right->height);
			temp->height = n + 1;
			temp = temp->parent;
		}
		temp = nn;
		while (temp != head)
		{
			int bf = temp->left->height - temp->right->height;
			if (bf == 2 || bf == -2)
			{
				if (temp->left->height > temp->right->height)
				{
					if (temp->left->left->height < temp->left->right->height)
					{
						rotate_left(temp->left);
						rotate_right(temp);
					}
					else
					{
						rotate_right(temp);
					}
				}
				else
				{
					if (temp->right->left->height > temp->right->right->height)
					{
						rotate_right(temp->right);
						rotate_left(temp);
					}
					else
					{
						rotate_left(temp);
					}
				}
			}
			temp = temp->parent;
		}

		return return_pair;
	}



	void clear()
	{
		clear_recursive(head->parent); //calling private function

		head->parent = head; //explicity setting pointer of dummy head
		head->right = head;
		head->left = head;
	}


	int size()const  //function that gives size of map
	{
		return _size;
	}


	bool empty()const //function to tell if map is empty or not
	{
		if (head->parent == head)
		{
			return true;
		}
		else
		{
			return false;
		}
	}


	iterator erase(const iterator& pos)   //function that deletes only one node
	{
		node<t1, t2>* del, * balance_factor_cheking;
		iterator it;
		it.ptr = head;
		del = pos.ptr;
		balance_factor_cheking = del->parent;
		if (del == head)
		{
			throw("Dummy should not be deleted \n");
		}
		else if (del->parent != head)  // removing nodes except root node 
		{
			if (del->left == del->right)   //removing leaf node 
			{
				if (del == del->parent->left)
				{
					del->parent->left = head;
					if (head->left == del)
					{
						head->left = del->parent;
					}

				}
				else
				{
					del->parent->right = head;
					if (head->left == del)
					{
						head->left = del->parent;
					}
				}
				node < t1, t2>* temp;
				temp = del->parent;
				while (temp != head)
				{
					int n = max(temp->left->height, temp->right->height);
					temp->height = n + 1;
					temp = temp->parent;
				}
				delete del;


			}
			else if (del->left != head && del->right == head) //removing node having only left child
			{
				node<t1, t2>* _var1;

				if (del == del->parent->left)
				{
					del->parent->left = del->left;

				}
				else
				{
					del->parent->right = del->left;
				}
				del->left->parent = del->parent;
				--_size;
				_var1 = del->left;
				balance_factor_cheking = del->parent;

				it.ptr = del->left;
				delete del;
				while (_var1 != head)
				{
					int n = max(_var1->left->height, _var1->right->height);
					_var1->height = n + 1;
					_var1 = _var1->parent;
				}
			}
			else if (del->left == head && del->right != head) //removing node having only right child
			{
				node<t1, t2>* _var;

				if (del == del->parent->left)
				{
					del->parent->left = del->right;

				}
				else
				{
					del->parent->right = del->right;
				}
				del->right->parent = del->parent;
				--_size;
				_var = del->right;
				it.ptr = del->right;
				balance_factor_cheking = del->parent;

				delete del;
				while (_var != head)
				{
					int n = max(_var->left->height, _var->right->height);
					_var->height = n + 1;
					_var = _var->parent;
				}
			}
			else  //removing node having two child 
			{
				node<t1, t2>* t, * rc, * pc;
				t = del->right;
				while (t->left != head)
				{
					t = t->left;

				}
				if (t == del->right)
				{
					t->left = del->left;
					t->left->parent = t;
					t->parent = del->parent;
					if (del == del->parent->left)
					{
						del->parent->left = t;
					}
					else
					{
						del->parent->right = t;
					}
					balance_factor_cheking = t;
					delete del;
					--_size;
					while (t != head)
					{
						int n = max(t->left->height, t->right->height);
						t->height = n + 1;
						t = t->parent;
					}


				}
				else
				{
					rc = t->right;
					pc = t->parent;
					if (t == pc->left)
					{
						pc->left = rc;
					}
					else
					{
						pc->right = rc;
					}
					if (rc != head)
					{
						rc->parent = pc;
					}
					t->right = del->right;
					t->right->parent = t;
					t->left = del->left;
					t->left->parent = t;
					t->parent = del->parent;
					if (del == del->parent->left)
					{
						del->parent->left = t;
					}
					else
					{
						del->parent->right = t;
					}
					delete del;
					--_size;
					t = pc;
					balance_factor_cheking = pc;
					while (t != head)
					{
						int n = max(t->left->height, t->right->height);
						t->height = n + 1;
						t = t->parent;
					}
				}

			}
		}
		else
		{
			if (del->left == del->right) //deleting root when it has no child node
			{
				del->parent->parent = head;
				head->left = head;
				head->right = head;
				delete del;
				--_size;
			}
			else if (del->left != head && del->right == head)//deleting root when it has only left child
			{
				node<t1, t2>* temp, * h_assign;
				temp = del->left;
				while (temp->right != head)
				{
					temp = temp->right;
				}

				if (temp == del->left)
				{
					head->right = temp;
					head->parent = temp;
					temp->parent = head;
					delete del;
					--_size;
				}
				else
				{
					node<t1, t2>* lc;
					lc = temp->left;
					h_assign = temp->parent;
					if (temp == temp->parent->right)
					{
						temp->parent->right = lc;
						if (lc != head)
						{
							lc->parent = temp->parent;
						}
					}

					temp->parent = head;
					head->parent = temp;
					temp->left = del->left;
					temp->left->parent = temp;
					delete del;
					while (h_assign != head)
					{
						int n = max(h_assign->left->height, h_assign->right->height);
						h_assign->height = n + 1;
						h_assign = h_assign->parent;
					}
				}
				it.ptr = temp;
			}
			else if (del->right != head && del->left == head)  //deleting root node if has only right child
			{
				node<t1, t2>* temp, * h_assign;;
				temp = del->right;
				while (temp->left != head)
				{
					temp = temp->left;
				}
				if (temp == del->right)
				{
					temp->parent = head;
					head->parent = temp;
					head->left = temp;
					delete del;
					--_size;
				}
				else
				{
					node<t1, t2>* rc, * p;
					rc = temp->right;
					p = temp->parent;
					p->left = rc;
					if (rc != head)
					{
						rc->parent = p;
					}

					temp->right = del->right;
					temp->right->parent = temp;
					temp->parent = head;
					head->parent = temp;
					head->left = temp;
					delete del;
					--_size;

					h_assign = p;
					while (h_assign != head)
					{
						int n = max(h_assign->left->height, h_assign->right->height);
						h_assign->height = n + 1;
						h_assign = h_assign->parent;
					}
				}

				it.ptr = temp;
			}
			else
			{
				node<t1, t2>* temp;
				temp = del->right;
				while (temp->left != head)
				{
					temp = temp->left;

				}
				if (temp == del->right)
				{
					temp->left = del->left;
					temp->left->parent = temp;
					temp->parent = head;
					head->parent = temp;
					balance_factor_cheking = temp;
					while (temp != head)
					{
						int n = max(temp->left->height, temp->right->height);
						temp->height = n + 1;
						temp = temp->parent;
					}
					delete del;
					--_size;
				}
				else
				{
					node<t1, t2>* rc, * p;
					rc = temp->right;
					p = temp->parent;
					p->left = rc;
					balance_factor_cheking = p;

					if (rc != head)
					{
						rc->parent = p;
					}
					temp->left = del->left;
					temp->left->parent = temp;
					temp->right = del->right;
					temp->right->parent = temp;
					temp->parent = del->parent;
					head->parent = temp;

					delete del;
					--_size;
					while (p != head)
					{
						int n = max(p->left->height, p->right->height);
						p->height = n + 1;
						p = p->parent;
					}
				}
				it.ptr = temp;
			}


		}


		while (balance_factor_cheking != head)
		{
			int bf = balance_factor_cheking->left->height - balance_factor_cheking->right->height;
			if (bf == 2 || bf == -2)
			{
				if (balance_factor_cheking->left->height > balance_factor_cheking->right->height)
				{
					if (balance_factor_cheking->left->left->height < balance_factor_cheking->left->right->height)
					{
						rotate_left(balance_factor_cheking->left);
						rotate_right(balance_factor_cheking);
					}
					else
					{
						rotate_right(balance_factor_cheking);
					}
				}
				else
				{
					if (balance_factor_cheking->right->left->height > balance_factor_cheking->right->right->height)
					{
						rotate_right(balance_factor_cheking->right);
						rotate_left(balance_factor_cheking);
					}
					else
					{
						rotate_left(balance_factor_cheking);
					}
				}
			}
			balance_factor_cheking = balance_factor_cheking->parent;
		}

		return it;
	}

	t2& at(const t1& key)
	{
		node<t1, t2>* temp;
		temp = head->parent;
		while (temp != head)
		{
			if (key == temp->data.first)
			{
				return temp->data.second;
			}
			else if (key > temp->data.first)
			{
				temp = temp->right;
			}
			else
			{
				temp = temp->left;
			}

		}

		throw("out of range");
	}


	t2& operator[](const t1& key)
	{

		node<t1, t2>* temp;
		temp = head->parent;
		while (temp != head)
		{
			if (key == temp->data.first)
			{
				return temp->data.second;
			}
			else if (key > temp->data.first)
			{
				temp = temp->right;
			}
			else
			{
				temp = temp->left;
			}

		}

		pair<iterator, bool> p;
		p = insert({ key,t2() });
		return p.first.ptr->data.second;
	}

	int count(const t1& key)
	{
		node<t1, t2>* temp;
		temp = head->parent;
		while (temp != head)
		{
			if (key == temp->data.first)
			{
				return 1;
			}
			else if (key > temp->data.first)
			{
				temp = temp->right;
			}
			else
			{
				temp = temp->left;
			}

		}

		return 0;
	}

	iterator find(const t1& key)
	{
		iterator it;
		it.ptr = head;
		node<t1, t2>* temp;
		temp = head->parent;
		while (temp != head)
		{
			if (key == temp->data.first)
			{
				it.ptr = temp;
				return it;
			}
			else if (key > temp->data.first)
			{
				temp = temp->right;
			}
			else
			{
				temp = temp->left;
			}

		}

		return it;
	}

	bool contains(const t1& key)
	{
		node<t1, t2>* temp;
		temp = head->parent;
		while (temp != head)
		{
			if (key == temp->data.first)
			{
				return true;
			}
			else if (key > temp->data.first)
			{
				temp = temp->right;
			}
			else
			{
				temp = temp->left;
			}

		}
		return false;
	}

	//destructure is here 
	~map()
	{
		clear();
	}

	map& operator=(const map& other)
	{
		node<t1, t2>* temp;
		temp = other.head->left;
		this->~map();
		iterator it;
		it.ptr = temp;
		while (it != other.end())
		{
			this->insert({ it.ptr->data.first, it.ptr->data.second });
			++it;
		}

		return *this;
	}
};
