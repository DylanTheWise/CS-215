// Dylan Wise
// CS 215-001, Spring 2014
// Programming assignment 4
// 27 April, 2014
#include <cstdlib>
#include "positionlist.h"
#include "position.h"
#include "board.h"
using namespace std;

// Initialize a node with no next node and the given position.
Node::Node(Position p)
	: next(NULL), pos(p)
{}

// creates empty list
PositionList::PositionList()
{
	first = NULL;
}

// Initialize a copy of a list using the copy_nodes helper function.
PositionList::PositionList(const PositionList &original)
{
	first = copy_nodes(original.first);
}

PositionList &PositionList::operator=(const PositionList &other)
{
	if (this == &other)
		return *this;

	// TODO: free_nodes(first);
	while(!empty())
		pop_front();
	
	first = copy_nodes(other.first);

	return *this;
}

PositionList::~PositionList()
{
	// TODO: stub
	// remove top element until empty
	while(!empty())
		pop_front();
}

bool PositionList::empty() const
{
	// if top points to null is empty
	if (first == NULL)
	{
		return true;
	}
	// else return false
	return false;
}


int PositionList::size() const 
{
	// traverse the list and iterate each time you can, thi is the size
	int i = 0;
	for (Node *curr = first; curr != NULL; curr = curr->next) {
		i++;
	}
	return i;
}

Position PositionList::get(int index) const
{
	// TODO: stub
	Node *curr = first;
	for (int i = 0; i < index; i++)
	{
		if (curr == NULL)
			return Position(-1, -1);

		curr = curr->next;
	}
	if (curr == NULL)
	{
		return Position(-1, -1);
	}

	// return current position
	return curr->pos;
}

void PositionList::push_front(Position pos)
{
	// TODO: stub

	// move pointers around to create a new lead
	Node *to_insert = new Node(pos);
	to_insert->next = first;
	first = to_insert;
}

void PositionList::pop_front()
{
	// TODO: stub
	// make the lead pointer point towards the second element
	Node *to_del = first;
	first = to_del->next;
	delete to_del;
}

Node *PositionList::copy_nodes(const Node *in) const
{
	// TODO: stub
	// if null return null
	if (in == NULL)
		return NULL;

	// else copy the node and return it
	Node *copy = new Node(in->pos);
	copy->next = copy_nodes(in->next);

	return copy;
}
