#ifndef BASE_H_INCLUDED
#define BASE_H_INCLUDED


#include<string>
#include<iostream>
using namespace std;

class Clock
{
public:
	Clock(int hours, int minutes, bool AM_PM);
	virtual int get_hours() const;
	virtual int get_minutes() const;
	virtual bool get_AM_PM() const;
	virtual void time_tick();
	virtual void print(ostream &out) const;

private:
	int m_hours;
	int m_minutes;
	bool m_AM_PM;

};
#endif