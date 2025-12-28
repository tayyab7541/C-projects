#pragma once
template <typename value>
struct node
{
	node<value>* left, * right, * parent;
	value val;
	bool is_nill;
	node()
	{
		is_nill = false;
	}
	friend std::ostream& operator>>(std::ostream& out, node<value> v);
};
template<typename value>
std::ostream& operator>>(std::ostream& out, node<value> v)
{
	out << "The require value = " << v.val << std::endl;
	return out;
}