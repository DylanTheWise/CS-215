// Dylan Wise
// CS 215-001, Spring 2014
// Programming assignment 4
// 27 April, 2014
#ifndef BOARD_H_INCLUDED
#define BOARD_H_INCLUDED

#include <iostream>
#include "position.h"
#include "positionlist.h"
using namespace std;

class MineSweeperBoard
{
public:

/* MineSweeperBoard(int board_width, int board_height, int mine_count);
 *
 * Description: 
 *   Constructor, makes 3 2-D arrays containing bools that initially are all false
 *   However mine_count number of mined bools are made true at random
 *
 * Inputs:
 *   Some ints for board width, board height and number of mines
 *
 * Outputs:
 *   No seen outputs, but does create 3 2-D arrays
 *
 * Side-effects:
 *   There is now a base for the game board
 *
 * Exceptions:
 *   None
 *
 * Notes:
 */

	// Initialize a board with a given width and height, containing the
	// given number of randomly-placed mines.  Nothing should be revealed
	// or flagged.  If there are more mines than spaces for them, fill
	// the entire board with mines.
	MineSweeperBoard(int board_width, int board_height, int mine_count);

/* ~MineSweeperBoard(); Deconstructs all the new bools created
 *
 * Description: 
 *   Destorys all dynamically alocated memory
 *
 * Inputs:
 *   None
 *
 * Outputs:
 *   None
 *
 * Side-effects:
 *   Memory is deleted
 *
 * Exceptions:
 *   None
 *
 * Notes:
 */

	// Clean up the board, freeing any dynamically allocated memory.
	~MineSweeperBoard();

/* int get_width() const;
 *
 * Description: 
 *   Returns the width
 *
 * Inputs:
 *   None
 *
 * Outputs:
 *   The width
 *
 * Side-effects:
 *   Current width is now accessible to all member functions
 *
 * Exceptions:
 *   None
 *
 * Notes:
 */

	// Get the size of the board.
	int get_width() const;

/* int get_height() const;
 *
 * Description: 
 *   Returns the height
 *
 * Inputs:
 *   None
 *
 * Outputs:
 *   The width
 *
 * Side-effects:
 *   Current height is now accessible to all member functions
 *
 * Exceptions:
 *   None
 *
 * Notes:
 */

	int get_height() const;

/* void reveal(Position p);
 *
 * Description: 
 *   Recursively reveals all of the nearby squares, stops at mines and flags
 *
 * Inputs:
 *   The position to start at
 *
 * Outputs:
 *   None
 *
 * Side-effects:
 *   Potentially many bool changes and the win/loss state of the game.
 *
 * Exceptions:
 *   None
 *
 * Notes:
 */

	// Reveal a square.
	// If this square wasn't already revealed, and if the number of
	// adjacent mines equals the number of adjacent flags, recursively
	// reveal all the surrounding squares that aren't flagged.
	void reveal(Position p);

/* bool flag(Position p);
 *
 * Description: 
 *   Changes the current position's bool value depending on its current value
 *
 * Inputs:
 *   The position for the flag to be created or destroyed
 *
 * Outputs:
 *   The new state of the bool
 *
 * Side-effects:
 *   A flag bool will be changed
 *
 * Exceptions:
 *   None
 *
 * Notes:
 */

	// Put a flag on a square, or remove a flag that is
	// already there.  Returns true if we placed a flag, false if
	// we removed one.
	bool flag(Position p);

/* char appearance(Position p) const;
 *
 * Description: 
 *   Dictates the appearance of what each bool will be (revealed(true/false) mined, flagged, etc)
 *
 * Inputs:
 *   The position you wish to determine the char for
 *
 * Outputs:
 *   The char that relects the state of the bools
 *
 * Side-effects:
 *   For ever one run potentially a char change
 *
 * Exceptions:
 *   None
 *
 * Notes:
 */

	// Return the appearance of the square (what will be
	// displayed to the player) as a single character.
	char appearance(Position p) const;

/* void display(ostream &out) const;
 *
 * Description: 
 *   This is the constuctor of the board's appearance to the user
 *
 * Inputs:
 *   None by the user
 *
 * Outputs:
 *   To the program, no
 *
 * Side-effects:
 *   The game board and all the current states for its coords are output to the console
 *
 * Exceptions:
 *   None
 *
 * Notes:
 */

	// Display the entire board to an output stream.  Prints
	// a header with the column numbers, and prints the row
	// number on each line.  For example,
	//     |  0  1  2  3  4
	//  ---+---------------
	//   0 |  1  /  .  .  .
	//   1 |  1  2  .  .  .
	//   2 |  0  1  .  .  .
	//   3 |  0  1  2  1  1
	//   4 |  0  0  0  0  0
	void display(ostream &out) const;

/* bool won() const;
 *
 * Description: 
 *   Checks to see of the user has won, by having all non mined coords revealved and
 *   all mined coords flagged
 *
 * Inputs:
 *   None
 *
 * Outputs:
 *   A bool saying whether the user has won or not
 *
 * Side-effects:
 *   The potential winning of the game
 *
 * Exceptions:
 *   None
 *
 * Notes:
 */

	// Returns true if the player won (every square with a mine
	// is flagged, and every cell without a mine is revealed).
	bool won() const;

/* bool lost() const;
 *
 * Description: 
 *   Checks to see of the user has lost, this done by seeing if a coord is both mined and revealed
 *
 * Inputs:
 *   None
 *
 * Outputs:
 *   A bool saying whether the user has lost or not
 *
 * Side-effects:
 *   The potential losing of the game
 *
 * Exceptions:
 *   None
 *
 * Notes:
 */

	// Returns true if the player lost (there is a revealed
	// mine).
	bool lost() const;

/* void give_up();
 *
 * Description: 
 *   If the user chooses to give up all coords are revealed, including mines, therefore the user loses
 *
 * Inputs:
 *   None
 *
 * Outputs:
 *   None
 *
 * Side-effects:
 *   The loss of the game.
 *
 * Exceptions:
 *   None
 *
 * Notes:
 */

	// Reveal everything (losing the game in the process)
	void give_up();
private:
	// Returns a list of all the positions adjacent to p.  If p
	// is in the middle of the board, it has eight neighbors,
	// but if it is on an edge or corner it will have fewer.
	PositionList adjacent(Position p) const;

	// Return the number of mines or flags adjacent to a square.
	int adjacent_mines(Position p) const;
	int adjacent_flags(Position p) const;

	// Size of the board.
	int width;
	int height;

	// Dynamically allocated 2D arrays indicating which squares are
	// revealed, which are mined, and which are flagged.
	bool **revealed;
	bool **mined;
	bool **flagged;
};
#endif
