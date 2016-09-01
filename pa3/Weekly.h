// Dylan Wise
// CS 215, Spring 2014
// Programming Assignment 3
// 8 April, 2014


#ifndef WEEKLY_H_INCLUDED
#define WEEKLY_H_INCLUDED

#include <string>
#include "Appointments.h"

using namespace std;

class Weekly : public Appointments
{
public:
/* Weekly(string label, string notes, string time, int day_of_week) - Default constructor for Weekly appointments
 *
 * Description: 
 *		 Creates a Weekly appointment object using label, notes, time and a day_of_week
 * Inputs:
 *		 A label and notes, notes can be an empty string, there SHOULD be a label
 *		 However its up to the users discretion, these two strings go the through
 *       the base class. The time will be a string given by the user and the day of week
 *       will be an int given by the user
 * Outputs:
 *		 None
 * Side-effects:
 *		 Creates a Weekly object
 * Exceptions:
 *		 None.
 * Notes:
 *		 Default constructor of a derived object
 */
	Weekly(string label, string notes, string place, string time, int day_of_week);

/* string get_place() - Returns the place for Weekly as a string
 *
 * Description: 
 *		 Takes the current place for weekly and returns it
 * Inputs:
 *		 None
 * Outputs:
 *		 Returns the place for the weekly object
 * Side-effects:
 *		 None
 * Exceptions:
 *		 None.
 * Notes:
 */
	string get_place();

/* string get_time() - Returns the time for Weekly as a string
 *
 * Description: 
 *		 Takes the current time for weekly and returns it
 * Inputs:
 *		 None
 * Outputs:
 *		 Returns the time for the Weekly object
 * Side-effects:
 *		 None
 * Exceptions:
 *		 None.
 * Notes:
 */
	string get_time();

/* int get_day_of_week() - Returns the current day of the week for Weekly
 *
 * Description: 
 *		 Takes the current day of week for Weekly and returns it
 * Inputs:
 *		 None
 * Outputs:
 *		 Returns the day of the week of the Weekly object
 * Side-effects:
 *		 None
 * Exceptions:
 *		 None.
 * Notes:
 */
	int get_day_of_week();

/* virtual bool occurs(int day) const - Tells whether an appointment occured on the current day
 *
 * Description: 
 *		 Weekly appointments occur on a specific day of the week. This method checks the day of the week 
 *       for the object with the specified day of the week input. If they are the same the bool returns true
 *       if not it returns false
 * Inputs:
 *		 an int the corresponds to a day
 * Outputs:
 *		 a bool that tells whether an appointment occured on the int day
 * Side-effects:
 *		 None.
 * Exceptions:
 *		 None.
 * Notes:
 */
	virtual bool occurs(int day) const;

/* virtual void print(ostream &out) const - Prints place, time and day of week
 *
 * Description: 
 *		 Uses the base class print to print label and notes, then uses the extended Weekly print
 *       to print the place, then the time and day of week the appointment occurs on.
 * Inputs:
 *		 None
 * Outputs:
 *		 The label, notes, place, time, and day of week are output to the console
 * Side-effects:
 *		 Words will be output to the console
 * Exceptions:
 *		 None.
 * Notes:
 */
	virtual void print(ostream &out) const; 

private:
		// a string containing the place the appointment is at
	string m_place;
		// a string containing the time the appointment occurs at
	string m_time;
		// an int containing the day of the week the task occurs on
	int m_day_of_week;
};
#endif