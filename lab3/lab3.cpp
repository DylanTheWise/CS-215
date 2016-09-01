#include <iostream>
#include <string>
#include <cctype> // For isdigit()
#include <vector>

using namespace std;

// Function prototypes (see p. 203-204 of the text).

void pause_215(bool have_newline);

/* string_to_digits - convert a numeric string to a reversed vector of digits
 *
 * Description: Converts the input string, numstr, into a vector of
 * integers between 0 and 9.  The vector is stored in reverse order, with
 * the ones digit first.  If numstr contains any non-digit characters,
 * returns an empty vector.
 *
 * Inputs:
 *   numstr:  The string to convert.
 *
 * Outputs:
 *   If numstr is numeric (contains only digit characters), returns a
 *   vector containing the integer values of the digits in numstr,
 *   in reverse order.  Otherwise, returns an empty vector.
 */

vector<int> string_to_digits(const string &numstr);

int main()
{
    string input = "";

    // Repeat the loop as long as there isn't an input error.
    while (cin)
    {
        cout << "Enter a number, or \"quit\" to exit: ";
        cin >> input;

        // Leave the loop early if the user typed "quit".
        if (input == "quit")
            break;

        vector<int> vec = string_to_digits(input);

        if (vec.size() == 0) {
            cout << "\"" << input << "\" isn't numeric!" << endl;
        } else {
            cout << "Starting from the ones digit: ";

            // Print the values from the vector.
            for (size_t i = 0; i < vec.size(); i++)
            {
                // Put a comma before every element but the first.
                if (i > 0)
                    cout << ", ";
                cout << vec[i];
            }
            cout << endl;
        }
    }

    pause_215(true);
}

// TODO: implement string_to_digits here.

vector<int> string_to_digits(const string &numstr)
{
	int len = numstr.length();
	vector<int> numvector;
	for (int i = len-1; i >= 0; i--)
	{
		char c = numstr[i];
		if (isdigit(c) == false)
			return vector<int>();

		else
		{
		int digit = c - '0' ;
		numvector.push_back (digit);
		}
	}
	return numvector;
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
