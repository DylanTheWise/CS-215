// Dylan Wise
// CS 215-001, Spring 2014
// Programming assignment 4
// 27 April, 2014
#include <iostream>
#include <vector>
#include <ctime>
#include "board.h"
#include "positionlist.h"
#include "position.h"
using namespace std;

// the constructor for the minesweeperboard, there is NO default constructor
MineSweeperBoard::MineSweeperBoard(int board_width, int board_height, int mine_count)
{
	// make width and height equal to those provided by user
	width = board_width;
	height = board_height;

	// create a 2-D array of bool** for revealed
	revealed = new bool*[height];
	for (int i = 0; i < height; i++)
	{
		revealed[i] = new bool[width];
	}
	// make all of the bool in the 2-D array false
	for (int i = 0; i < height; i++)
	{
		for (int j = 0; j < width; j++)
		{
			revealed[i][j] = false;
		}
	}

	// create a 2-D array of bool** for flagged
	flagged = new bool*[height];
	for (int i = 0; i < height; i++)
	{
		flagged[i] = new bool[width];
	}
	// make all of the bool in the 2-D array false
	for (int i = 0; i < height; i++)
	{
		for (int j = 0; j < width; j++)
		{
			flagged[i][j] = false;
		}
	}

	// create a 2-D array of bool** for mined
	mined = new bool*[height];
	for (int i = 0; i < height; i++)
	{
		mined[i] = new bool[width];
	}
	// make all of the bool in the 2-D array false
	for (int i = 0; i < height; i++)
	{
		for (int j = 0; j < width; j++)
		{
			mined[i][j] = false;
		}
	}

	// start a loop that is mine_count long
	for (int i = 0; i < mine_count; i++)
	{
		// create a while that will only exit if a bool is changed
		bool escape = false;
		while (escape == false)
		{
			// create a random int for height and width
			int randwidth = rand() % width;
			int randheight = rand() % height;

			// if the position is already falise make it true and exit the while
			// this ensures that we loop mine_count times and that there are no repeat mines
			if (mined[randheight][randwidth] == false)
			{
				mined[randheight][randwidth] = true;  //while loop, check if true
				escape = true;
			}
		}
	}
}

// deconstructor for the minesweeperboard
MineSweeperBoard::~MineSweeperBoard()
{
	// deletes all the new bools constructed to get rid of potential memory leaks
	for (int j = height; j < 0; j++)
		{
			delete[] mined[j];
			delete[] revealed[j];
			delete[] flagged[j];
		}
		delete[] mined;
		delete[] revealed;
		delete[] flagged;
}

// return user input width
int MineSweeperBoard::get_width() const
{
	return width;
}

// return user input height
int MineSweeperBoard::get_height() const
{
	return height;
}

// the method to recursively reveal the position of mines on the board
void MineSweeperBoard::reveal(Position p)
{
	// create adjacent neighbors for the current position
	PositionList neighbors = adjacent(p);
	// extract the exact values of the position
	int x = p.x();
	int y = p.y();
	
	// if already revealed exit the method, there is nothing to do
	if (revealed[y][x])
	{
		return;
	}

	// reveal and unflag the current position
	revealed[y][x] = true;
	flagged[y][x] = false;

	// if the position is mined return this position does not need extra work
	if (mined[y][x])
	{
		return;
	}

	// if adjacent mines and flags are equal this is where the magic happens
	if (adjacent_mines(p) == adjacent_flags(p))
	{
		// we loop the amount of neighbors size (adjacent points to the point given)
		for (int i = 0; i < neighbors.size(); i++)
		{
			// we take the first neighbor and if its not flagged call this function again with that position
			Position adj = neighbors.get(i);
			if (!flagged[adj.y()][adj.x()])
					reveal(adj);
		}
	}

	// use adjacent flags and mines and call
}

// flag an unflagged position and unflag a flagged position
bool MineSweeperBoard::flag(Position p)
{
	// extract the coordinates from the position
	int x = p.x();
	int y = p.y();
	// if flagged unflag and return the bool
	if (flagged[y][x])
	{
		flagged[y][x] = false;
		return flagged[y][x];
	}
	// if not flagged, flag and return the bool
	flagged[y][x] = true;
	return flagged[y][x];
}

// dictates what each of the points indicate
char MineSweeperBoard::appearance(Position p) const
{
	int x = p.x();
	int y = p.y();

	// flagged positions are slashes
	if (flagged[y][x]) {
		return '/';
	} else if (revealed[y][x]) {
		if (mined[y][x]) {
			// Boom!
			return '*';   // mines are asterisks
		} else {
			// At most 8 adjacent mines, so one digit.
			int adjmines = adjacent_mines(p);
			// Convert a number to a digit character.
			return '0' + adjmines;
		}
	} else {
		// Unrevealed, unflagged.
		return '.';
	}
}

// the display for the board
void MineSweeperBoard::display(ostream &out) const
{
	// creates the top line of the board, numbers higher than 10 need less spaces
	cout << "    |";
	for (int i = 0; i < width; i++)
	{
		if (i < 10)
		{
			cout << "  " << i;
		}
		if (i >= 10)
		{
			cout << " " << i;
		}
	}
	// second line of the board
	cout << endl;

	cout << "----+";

	// creates 3 en-dashes for each x coord
	for (int i = 0; i < width; i++)
	{
		cout << "---";
	}

	// the rest of the lines are dictated by the height, numbers higher than 10 need less space
	for (int i = 0; i < height; i++)
	{
		cout << endl;
		if (i < 10)
		{
			cout << " " << i << "  |";
		}

		if (i >= 10)
		{
			cout << " " << i << " |";
		}

		// calls for the correct character type based on its bool status for revealed, mined, flagged
		for (int k = 0; k < width; k++)
		{
			Position pos = Position(k, i);
			char boardpiece = appearance(pos);
			cout << "  " << boardpiece;
		}
	}
	cout << endl;
}

bool MineSweeperBoard::won() const
{
	// Check every square.  If we see a square that is mined but
	// not flagged, or unmined but not revealed, return false
	// immediately.  If we get to the end, every square is correct,
	// so the user won and we return true.
	for (int y = 0; y < height; y++) {
		for (int x = 0; x < width; x++) {
			if (mined[y][x] && !flagged[y][x]) {
				return false;
			} else if (!mined[y][x] && !revealed[y][x]) {
				return false;
			}
		}
	}
	return true;
}

// the bool that tells whether the user lost
bool MineSweeperBoard::lost() const
{
	for (int y = 0; y < height; y++)
	{
		for (int x = 0; x < width; x++)
		{
			// the mined and revealed for the same square are true you in trouble :o
			if (mined[y][x] && revealed[y][x])
				return true;
		}
	}
	// if not you live another day, phew.
	return false;
}

// this will only run if you are a quitter
void MineSweeperBoard::give_up()
{
	for (int y = 0; y < height; y++)
	{
		for (int x = 0; x < width; x++)
		{
			// all revealed bools are made true, this means the mined ones as well! So you lose. :(
			revealed [y][x] = true;
		}
	}
}

PositionList MineSweeperBoard::adjacent(Position p) const
{
	PositionList result;

	// Loop over the 3x3 block centered around p.
	for (int adj_y = p.y() - 1; adj_y <= p.y() + 1; adj_y++) {
		for (int adj_x = p.x() - 1; adj_x <= p.x() + 1; adj_x++) {
			// Make a position out of the new coordinates.
			Position adj(adj_x, adj_y);
			// Skip out-of-bounds squares
			if (!adj.in_bounds(width, height))
				continue;
			// Also skip the center.
			if (adj.x() == p.x() && adj.y() == p.y())
				continue;

			// If we get here, it's really adjacent, so add it to the list.
			result.push_front(adj);
		}
	}
	return result;
}

// counts adjacent mines and returns the number as an int
int MineSweeperBoard::adjacent_mines(Position p) const
{
	PositionList neighbors = adjacent(p);

	// Loop over the neighbors.
	int adjacent_count = 0;
	for (int i = 0; i < neighbors.size(); i++) {
		Position adj = neighbors.get(i);
		// If it's mined, increase the count.
		if (mined[adj.y()][adj.x()])
			adjacent_count++;
	}
	return adjacent_count;
}

// counts adjacent flags and returns the number as an int
int MineSweeperBoard::adjacent_flags(Position p) const
{
	PositionList neighbors = adjacent(p);

	// Loop over the neighbors
	int adjacent_count = 0;
	for (int i = 0; i < neighbors.size(); i++)
	{
		Position adj = neighbors.get(i);
		// If it's flagged, increase the count
		if (flagged[adj.y()][adj.x()])
			adjacent_count++;
	}
	return adjacent_count;
}