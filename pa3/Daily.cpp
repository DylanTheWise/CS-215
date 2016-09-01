// Dylan Wise
// CS 215, Spring 2014
// Programming Assignment 3
// 8 April, 2014


#include <iostream>
#include <string>
#include <vector>
#include <stdexcept>
#include "Appointments.h"
#include "Daily.h"

using namespace std;

Daily::Daily(string label, string notes, string place, string time)
	: Appointments(label, notes)
{
	m_place = place;
	m_time = time;
}

string Daily::get_place()
{
	return m_place;
}

string Daily::get_time()
{
	return m_time;
}

bool Daily::occurs(int day) const
{
	return true;
}

void Daily::print(ostream &out) const
{
	Appointments::print(out);
		// Prints out where and when this appointment takes place, the tabs are to seperate the base class
	    // prints from the inherited class prints style-wise
	out << "\t" << "Where: " << m_place << endl;
	out << "\t" << "When: " << "Every day at " << m_time << endl;
}