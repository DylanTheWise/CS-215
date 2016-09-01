// Dylan Wise
// CS 215, Section 001, Spring 2014
// Programming Assignment 1
// 29 January, 2014

// This program will be able to add two non-negative numbers of any size

#include <iostream>
#include <string>
#include <vector>
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

void pause_215(bool have_newline);

/* digit_to_char(int) - convert a digit to a char (ASCII value)
 *
 * Description: 
 *   Take in a single digit and convert it to a char (ASCII)
 *
 * Inputs:
 *   A single integer
 *
 * Outputs:
 *   A char that equals the ASCII value of the integer input.
 *
 *   Nothing is output to the console. 
 *
 * Notes:
 *   This function is intended to be used in the function to convert
 *   a vector to a string. 
 */

char digit_to_char (int num);

/* vector_to_string(vector<int>&) - convert a digit to a char (ASCII value)
 *
 * Description: 
 *   Take vector and convert it to a string
 *
 * Inputs:
 *   A single vector
 *
 * Outputs:
 *   A string that equals to the reverse of the vector inputed
 *
 *   Nothing is output to the console. 
 *
 * Notes:
 *   This function is created to take a vector (the sum) and convert it to
 *   a string in reverse order
 *
 *   The for loop's start number is the length of the function's input and ends
 *   when i equals zero. The loop decrements. 
 */

string vector_to_string(const vector<int> &sumvector);

/* char_to_digit(char) - convert a char (ASCII value) to the digit it represents
 *
 * Description: 
 *   Takes a char (ASCII) and converts it to the digit that it represents
 *
 * Inputs:
 *   This function takes in a char
 *
 * Outputs:
 *   An integer that can be used in math equations.
 *
 *   Nothing is output to the console. 
 *
 * Notes:
 *   This function takes in the chars from a string that only contains numbers
 *   and converts it to the digit it represents
 *   
 */

int char_to_digit(char c);

/* vector<int> addition(const vector<int>&, const vector<int>&)
 *                      convert a digit to a char (ASCII value)
 *
 * Description: 
 *   Take two vectors that represent two numbers that are in reverse order
 *   To do this the program will add the ones place first obtain its sum 
 *   and put that into the sum vector. If this sum is larger than 10 the sum
 *   of the next addition will be increased by 1 (to accomodate the carry)
 *
 * Inputs:
 *   Two vectors in reverse order that will be added together to generate a sum
 *
 * Outputs:
 *   The sum of the two vectors as a new vector, still in reverse order
 *
 *   Nothing is output to the console. 
 *
 * Notes:
 *   This function will add any two non-negative numbers of any size
 *
 */

vector<int> addition(const vector<int> &numvector1, const vector<int> &numvector2);

/* string_to_vector(string) - convert a string of numbers into a vector
 *
 * Description: 
 *   Take a string of numbers and convert it to a vector that stores the 
 *   numbers in reverse order
 *
 * Inputs:
 *   A string of numbers
 *
 * Outputs:
 *   A vector with whatever was in the string but in reverse order
 *
 *   Nothing is output to the console. 
 *    
 */

vector<int> string_to_vector(string num);

/* bool non_numeric_char_test(string) - a bool that will tell if the input given 
 *                                      contains only numbers or not
 *
 * Description: 
 *   takes in a string input by the user and tests if it contains only number
 *   if it does not the bool returned is false
 *
 * Inputs:
 *   A single string that may or may not contain non-numbers
 *
 * Outputs:
 *   a bool that can be either false or true depending on if the input string
 *   contains not-numeric characters or not
 *
 *   Nothing is output to the console. 
 *
 */

bool non_numeric_char_test (string num);

/* int main() - add two vectors together
 *
 * Description: 
 *   Take two strings of numbers and add their contents together
 *
 * Inputs:
 *   Two strings of numbers input by the user
 *
 * Outputs:
 *   The sum of the two numbers that were input
 *
 *   The equation and it answer are output into the console
 * 
 */

int main()
{

	cout << "Hello, this program will add two non-negative numbers of any size together." << endl;
	cout << "Press ENTER to continue." << endl;

	cin.ignore(200, '\n');

	// Initialization of all the variables to be used in main
	// so goto can be used if an error occurs
	string num1 = "";
	string num2 = "";
	string answer = "";
	vector<int> numvector1;
	vector<int> numvector2;
	vector<int> sum;


	cout << "Please enter you first number." << endl;
	cin >> num1; cout << endl;

	// If any of the input numbers is not a number skip to the end of the function
	bool error_test = non_numeric_char_test(num1);
	if (error_test == false) { goto error_end; }

	numvector1 = string_to_vector(num1);

	cout << "Thank you, now please enter your second number." << endl;
	cin >> num2; cout << endl;

	// If any of the input numbers is not a number skip to the end of the function
	error_test = non_numeric_char_test(num2);
	if (error_test == false) {goto error_end;}

	numvector2 = string_to_vector(num2);

	sum = addition(numvector1, numvector2);

	answer = vector_to_string(sum);

	cout << num1 << " " << "+" << " " << num2 
	<< " " << "=" << " " << answer << endl;

	// Portion of the code the function will skip to if an error is called.
	error_end:
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

char digit_to_char (int num)
{
	int single = num;
	// Add 48 so the int is equal to the ASCII value
	single += 48;
	char c_num = single;
	return c_num;
}

string vector_to_string(const vector<int> &sumvector)
{
	string sum_string = "";
	int sumvectorlen = sumvector.size();
	for (int i = sumvectorlen; i > 0; i--)
	{
		// Due to length starting at 1 and iterators starting a
		// zero you have to subtract i by 1 for the loop to work
		// correctly
		int single_num = sumvector[i-1];
		char string_single = digit_to_char(single_num);
		sum_string.push_back(string_single);
	}

	return sum_string;
}

int char_to_digit(char c)
{
	int num = c;
	num -= 48;
	return num;
}

vector<int> addition(const vector<int> &numvector1, const vector<int> &numvector2)
{
	bool carry_bool = false;
	int sumvectorlen = 0;
	vector<int> sumvector (0,0);
	// These takes the size of both the vectors input
	int fst_vector_size = numvector1.size();
	int snd_vector_size = numvector2.size();

	// This if else discovers which vector is largest.
	if (fst_vector_size > snd_vector_size) 
	{
		sumvectorlen = fst_vector_size;
	}

	else 
	{
		sumvectorlen = snd_vector_size;
	}

	// The largest vector size then becomes the int that the for loop stops at
	for (int i = 0; i < sumvectorlen; i++)
	{
		// Initializes the ints that will become the induvidual numbers of the
		// vectors
		char num_piece1 = 0;
		char num_piece2 = 0;
		// If the first vector does not have enough values to go through the loop
		// this line skips the line that uses a subscript that could cause and error
		if (fst_vector_size <= i) {num_piece1 = 0;}
		else 
		{
			num_piece1 = numvector1[i];
		}

		if (snd_vector_size <= i) {num_piece2 = 0;}
		else 
		{
			num_piece2 = numvector2[i];
		}

		int sum_num = num_piece1 + num_piece2;
		// If the previous loop had a carry this line adds 1 to the sum
		// of the two numbers to accomodate
		if (carry_bool == true) {sum_num += 1;}
		// Reset the bool to false so it can be used in the next pass
		carry_bool = false;
		int carry = sum_num / 10;
		int remainder = sum_num % 10;
		sumvector.push_back (remainder);
		// If this is the last time the loop will run and the carry is 1
		// a 1 is added the end of the vector (to represent a new digit being
		// added to the sum
		if (i == sumvectorlen -1 && carry == 1)
		{
			sumvector.push_back (1);
		}
		// If the sum of the two numbers is 10 or over the carry bool will equal
		// true
		if (carry == 1) 
		{
			carry_bool = true;
		}
	}
	return sumvector;
}

vector<int> string_to_vector(string num)
{
	int len = num.length();
	vector<int> basevector (0,0);
	for (int i = 0; i < len; i++)
	{
		char num_piece = num[len - 1 - i];
		// calls the function to convert the chars to ints
		int norm_num = char_to_digit(num_piece);
		basevector.push_back (norm_num);
	}
	return basevector;
}

bool non_numeric_char_test (string num)
{
	int i = 0;
	bool is_number = true;
	int len = num.length();
	while (i <= len - 1)
	{
		char num_piece = num[len - 1 - i];
		// If the char ascii value isnt a number bool gets tripped.
		if (num_piece > 57 || num_piece < 48)
		{
			is_number = false;
		}
		// Iterator to exit while loop
		i += 1;
	}
	if (is_number == false) {cout << "ERROR NON-NUMERIC INPUT" << endl;}
	return is_number;
}