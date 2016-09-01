// Dylan Wise
// CS 215, Spring 2014
// Programming Assignment 3
// 8 April, 2014


#ifndef SCHEDULE_H_INCLUDED
#define SCHEDULE_H_INCLUDED

#include <string>
#include <vector>
#include "Appointments.h"
using namespace std;

class Schedule
{
public:
/* Schedule() - the default constructor for the schedule object
 *
 * Description: 
 *		 Creates a schedule object
 * Inputs:
 *		 None
 * Outputs:
 *		 None
 * Side-effects:
 *		 Creates an object
 * Exceptions:
 *		 None.
 * Notes:
 *		 Default constructor of a base object
 */
	Schedule();

/* ~Schedule() - the deconstructor for the schedule object
 *
 * Description: 
 *		 frees the memory created by the new for creation of the appointment pointers
 * Inputs:
 *		 None
 * Outputs:
 *		 None
 * Side-effects:
 *		 Frees the dynamically allocated memory created during the program
 * Exceptions:
 *		 None.
 * Notes:
 *		 Deconstructor of a base object
 */
	~Schedule();

/* int size() - finds the current size of the vector containing the appointments
 *
 * Description: 
 *		 uses the size member function of the vector class and finds the size
 *       of the appointments vector
 * Inputs:
 *		 None
 * Outputs:
 *		 an int containing the size of the vector 
 * Side-effects:
 *		 creates a new int
 * Exceptions:
 *		 None.
 * Notes:
 */
	int size();

/* void load(string filename) - takes a string containing the filename an attempts to open the file
 *
 * Description: 
 *		 with the filename that was seen to be legitamite in main, open the file here in the class
 * Inputs:
 *		 a string containing the filename
 * Outputs:
 *		 a file containing the appointments
 * Side-effects:
 *		 a new file opened in the stack
 * Exceptions:
 *		 None.
 * Notes:
 */
	void load(string filename);

/* void add(Appointments* app) - takes the appointments object and attempts to add it to the vector of appointments
 *
 * Description: 
 *		 Using the already created appointment object this method attempts to add it to the vector of appointments
 * Inputs:
 *		 A pointer pointing to an appointments object (or its derived objects)
 * Outputs:
 *		 None
 * Side-effects:
 *		 The new appointment is added to the vector of appointment pointers
 * Exceptions:
 *		 None.
 * Notes:
 */
	void add(Appointments* app);

/* void remove(int number) - removed the appointment whos index corresponds to the input number
 *
 * Description: 
 *		 using the erase function an object of the vector is removed
 * Inputs:
 *		 A number containing the index of the object to be removed
 * Outputs:
 *		 None
 * Side-effects:
 *		 The vector of appointments will now be missing the object specified.
 * Exceptions:
 *		 None.
 * Notes:
 */
	void remove (int number);

/* void print_day(int number) const - prints all the appointments for the specified day of the week
 *
 * Description: 
 *		 We find the size of the vector, then use the number provided and find the day of the week. With that
 *       we compare the number provided with the one in the appointment object. If the the does occur bool is
 *       true the appointment is printed out to the console
 * Inputs:
 *		 the number containing the day of the week
 * Outputs:
 *		 All tha appointments that occur on that day of week are printed out
 * Side-effects:
 *		 Possibly many things being output to the console. If many appointments are on that day
 *       the console will be flooded.
 * Exceptions:
 *		 None.
 * Notes:
 */
	void print_day(int number) const;

/* void print_week() const - prints all the appointments for the week, seperated by day
 *
 * Description: 
 *		 We find the size of the vector, we make a for loop that cycles 7 times (for each day of the week)
 *       we use that to print the day of week. After that we have another for loop that goes the amount of 
 *       times corresponding to the size of the vector. We then go through the elements of the vector and 
 *       use the does occur bool to see if we need to print it.
 * Inputs:
 *		 None
 * Outputs:
 *		 All tha appointments that occur in the week, seperated by the day of the week
 * Side-effects:
 *		 Possibly many things being output to the console. If many appointments are daily almost a 
 *       guarantee for flooding
 * Exceptions:
 *		 None.
 * Notes:
 */
	void print_week() const;

private:
		// a vector of appointments containing all the appointment objects
	vector<Appointments*> m_appointments;
		// a string containing the name of the filename
	string m_filename;
};
#endif