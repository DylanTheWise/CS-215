// Dylan Wise
// CS 215, Spring 2014
// Programming Assignment 3
// 8 April, 2014


#ifndef APPOINTMENTS_H_INCLUDED
#define APPOINTMENTS_H_INCLUDED

#include <string>
using namespace std;

class Appointments
{
public:
/* Appointments(string label, string notes) - Default constructor for Appointments
 *
 * Description: 
 *		 Creates an appointment object using label and notes
 * Inputs:
 *		 A label and notes, notes can be an empty string, there SHOULD be a label
 *		 However its up to the users discretion. 
 * Outputs:
 *		 None
 * Side-effects:
 *		 Creates an object
 * Exceptions:
 *		 None.
 * Notes:
 *		 Default constructor of a base object
 */
	Appointments(string label, string notes);

/* string get_label() - Returns the current label for appointments
 *
 * Description: 
 *		 Takes the current label for appointments and returns it
 * Inputs:
 *		 None
 * Outputs:
 *		 The label of the appointment object
 * Side-effects:
 *		 None
 * Exceptions:
 *		 None.
 * Notes:
 */
	string get_label() const;

/* string get_notes() - Returns the current notes for appointments
 *
 * Description: 
 *		 Takes the current notes for appointments and returns it
 * Inputs:
 *		 None
 * Outputs:
 *		 The notes of the appointment object
 * Side-effects:
 *		 None
 * Exceptions:
 *		 None.
 * Notes:
 */
	string get_notes() const;

/* virtual bool occurs(int day) const - Tells whether an appointment occured on the current day
 *
 * Description: 
 *		 Default occurs never gets used so just returns true
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

/* virtual void print(ostream &out) const - Prints label and notes
 *
 * Description: 
 *		 Since all derived appointment objects have label and notes this
 *       print method with print the label and notes with a newline. However if the object only
 *       contains a label and no notes, this method will pring a label then a newline.
 * Inputs:
 *		 None
 * Outputs:
 *		 The label and then the notes to the user console.
 * Side-effects:
 *		 Words will be output to the console
 * Exceptions:
 *		 None.
 * Notes:
 */
	virtual void print(ostream &out) const;

private:
		// a string containing the label for the object
	string m_label;
		// a string containing the notes for the object
	string m_notes;
};
#endif