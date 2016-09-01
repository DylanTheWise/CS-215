// Dylan Wise
// CS 215, Spring 2014
// Programming Assignment 3
// 8 April, 2014


#include <iostream>
#include <string>
#include <vector>
#include <stdexcept>
#include "Appointments.h"
#include "Weekly.h"
#include "helpers.h"

using namespace std;

Weekly::Weekly(string label, string notes, string place, string time, int day_of_week)
	: Appointments(label, notes)
{
	m_place = place;
	m_time = time;
	m_day_of_week = day_of_week;
}

string Weekly::get_place()
{
	return m_place;
}

string Weekly::get_time()
{
	return m_time;
}

int Weekly::get_day_of_week()
{
	return m_day_of_week;
}

bool Weekly::occurs(int day) const
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

void Weekly::print(ostream &out) const
{
	string day_name_str = day_name(m_day_of_week);
	Appointments::print(out);
		// Task specific print, seperated sylistically by the tab
	out << "\t" << "Where: " << m_place << endl;
	out << "\t" << "When: " << day_name_str << " at " << m_time << endl;
}