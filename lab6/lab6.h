#ifndef LAB6_H
#define LAB6_H

#include<iostream>
using namespace std;


// Remember to #include anything that is used in the header
// file, and to add the using namespace std; here.

// Define (but don't implement) your rational class here.

/* class rational() - take two numbers and divide them rationally
 *
 * Description: 
 *   Take two numbers to divide and print out the rational function
 *   then take another two numbers and add their fraction with the other
 *   as well as print out the answer in decimal format as a double
 *
 * Inputs:
 *   No input from the user.
 *
 * Outputs:
 *   Outputs the numbers in fraction form. Another pair of fractions 
 *   that are added together and then prints their decimal form.
 *
 * Side-effects:
 *   Prints a prompt to standard output.  Reads no lines of input.
 *
 * Exceptions:
 *   Division by zero informs the user that there is an error.
 *
 * Notes:
 * 
 */

class rational {
    public:
		rational();
		rational(int numerator, int denomicator);
		void print(ostream &out) const;
		double as_double() const;
		void add(rational r);

    private:
		int m_numerator;
		int m_denominator;
};

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

// Not actually used; for demonstration purposes only.
const double PI = 3.14159265;

#endif