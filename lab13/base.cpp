#include <iostream>
#include <string>
#include "base.h"

using namespace std;

Clock::Clock(int hours, int minutes, bool AM_PM)
{
	m_minutes = minutes;
	m_hours = hours;
	m_AM_PM = AM_PM;
}

int Clock::get_hours() const
{
	return m_hours;
}

int Clock::get_minutes() const
{
	return m_minutes;
}

bool Clock::get_AM_PM() const
{
	return m_AM_PM;
}

void Clock::time_tick()
{
	int skip = 0;
	bool advance_hour = false;
	if (m_minutes < 59)
	{
		m_minutes += 1;
	}
	else
		advance_hour = true;

	if (advance_hour && m_hours < 11)
	{
		m_minutes = 0;
		m_hours += 1;
	}

	if (advance_hour && m_hours == 11)
	{
		m_minutes = 0;
		m_hours += 1;
		if (m_AM_PM)
		{
			m_AM_PM = false;
			skip = 1;
		}
		if (!m_AM_PM && skip == 0)
		{
			m_AM_PM = true;
		}
	}

	if (advance_hour && m_hours == 12)
	{
		m_hours = 1;
		m_minutes = 0;
	}
}

void Clock::print(ostream &out) const
{
	cout << "The time is " << m_hours << ":" << m_minutes << " ";
	if (m_AM_PM){
		cout << "AM";}
	if (!m_AM_PM){
		cout << "PM";}

	cout << endl;
}