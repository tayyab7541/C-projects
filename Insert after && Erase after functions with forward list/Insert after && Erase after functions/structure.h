#pragma once
template <typename t>
struct node
{
	t value;
	node* link;

	template <typename t>
	friend std::ostream& operator<< (std::ostream& o1, const node<t>& n);


};

template <typename t>
std::ostream& operator<<(std::ostream& o1, const node<t>& n)
{
	o1 << n.value << "\n";
	return o1;
}