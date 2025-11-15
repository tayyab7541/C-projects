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