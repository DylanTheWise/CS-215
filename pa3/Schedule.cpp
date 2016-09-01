// Dylan Wise
// CS 215, Spring 2014
// Programming Assignment 3
// 8 April, 2014


#include <iostream>
#include <string>
#include <istream>
#include <sstream>
#include <vector>
#include <fstream>
#include <stdexcept>
#include "helpers.h"
#include "Schedule.h"
#include "Appointments.h"
#include "Daily.h"
#include "Weekly.h"
#include "Task.h"

using namespace std;

Schedule::Schedule()
{
	m_filename = "";
	vector<Appointments*> m_appointments;
}

Schedule::~Schedule()
{
		// Goes through the appoitnments vector and deletes each of the pointers
	int filesize = m_appointments.size();
	for (int i = 0; i < filesize; i++)
	{
		delete m_appointments[i];
	}
}

int Schedule::size()
{
		// Takes the current size of the appointment vector and sends it to where ever called for use
	int filesize;
	filesize = m_appointments.size();
	return filesize;
}

void Schedule::load(string filename)
{
	bool fail = true;
	ifstream in_file;
	string line;
	while (fail == true)
	{
		try{
			in_file.open(filename.c_str());
			fail = false;
		}
		catch(runtime_error &e)
		{
			cout << "Error: " <<e.what() << "Please enter a valid filename " << endl;
			getline(cin, filename);
		}
	}
		if (in_file.is_open())
	{
		while( getline (in_file, line) )
		{
			
		}
	}
}

void Schedule::add(Appointments* app)
{
		// Pushes the most recenly created object to the back of the appointments vector
	m_appointments.push_back(app);
}

void Schedule::remove(int number)
{
		// Erases the appointment object for the number (index) specified
	m_appointments.erase (m_appointments.begin()+number);
}

void Schedule::print_day(int number) const
{
		// Takes the size of the appointments vector
	int size = m_appointments.size();
		// Using the number given determine what day it is, then print that day
	string isday = day_name(number);
	cout << isday << ":" << endl;
		// A loop based on the size of the appointments vector
	for(int i = 0; i < size; i++)
	{
			// Checks if the appointment occurs that day then prints if it does
		bool doesoccur = m_appointments[i]->occurs(number);
		if (doesoccur == true)
		{
			cout << i << "   ";
			m_appointments[i]->print(cout);
		}
		cout << endl;
	}
}

void Schedule::print_week() const
{
		// Nearly the same as above except having the number provided by the user
		// we use a loop to go through all the numbers of the week (0-6)
	int size = m_appointments.size();
	for (int k = 0; k < 7; k++)
	{
		string isday = day_name(k);
		cout << isday << ":" << endl;
		for(int i = 0; i < size; i++)
		{
			bool doesoccur = m_appointments[i]->occurs(k);
			if (doesoccur == true)
			{
				cout << i << "   ";
				m_appointments[i]->print(cout);
			}
			cout << endl;
		}
	}
}