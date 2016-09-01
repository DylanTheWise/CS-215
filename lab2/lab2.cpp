// Dylan Wise
// CS 215, Section 001, Spring 2014
// 29 January, 2014
#include <iostream>
#include <string>
#include <cctype>


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
 *   Reads two lines from standard input if have_newline is true,
 *   one line if it is false.  Lines are assumed to be less than
 *   two hundred characters long.
 *
 * Outputs:
 *   No return value.
 *
 *   Prints a prompt to standard output.
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

/* char_to_digit(char c) - Take a char and convert it to its proper 
 *                         decimal value
 *
 * Description: 
 *   Take the char that are known to be digits and subtract 48
 *   from that value to get the original decimal value
 *
 * Inputs:
 *   char c
 *       This character is known to be a digit as in order for 
 *       function to activate the char must trigger the 
 *       isdigit() function
 *
 * Outputs:
 *   Outputs the decimal equivalent of the char inputed. 
 *
 *   Prints a prompt to standard output.
 *
 * Notes:
 *   It is assumed that the char entered is a digit due to the
 *   isdigit function
 */
int char_to_digit(char c)
{
	int num = c;
	num -= 48;
	return num;
}

/* ASCII(string input) - Take a string and convert the individual
 *                       characters in char unless the character
 *                       is a digit
 *
 * Description: 
 *   Take the contents of string and return ASCII values 
 *   unless it's a digit
 *
 * Inputs:
 *   string input
 *       This string can have any ASCII character
 *
 * Outputs:
 *   None
 *   Does cout the ASCII for all characters except digits
 */
void ASCII(string input)
{
	int len = input.length();
	for (int i = 0; i < len; i++)
	{	
		char c = input[i];

		if (isdigit(c))
		{
			int x = char_to_digit(c);
			cout << x << " ";
		}
		else
		{
			int code = c;
			cout << code << " ";
		}
	}
}

int main()
{
	//Take a string
	string input = "";
	cout << "Enter a string. " << endl;
	cin >> input;

	//Find string length
	int length = 0;
	length = input.length();
	
	ASCII(input);

	pause_215(true);

	return 0;
}