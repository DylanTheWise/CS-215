// Dylan Wise
// CS 215-001, Spring 2014
// Programming assignment 4
// 27 April, 2014
#include <iostream>
#include <cstdlib>
#include <string>
#include <vector>
#include <istream>
#include <ctime>
#include "board.h"
#include "position.h"
#include "positionlist.h"
using namespace std;

/* pause_215() - Wait for the user to press ENTER.
 *
 * Description: 
 *   Optionally read and discard the remainder of the user's last
 *   line of input.  Then, prompt the user to press ENTER, then
 *   read and discard another line of input.
 *
 * Inputs:
 *   bool have_newline:
 *     True if the user has already entered a newline that the
 *     program has not yet read.  If true, this function first
 *     discards remaining input up to and including that newline.
 *
 * Outputs:
 *   No return value.
 *
 * Side-effects:
 *   Prints a prompt to standard output.  Reads one or two lines
 *   from standard input.
 *
 * Exceptions:
 *   None.
 *
 * Notes:
 *   This function is intended to be used at the end of a program,
 *   just before returning from main().  Reading another line of
 *   input prevents the console window from closing immediately.
 *
 *   In general, have_newline should be true if the last user input
 *   from cin used the extraction operator (>>), and false if there
 *   has been no user input or if the last input used getline().
 */

void pause_215(bool have_newline);

/* int main() - Game time!
 *
 * Description: 
 *   Main first initializes all the the big variables you will require in the function as a whole
 *   Main then asks the user what the size of the game board should be, the size should be between 5 and 20
 *   Once the size is determined the user is asked how many mines they want in their board (the difficulty basically)
 *   the user can decide between 1 and whatever the area is for the board (Don't know why they would want to...)
 *   After the mines are placed the game begins and the user can reveal, flag or give up. Eventually the user will
 *   either win or lose, the appropriate message is shown and user is shown how long the game took

 * Inputs:
 *   Several, the user must decide the size of the board, how many mines to place.
 *   Then the user gets to either reveal, flag or quit
 *
 * Outputs:
 *   The game board, the many messages prompting for user input
 *
 * Side-effects:
 *   The side effect is the game is played
 *
 * Exceptions:
 *   All exceptions are handled in code. The only exceptions that can occur are when the user inputs invalid
 *   things when prompted
 *
 * Notes:
 */

int main()
{
	// Generate a random seed and start the game timer
	srand(static_cast<unsigned int>(time(NULL)));
	clock_t begin = clock();

	// TODO: Ask for the board size (between 5 and 20 in each direction)
	// and the number of mines.

	// Initialize many of the variables that are needed for the program ahead of time
	bool gave_up = false;
	int x;
	int y;
	int mine_count;
	string input_line;

	// introduce game name
	cout << "Welcome to MineSweeper 215" << endl;
	cout << endl;

	// more variable initization, including escape bools and error counts
	vector<int> num_list;
	bool escape0 = false;
	bool escape1 = false;
	int error_count = 0;

	while(escape0 == false)
	{
		// this first layer asks the user to input the size of the gameboard
		int uinput;
		escape1 = false;
		cout << "How large should the board be (width, height)? ";
	
		while(escape1 == false)
		{
			//second layer takes in the numbers input by the user
			cin >> uinput;
			error_count = 0;
			// if the input is lower than five tell the user, clear the buffer and iterate the error count
			if (uinput < 5)
			{
				cin.clear();
				string clear;
				getline(cin, clear);
				cout << "Please enter a size larger than 5 "<< endl;
				error_count += 1;
			}

			// if the input is above twenty tell tell the user and do the same as described above
			if (uinput > 20)
			{
				cin.clear();
				string clear;
				getline(cin, clear);
				cout << "Please enter a size smaller than 20 " << endl;
				error_count += 1;
			}

			// if a non-numeric input is given clear the buffer, tell the user the correct way to enter and iterate error count
			if (cin.fail())
			{
				cin.clear();
				string clear;
				getline(cin, clear);
				cout << "Please enter two numbers seperated by a space " << endl;
				error_count += 1;
			}

			// if there is one error exit this loop back to the top layer which asks for input again
			if (error_count > 0)
			{
				escape1 = true;
			}

			// however if no error occurs push_back number(s) to the list
			if (error_count == 0)
			{
				num_list.push_back(uinput);
			}

			int size = num_list.size();
			// if the size is 2 and there were no errors we know we have two numbers that will work
			if (size == 2)
			{
				escape0 = true;
				escape1 = true;
				cout << endl;
			}

		}
	}

	// assign the numbers gained from the user to their respective coordinates
	x = num_list[0];
	y = num_list[1];

	int board_area = x*y;

	// initialize error handling for mines
	bool escape2 = false;
	int error_count2 = 0;
	while (escape2 == false)
	{
		// ask the user how many mines they want and show them the max area
		error_count2 = 0;
		cout << "How many mines to place (maximum " << board_area << ")? ";
		cin >> mine_count;
		cout << endl;

		// if minecount is larger than the board area and error is thrown
		if (mine_count > board_area)
		{
			cin.clear();
			string clear;
			getline(cin, clear);
			cout << "Please enter a value smaller than " << board_area << endl;
			cout << endl;
			error_count2 += 1;

		}

		// if minecount is 0 or negative then an error is thrown
		if (mine_count <= 0)
		{
			cin.clear();
			string clear;
			getline(cin, clear);
			cout << "Please enter a value larger than 0 " << endl;
			cout << endl;
			error_count2 += 1;

		}

		// if a non-numeric input is given an error is thrown
		if (cin.fail())
		{
			cin.clear();
			string clear;
			getline(cin, clear);
			cout << "Please enter a number " << endl;
			cout << endl;
			error_count2 += 1;
		}

		// if a correct value is given that does not throw an error the while loop is exited
		if (error_count2 == 0)
		{
			escape2 = true;
		}

	}
	// Create a board of that size.
	// TODO: change these numbers.
	MineSweeperBoard board(x, y, mine_count);
	board.display(cout);
	while (!board.lost() && !board.won())
	{
		
		// TODO: Ask the user to [R]eveal, [F]lag, or [G]ive up.
		// The first two commands also require a Position, so
		// you may need to ask for x and y coordinates as well.

		string uinput;
		int exit = 0;
			// an exit int that can only trip when the user decides to quit
		while(exit == 0)
		{
			// a bool that will stay true if no sucessful input is given
			bool error_bool = true;
			cin.clear();
			string clear;
			getline(cin, clear);
			cout << endl;
			cout << "[R]eveal, [F]lag, or [G]ive up? ";

			// only disadvantage of getline is if whitespace is included after it is an "invalid input"
			getline(cin, uinput);

			if (uinput == "R" || uinput == "r")
			{
				// initialize error bools, error count, and a list to hold the number for the coords
				error_count = 0;
				int number_pass = 0;
				vector<int> num_list;
				bool error_reveal_0 = false;
				bool error_reveal_1 = true;
				while (error_reveal_0 == false)
				{
					// initialize input from the user and reset error bool for lower half of input (for errors)
					int uinput2;
					error_reveal_1 = false;
					cout << "What position (x, y)? ";
	
					while(error_reveal_1 == false)
					{
						cin >> uinput2;

						if (cin.fail())
						{
							// failure condition, tells the user what to input and interates error count
							cin.clear();
							string clear;
							getline(cin, clear);
							cout << "Please enter two numbers seperated by a space " << endl;
							error_count += 1;
						}

						// if the number is within range and this is the first pass through pushback on the list
						if (number_pass == 0 && uinput2 < x)
						{
							num_list.push_back(uinput2);
						}

						// if first pass and there is an invalid size inform the user
						if (number_pass == 0 && uinput2 >= x)
						{
							cout << "Please enter an X value within the board range " << endl;
							error_count += 1;
						}

						// if on the second pass and the int is valid push it into the list
						if (number_pass == 1 && uinput2 < y)
						{
							num_list.push_back(uinput2);
						}

						// if on the second pass and the int is invalid throw an error
						if (number_pass == 1 && uinput2 >= y)
						{
							cout << "Please enter a Y value within the board range " << endl;
							error_count += 1;
						}

						// take the current size of the list
						int size = num_list.size();

						// if the size is zero we know that we did not make a successful pass
						if (size == 0)
						{
							number_pass = 0;
						}

						// if the size is 1 we know we have make one successful pass
						if (size == 1)
						{
							number_pass = 1;
						}

						// if the size is two we have both the numbers we need and attempt to exit
						if (size == 2)
						{
							error_reveal_0 = true;
							error_reveal_1 = true;
						}

						// if there was an error repeat the entire process from the user input again
						if (error_count > 0)
						{
							error_reveal_1 = true;
						}

					}

				}
				// create the reveal x and y, make a position from them, reveal them and then display on the board
				cout << endl;
				int x_r = num_list[0];
				int y_r = num_list[1];
				Position pos = Position(x_r, y_r);
				board.reveal(pos);
				board.display(cout);
				cout << endl;
				error_bool = false;
				exit = 1;

			}

			// Flag is the exact same process as reveal except at the end we call for flag as opposed to reveal 
			if (uinput == "F" || uinput == "f")
			{
				{
				// initialize error bools, error count, and a list to hold the number for the coords
				error_count = 0;
				int number_pass = 0;
				vector<int> num_list;
				bool error_flag_0 = false;
				bool error_flag_1 = true;
				while (error_flag_0 == false)
				{
					// initialize input from the user and reset error bool for lower half of input (for errors)
					int uinput2;
					error_flag_1 = false;
					cout << "What position (x, y)? ";
	
					while(error_flag_1 == false)
					{
						cin >> uinput2;

						if (cin.fail())
						{
							// failure condition, tells the user what to input and interates error count
							cin.clear();
							string clear;
							getline(cin, clear);
							cout << "Please enter two numbers seperated by a space " << endl;
							error_count += 1;
						}

						// if the number is within range and this is the first pass through pushback on the list
						if (number_pass == 0 && uinput2 < x)
						{
							num_list.push_back(uinput2);
						}

						// if first pass and there is an invalid size inform the user
						if (number_pass == 0 && uinput2 >= x)
						{
							cout << "Please enter an X value within the board range " << endl;
							error_count += 1;
						}

						// if on the second pass and the int is valid push it into the list
						if (number_pass == 1 && uinput2 < y)
						{
							num_list.push_back(uinput2);
						}

						// if on the second pass and the int is invalid throw an error
						if (number_pass == 1 && uinput2 >= y)
						{
							cout << "Please enter a Y value within the board range " << endl;
							error_count += 1;
						}

						// take the current size of the list
						int size = num_list.size();

						// if the size is zero we know that we did not make a successful pass
						if (size == 0)
						{
							number_pass = 0;
						}

						// if the size is 1 we know we have make one successful pass
						if (size == 1)
						{
							number_pass = 1;
						}

						// if the size is two we have both the numbers we need and attempt to exit
						if (size == 2)
						{
							error_flag_0 = true;
							error_flag_1 = true;
						}

						// if there was an error repeat the entire process from the user input again
						if (error_count > 0)
						{
							error_flag_1 = true;
						}

					}

				}
				// create the flag x and y, make a position from them, flag it and then display on the board
				cout << endl;
				int x_f = num_list[0];
				int y_f = num_list[1];
				Position pos = Position(x_f, y_f);
				board.flag(pos);
				board.display(cout);
				cout << endl;
				error_bool = false;
				exit = 1;
				}
			}

			// if the user gives up reveal everything and display it
			if (uinput == "G" || uinput == "g")
			{
				gave_up = true;
				cout << endl;
				board.give_up();
				board.display(cout);
				exit = 1;
				error_bool = false;
			}

			// if there was not a successful command error bool will be true and the user should know
			if (error_bool == true)
			{
				cout << "Unknown command: " << uinput << endl;
			}
		}
		
		// TODO: Then perform that command by calling the appropriate
		// method.

	}

	// TODO: Tell the user whether they won or lost.

	// if the user did not win tell them that they lost
	if (!board.won())
	{
		if (gave_up == false)
		{
			board.give_up();
			board.display(cout);
		}
		cout << endl;
		cout << "*** Condolences, you have lost the game :( ***" << endl;
	}

	// if that is not the case the user must have won and therefore you should tell them!
	if (board.won())
	{
		cout << "*** Gongratulations! You won the game! ***" << endl;
	}

	// TODO: Compute and display how much time the game took.

	// End the clock and tell the user how much time they took
	cout << endl;
	clock_t end = clock();
	double time_elapsed = double(end - begin)/CLOCKS_PER_SEC;

	cout << "Your game took " << time_elapsed << " seconds." << endl;

	// pause and wait for user input to exit the program
	pause_215(true);
	return 0;
}

void pause_215(bool have_newline)
{
    if (have_newline) {
        // Ignore the newline after the user's previous input.
        cin.ignore(200, '\n');
    }

    // Prompt for the user to press ENTER, then wait for a newline.
    cout << endl << "Press ENTER to continue." << endl;
    cin.ignore(200, '\n');
}