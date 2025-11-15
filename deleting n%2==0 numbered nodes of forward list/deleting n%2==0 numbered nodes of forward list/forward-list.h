#pragma once
struct node
{
	int value;
	node* link;
};

class forward_list
{
private:
	node* head;
public:
	forward_list()
	{
		head = new node;
		head->link = head;
	}
	~forward_list()
	{
		delete head;
	}

	void push_front(int num)
	{
		node* nn;
		nn = new node;
		nn->value = num;
		nn->link = head->link;
		head->link = nn;
	}

	void pop_front()
	{
		node* temp;
		temp = head->link;
		head->link = temp->link;
		delete temp;
	}

	int front()
	{
		return head->link->value;
	}

	void removeeven()
	{
		node* temp1=nullptr;
		node* temp = head->link;
		int n = 1;
		while (temp != head)
		{
			if (n % 2 == 0)
			{
				temp1->link = temp->link;
				node* nn;
				nn = temp;
				temp = temp->link;
				delete nn;
				++n;
				continue;
			}
			temp1 = temp;
			temp = temp->link;
			++n;

		}
	}

	bool empty()
	{
		if (head->link == head)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
};