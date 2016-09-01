// Dylan Wise
// CS 215, Spring 2014
// Programming Assignment 3
// 8 April, 2014


#ifndef TASK_H_INCLUDED
#define TASK_H_INCLUDED

#include <string>
#include "Appointments.h"

using namespace std;

class Task : public Appointments
{
public:
/* Task(string label, string notes, int day_of_week, int duration) - Default constructor for Task appointments
 *
 * Description: 
 *		 Creates a Task appointment object using label, notes, day_of_week and a duration
 * Inputs:
 *		 A label and notes, notes can be an empty string, there SHOULD be a label
 *		 However its up to the users discretion, these two strings go the through
 *       the base class. The day_of_week is an int the specifies the day that the task
 *       occurs and the int duration is a number specifying how many minutes long it is
 * Outputs:
 *		 None
 * Side-effects:
 *		 Creates a task object
 * Exceptions:
 *		 None.
 * Notes:
 *		 Default constructor of a derived object
 */
	Task(string label, string notes, int day_of_week, int duration);

/* int get_day_of_week() - Returns the current day of the week for Task
 *
 * Description: 
 *		 Takes the current day of week for Task and returns it
 * Inputs:
 *		 None
 * Outputs:
 *		 Returns the day of the week of the Task object
 * Side-effects:
 *		 None
 * Exceptions:
 *		 None.
 * Notes:
 */
	int get_day_of_week();

/* int get_duration() - Returns the current duration for Task
 *
 * Description: 
 *		 Takes the current duration for Task and returns it
 * Inputs:
 *		 None
 * Outputs:
 *		 Returns the duration of the Task object
 * Side-effects:
 *		 None
 * Exceptions:
 *		 None.
 * Notes:
 */
	int get_duration();

/* virtual bool occurs(int day) const - Tells whether an appointment occured on the current day
 *
 * Description: 
 *		 Task appointments occur on a specific day of the week. This method checks the day of the week 
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

/* virtual void print(ostream &out) const - Prints day of week and the duration in minutes
 *
 * Description: 
 *		 Uses the base class print to print label and notes, then uses the extended task
 *       print to print out the day of the week and how long the task needs to last
 * Inputs:
 *		 None
 * Outputs:
 *		 The label, notes, day of week and duration to the console for the appointment
 * Side-effects:
 *		 Words will be output to the console
 * Exceptions:
 *		 None.
 * Notes:
 */
	virtual void print(ostream &out) const; 

private:
		// an int containing the day of the week the task occurs on
	int m_day_of_week;
		// an int containing the duration of the task in minutes
	int m_duration;
};
#endif