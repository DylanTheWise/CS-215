// Dylan Wise
// CS 215, Spring 2014
// Programming Assignment 3
// 8 April, 2014


#include <iostream>
#include <string>
#include <vector>
#include <stdexcept>
#include "Appointments.h"

using namespace std;

Appointments::Appointments(string label, string notes)
{
	m_label = label;
	m_notes = notes;
}

string Appointments::get_label() const
{
	return m_label;
}

string Appointments::get_notes() const
{
	return m_notes;
}

bool Appointments::occurs(int day) const
{
	return true;
}

void Appointments::print(ostream &out) const
{
	out << m_label;
	if (m_notes != "")
	{
		out << " (" << m_notes << ")" << endl;
	}
		// If the this if else was not here if the appointment had no notes it would have no endline
	    // and therefore look inconsistant 
	else
		out << endl;
}
