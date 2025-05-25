#include "bilist.h"

BiList::BiList()
{
	front = nullptr;
}

BiList::~BiList()
{
	clear();
}

void BiList::clear()
{
	front = front->clear(front);
}

BiNode* BiList::get_back()
{
	return front->get_back(front);
}

int BiList::size()
{
	return front->size(front);
}

void BiList::push_back(int x)
{
	if (front)
	{
		front = front->push_back(front, x);
	}
	else
	{
		front = new BiNode(x);
	}
}

void BiList::push_front(int x)
{
	if (front)
	{
		front = front->push_front(front, x);
	}
	else
	{
		front = new BiNode(x);
	}
}

void BiList::insert(int x, BiNode* node)
{
	if (node)
	{
		front = front->insert(front, x, node);
	}
}

void BiList::insert(BiNode* node, int x)
{
	if (node)
	{
		front = front->insert(front, node, x);
	}
}

void BiList::remove(BiNode* node)
{
	if (node)
	{
		front = front->remove(front, node);
	}
}

void BiList::forward_view()
{
	if (front)
	{
		front->forward_view(front);
	}
}

void BiList::reverse_view()
{
	if (front)
	{
		front->reverse_view(front);
	}
}

BiNode* BiList::find(int key)
{
	return front->find(front, key);
}

BiNode* BiList::get(int index)
{
	return front->get(front, index);
}

int& BiList::operator[](size_t index)
{
	return front->get(front, index)->data;
}

void BiList::splice_in(BiList& List, int index)
{
	if (front && List.front && List.front->get(front,index))
	{
		front = front->splice_in(front, List.front, index);
		List.front = nullptr;
		List.clear();
	}
}

void BiList::splice_out(BiList& List, int index1, int index2)
{
	if (front && List.front)
	{
		front = front->splice_out(front, List.front, index1, index2);
	}
}

void BiList::sort()
{
	if (front)
	{
		front = front->sort(front);
	}
}
