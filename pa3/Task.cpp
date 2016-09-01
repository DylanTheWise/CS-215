// Dylan Wise
// CS 215, Spring 2014
// Programming Assignment 3
// 8 April, 2014


#include <iostream>
#include <string>
#include <vector>
#include <stdexcept>
#include "Appointments.h"
#include "Task.h"
#include "helpers.h"

using namespace std;

Task::Task(string label, string notes, int day_of_week, int duration)
	: Appointments(label, notes)
{
	m_day_of_week = day_of_week;
	m_duration = duration;
}

int Task::get_day_of_week()
{
	return m_day_of_week;
}

int Task::get_duration()
{
	return m_duration;
}

bool Task::occurs(int day) const
{
		// Checks if the day input matches the day of the week
		// if it does return true, if not return false
	if (m_day_of_week == day)
	{
		return true;
	}
	else
	{
		return false;
	}
}

void Task::print(ostream &out) const
{
	string day_name_str = day_name(m_day_of_week);
	Appointments::print(out);
		// The Task specific prints, seperated stylistically by a tab
	out << "\t" << "When: " << "any time on " << day_name_str << endl;
	out << "\t" << "for " << m_duration << " minutes" << endl;
}