#include <iostream>
#include <string>
#include "base.h"
#include "derived.h"
using namespace std;

Alarm::Alarm(int hours, int minutes, bool AM_PM, int al_hours, int al_minutes, bool al_AM_PM)
	: Clock(hours, minutes, AM_PM)
{
	m_a_hours = al_hours;
	m_a_minutes = al_minutes;
	m_a_AM_PM = al_AM_PM;
}

int Alarm::get_hours() const
{
	Clock::get_hours();
}

int Alarm::get_a_hours() const
{
	return m_a_hours;
}

int Alarm::get_minutes() const
{
	Clock::get_minutes();
}

int Alarm::get_a_minutes() const
{
	return m_a_minutes;
}

bool Alarm::get_AM_PM() const
{
	Clock::get_AM_PM();
}

bool Alarm::get_a_AM_PM() const
{
	return m_a_AM_PM;
}

void Alarm::time_tick()
{
	Clock::time_tick();
}

void Alarm::print(ostream &out) const
{
	Clock::print(out);
}

void Alarm::check_alarm() const
{
	int BEEP = 0;
	int hours = get_hours();
	int minutes = get_minutes();
	bool AM_PM = get_AM_PM();

	if (m_a_hours == hours)
		BEEP += 1;
	if (m_a_minutes == minutes)
		BEEP += 1;
	if (m_a_AM_PM == AM_PM)
		BEEP += 1;

	if (BEEP == 3)
		cout << "BEEP BEEP BEEP!" << endl;
}