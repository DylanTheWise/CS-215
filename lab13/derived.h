#ifndef DERIVED_H_INCLUDED
#define DERIVED_H_INCLUDED


#include<string>
#include<iostream>
using namespace std;

class Alarm : public Clock
{
public:
	Alarm(int hours, int minutes, bool AM_PM, int a_hours, int a_mintes, bool a_AM_PM);
	int get_a_hours() const;
	int get_a_minutes() const;
	bool get_a_AM_PM() const;
	virtual int get_hours() const;
	virtual int get_minutes() const;
	virtual bool get_AM_PM() const;
	virtual void time_tick();
	virtual void print(ostream &out) const;
	void check_alarm() const;
private:
	int m_a_hours;
	int m_a_minutes;
	bool m_a_AM_PM;

};
#endif