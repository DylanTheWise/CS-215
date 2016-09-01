// Dylan Wise
// CS 215, Spring 2014
// Programming Assignment 3
// 8 April, 2014


#ifndef HELPERS_H_INCLUDED
#define HELPERS_H_INCLUDED

#include "Appointments.h"
#include <vector>
#include <string>
using namespace std;

	// Since these ints remain incredibly important throughout the duration of the program they are 
    // defined here globally. Each day of the week corresponds to a number starting at index 0 on Sunday
const int SUNDAY = 0;
const int MONDAY = 1;
const int TUESDAY = 2;
const int WEDNESDAY = 3;
const int THURSDAY = 4;
const int FRIDAY = 5;
const int SATURDAY = 6;

/* int prompt day() - takes a numeric input from the user and returns it
*                     if that number is valid
 *
 * Description: 
 *   a question is output to the console asking the user what day?
 *   the user inputs 0-6 corresponding with Sunday - Saturday, if out of 
 *   range or non-numeric and error is output and use retries
 *
 * Inputs:
 *   into the function none, inside the function a number 0-6
 *
 * Outputs:
 *   and int that the user input that is 0-6
 *
 * Side-effects:
 *   Text is output to the console in the form of a question
 *
 * Exceptions:
 *   If the users input is non-numeric or out of range an exception
 *   is thrown
 *
 * Notes:
 */
int prompt_day();

/* int string_to_int(string str) - takes a numeric string and converts it to an int
 *
 * Description: 
 *   Takes a string that is supposed to contain only a number and converts it to and int
 *
 * Inputs:
 *   a string that should be a number
 *
 * Outputs:
 *   an int containing the number that was input
 *
 * Side-effects:
 *   a new int
 *
 * Exceptions:
 *   if the input is non-numeric or if there is junk after the numberic string
 *
 * Notes:
 */
int string_to_int(string str);

/* vector<string> split_string(string input) - takes a string an splits it into its elements
 *
 * Description: 
 *   Takes a string that comes from a schedule text file and splits along the "#"
 *   it then takes those elements and puts them into a vector of strings
 *
 * Inputs:
 *   a string that should come from a schedule text file
 *
 * Outputs:
 *   a vector containing the elements of that string
 *
 * Side-effects:
 *   a new vector containing the necessary elements to construct an appointment
 *
 * Exceptions:
 *   None
 *
 * Notes:
 */
vector<string> split_string(string input);

/* string day_name(int day_of_week) - takes an int that contains an index 0-6 and makes
 *                                    it a string based on that number
 *
 * Description: 
 *   takes an int 0-6 and gives it the corresponding name of the day of the week
 *   with 0 being "Sunday", 1 being "Monday" and so on
 *
 * Inputs:
 *   in int which is 0-6
 *
 * Outputs:
 *   a string containing a day of the week
 *
 * Side-effects:
 *   a new string is created
 *
 * Exceptions:
 *   None
 *
 * Notes:
 */
string day_name(int day_of_week);

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

/* Appointments *parse_appointments(string line) - calls the constructors of the derived classes based on 
 *                                                 based on what the string contains                                                 
 *
 * Description: 
 *   When strings are read from the text files made for the schedule class they contain
 *   each of the elements necessary to construct an appointment object. This function takes 
 *   those strings calls the split string function to put each element seperated by a "#" and
 *   put those into a vector. Then this function takes that vector looks at the first element
 *   which indicates what type of object it is and enters that portion of the parse. The parse then 
 *   takes each element out and assigns those to strings (in some cases these need to be converted to ints)
 *   these are then use to call the constructor the respective derived class
 *
 * Inputs:
 *   a string that must be a single line from a text file that is correctly formated for the use of this 
 *   program
 *
 * Outputs:
 *   An apppoitments pointer that contain any one of the derived classes we have
 *
 * Side-effects:
 *   The creation of an object pointer 
 *
 * Exceptions:
 *   Many, mostly concerning not having enough elements in the vector to properly create an object, 
 *   these should never trip as long as the rest of the program is working correctly, also another exception
 *   if the appointment type is not recognized
 *
 * Notes:
 */
Appointments *parse_appointment(string line);

#endif

