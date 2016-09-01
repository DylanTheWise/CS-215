// Dylan Wise
// CS 215, Spring 2014
// Programming Assignment 3
// 8 April, 2014


#ifndef DAILY_H_INCLUDED
#define DAILY_H_INCLUDED

#include <string>
#include "Appointments.h"

using namespace std;

class Daily : public Appointments
{
public:
/* Daily(string label, string notes, string place, string time) - Default constructor for Daily appointments
 *
 * Description: 
 *		 Creates a Daily appointment object using label, notes, place and a time
 * Inputs:
 *		 A label and notes, notes can be an empty string, there SHOULD be a label
 *		 However its up to the users discretion, these two strings go the through
 *       the base class. The next to objects, place and time, are unique to this 
 *       object and are also input by the user.
 * Outputs:
 *		 None
 * Side-effects:
 *		 Creates a daily object
 * Exceptions:
 *		 None.
 * Notes:
 *		 Default constructor of a derived object
 */
	Daily(string label, string notes, string place, string time);

/* string get_place() - Returns the current place for daily
 *
 * Description: 
 *		 Takes the current place for daily and returns it
 * Inputs:
 *		 None
 * Outputs:
 *		 Returns the place of the daily object
 * Side-effects:
 *		 None
 * Exceptions:
 *		 None.
 * Notes:
 */
	string get_place();

/* string get_time() - Returns the current time for daily
 *
 * Description: 
 *		 Takes the current time for daily and returns it
 * Inputs:
 *		 None
 * Outputs:
 *		 Returns the time of the daily object
 * Side-effects:
 *		 None
 * Exceptions:
 *		 None.
 * Notes:
 */
	string get_time();

/* virtual bool occurs(int day) const - Tells whether an appointment occured on the current day
 *
 * Description: 
 *		 Daily appointments occur everyday so the bool will always return true
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

/* virtual void print(ostream &out) const - Prints place and time
 *
 * Description: 
 *		 Uses the base class print to print label and notes, then uses the extended daily
 *       print to print out where and when the appointment takes place, both preceeded by a tab
 * Inputs:
 *		 None
 * Outputs:
 *		 The label, notes, place and time to the user console in a neat and clean fashion
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
};
#endif