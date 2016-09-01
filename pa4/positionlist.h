// Dylan Wise
// CS 215-001, Spring 2014
// Programming assignment 4
// 27 April, 2014
#ifndef POSITIONLIST_H_INCLUDED
#define POSITIONLIST_H_INCLUDED

#include "position.h"

// Class representing a node in a PostionList.  This class
// is intended to be used only by PositionList.
class Node
{
public:

/* Node(Position p);
 *
 * Description: 
 *   Creates a node with no next node at p
 *
 * Inputs:
 *   The position p
 *
 * Outputs:
 *   None
 *
 * Side-effects:
 *   The creation of a node object using position
 *
 * Exceptions:
 *   None
 *
 * Notes:
 */

	// Create a new node with no next node and position p.
	Node(Position p);
private:
	// A pointer to the next node in the linked list.
	Node *next;

	// The Position being stored in this node.
	Position pos;

	// The Node class is intended for the internal use of
	// PositionList, so give that class access to our
	// private data members.
	friend class PositionList;
};

// Class representing a position on a two-dimensional board.
// Stores an x and y coordinate, with methods to return and
// set each coordinate, and a method to test whether the
// position falls within a given width and height.
class PositionList
{
public:

/* PositionList();
 *
 * Description: 
 *   Creates an empty position list object. First pointer points towards NULL

 * Inputs:
 *   None
 *
 * Outputs:
 *   None
 *
 * Side-effects:
 *   PositionList object is created
 *
 * Exceptions:
 *   None
 *
 * Notes:
 */

	// Initialize an empty list.
	PositionList();

/* PositionList(const PositionList &original);
 *
 * Description: 
 *   Basically creates a deep copy of another PositionList
 *
 * Inputs:
 *   A PositionList
 *
 * Outputs:
 *   A copy of that PositionList
 *
 * Side-effects:
 *   Another PositionList is created
 *
 * Exceptions:
 *   None
 *
 * Notes:
 */

	// Initialize a list as a deep copy of another.
	PositionList(const PositionList &original);

/* ~PositionList();
 *
 * Description: 
 *   Frees all allocated memory for positionlist 
 *
 * Inputs:
 *   None
 *
 * Outputs:
 *   None
 *
 * Side-effects:
 *   Memory is freed
 *
 * Exceptions:
 *   None
 *
 * Notes:
 */

	// Clean up this list by freeing all its nodes.
	~PositionList();

/* PositionList &operator=(const PositionList &other);
 *
 * Description: 
 *   Creates a deep copy of a list into the *this one
 *
 * Inputs:
 *   A PositionList
 *
 * Outputs:
 *   *this PositionList
 *
 * Side-effects:
 *   Deep copy is created to replace PositionList
 *
 * Exceptions:
 *   None
 *
 * Notes:
 */

	// Deep copy the contents of another list into this one.  Replace the old
	// contents of this list, freeing those nodes.  Returns the implicit
	// parameter by reference (return *this;)
	//
	// This method implements assignment:   poslist = otherposlist;
	PositionList &operator=(const PositionList &other);

/* bool empty() const;
 *
 * Description: 
 *   Detects if PositionList is empty
 *
 * Inputs:
 *   None
 *
 * Outputs:
 *   A bool indicating is PositionList is empty
 *
 * Side-effects:
 *   None
 *
 * Exceptions:
 *   None
 *
 * Notes:
 */

	// Returns true if this list is empty.
	bool empty() const;

/* int size() const;
 *
 * Description: 
 *   Detects the current size of the PositionList
 *
 * Inputs:
 *   None
 *
 * Outputs:
 *   An int indicating the size of the PositionList
 *
 * Side-effects:
 *   None
 *
 * Exceptions:
 *   None
 *
 * Notes:
 */

	// Calculate the size of the list (number of nodes).
	int size() const;
	
/* Position get(int index) const;
 *
 * Description: 
 *   Returns the position of the index given. If out of bounds (-1, -1) is returned
 *
 * Inputs:
 *   An index for the Position
 *
 * Outputs:
 *   A Position
 *
 * Side-effects:
 *   None
 *
 * Exceptions:
 *   None
 *
 * Notes:
 */

	// Find and return the index-th element in the list, counting from 0.
	// If the index was out of bounds, return the Position (-1, -1).
	Position get(int index) const;

/* void push_front(Position pos);
 *
 * Description: 
 *   Adds a new position object to the front of the list
 *
 * Inputs:
 *   A Position
 *
 * Outputs:
 *   None
 *
 * Side-effects:
 *   Pointers changed in order to add a new Postition to the front of the PositionList
 *
 * Exceptions:
 *   None
 *
 * Notes:
 */

	// Add a new Position object to the beginning of the list.
	void push_front(Position pos);

/* void pop_front();
 *
 * Description: 
 *   Removed the first element of the list
 *
 * Inputs:
 *   None
 *
 * Outputs:
 *   None
 *
 * Side-effects:
 *   A new first element for the list, as well as the size being one smaller
 *
 * Exceptions:
 *   None
 *
 * Notes:
 */

	// Remove the first element, freeing its node.
	void pop_front();

private:
	// Recursively make a deep copy of a node and all the nodes that follow.
	// Returns the copy.  The input may be NULL, in which case nothing is
	// copied and the function returns NULL.
	// This function will be used by the copy constructor and by operator= .
	Node *copy_nodes(const Node *in) const;

	Node *first;
};

#endif
