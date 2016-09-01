// Dylan Wise
// CS 215, Spring 2014
// Programming Assignment 3
// 8 April, 2014


#include <stdexcept>
#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include "helpers.h"
#include "Appointments.h"
#include "Daily.h"
#include "Weekly.h"
#include "Task.h"
using namespace std;

string day_name(int day)
{
	if (day == SUNDAY)
		return "Sunday";
	else if (day == MONDAY)
		return "Monday";
	else if (day == TUESDAY)
		return "Tuesday";
	else if (day == WEDNESDAY)
		return "Wednesday";
	else if (day == THURSDAY)
		return "Thursday";
	else if (day == FRIDAY)
		return "Friday";
	else if (day == SATURDAY)
		return "Saturday";

	throw logic_error("invalid day");
}

// Split a string on the # character.  Returns a vector of the parts, in order.
vector<string> split_string(string input)
{
	vector<string> pieces;

	// Start of the current field
	int field_start = 0;

	// Location of the next at sign.
	int next_at;
	do {
		// Find the #.  Returns the index, or string::npos if it wasn't
		// found.
		next_at = input.find('#', field_start);

		// If it wasn't found, add the last piece.
		if (next_at == string::npos)
			pieces.push_back(input.substr(field_start));
		// Or it was found, so add this piece
		else
			pieces.push_back(input.substr(field_start, next_at - field_start));

		// The next field starts just after the # 
		field_start = next_at + 1;

		// If there was no #, we're done.
	} while(next_at != string::npos);

	return pieces;
}

// Convert a numeric string to an integer.  Throws an exception if it is
// not a number.
int string_to_int(string str)
{
	int num;
	istringstream instr(str);
	instr >> num;
	if (instr.fail())
		throw runtime_error("invalid number " + str);

	// Check for junk after the number.
	string remaining = "junk";
	getline(instr, remaining);

	// End of file or an empty string means there was no junk.
	if (instr.eof() || remaining == "")
		return num;
	else
		throw runtime_error("garbage after number " + str);
}

int prompt_day()
{
	int day = -1;
	do {
		cout << "What day? [0 = Sunday, 6 = Saturday] ";
		cin >> day;
		if (cin.fail()) {
			cin.clear();
			cout << "Invalid day." << endl;
		} else if (day < SUNDAY || day > SATURDAY) {
			cout << "Day out of range." << endl;
		}
		// Throw away the rest of the line.
		cin.ignore(200, '\n');
	} while (day < SUNDAY || day > SATURDAY);

	return day;
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



// Helper function to parse a line from the schedule file.
// TODO: adjust this to match your classes, and add support for the
// other two types of appointments.
//
Appointments *parse_appointment(string line)
{
	vector<string> columns = split_string(line);
	if (columns.size() < 3)
		throw runtime_error("not enough columns in: " + line);

	// Columns 1-3: type, label, notes
	string type = columns[0];
	string label = columns[1];
	string notes = columns[2];

	if (type == "weekly") {
		if (columns.size() < 6)
			throw runtime_error("not enough columns in: " + line);
		string place = columns[3];
		string time = columns[4];
		int day = string_to_int(columns[5]);
		if (day < SUNDAY || day > SATURDAY)
			throw runtime_error("day out of range");

		// Adjust this to match your class name and parameters.
		return new Weekly(label, notes, place, time, day);
	}
	// TODO: add cases for "daily" and "task"

	if (type == "daily") {
		if (columns.size() < 5)
			throw runtime_error("not enough columns in: " + line);
		string place = columns[3];
		string time = columns[4];

		// Adjust this to match your class name and parameters.
		return new Daily(label, notes, place, time);
	}

	if (type == "task") {
		if (columns.size() < 5)
			throw runtime_error("not enough columns in: " + line);
		string duration = columns[4];
		int duration1 = string_to_int(duration);
		int day_of_week = string_to_int(columns[3]);
		if (day_of_week < SUNDAY || day_of_week > SATURDAY)
			throw runtime_error("day out of range");

		// Adjust this to match your class name and parameters.
		return new Task(label, notes, day_of_week, duration1);
	}

	// If we got here, we didn't handle the appointment type.
	throw runtime_error("unknown appointment type " + type);
}

