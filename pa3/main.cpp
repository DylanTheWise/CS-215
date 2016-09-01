// Dylan Wise
// CS 215, Spring 2014
// Programming Assignment 3
// 8 April, 2014


#include <stdexcept>
#include <iostream>
#include <istream>
#include <sstream>
#include <exception>
#include <fstream>
#include "helpers.h"
#include "Schedule.h"
#include "Appointments.h"
#include "Daily.h"
#include "Weekly.h"
#include "Task.h"

using namespace std;

int main()
{
	// TODO:
	// 1. Prompt for a schedule file and try to load it as a schedule,
	//    repeating until it succeeds.

		// Initialize the schedule, the filename string and the file variable
	Schedule newfile;
	string filename;
	string line;
	ifstream in_file;
		// a bool that will keep the user in a loop until a file is sucessfully opened
	bool fail = true;
	while (fail == true)
	{
		try{

			cout << "Please enter the name of the schedule file (Press ENTER for an empty Schedule)" << endl;
			getline(cin, filename);

				// If the user inputs a blank string, the user gets to choose a file to create
			if (filename == ""){
				cout << "What do you want to name this new file?" << endl;
				getline(cin, filename);
				in_file.open(filename.c_str());
				fail = false;
			}
			else
			{
				in_file.open(filename.c_str());
					// If the filename does not exist the user must repeat the loop
				if (!in_file.good())
					throw runtime_error("Error opening file. ");
				fail = false;
			
			}
		}
		catch(runtime_error &e)
		{
			cout << "Error: " <<e.what() << "Please enter a valid filename" << endl;
		}
	}
		// If the file is good it opens and goes through each line and adds the appointments
	if (in_file.is_open())
	{
		while( getline (in_file, line) )
		{
			Appointments* app = parse_appointment(line);
			newfile.add(app);
		}
	}

	// 2. In a while loop:
	//    a. Print a prompt.
	//    b. Read a command from the user.
	//    c. Execute the command
	//    d. Repeat until the command was [q]uit
	// Commands include:
	//    Print [w]eekly/[d]aily schedule, [a]dd appointment,
	//    [r]emove appointment, [q]uit
	// Be sure to catch exceptions that the methods might throw!
	newfile.load(filename);
	string uinput;
	int exit = 0;
		// an exit int that can only trip when the user decides to quit
	while(exit == 0)
	{
			// a bool that will stay true if no sucessful input is given
		bool error_bool= true;
		cout << endl;
		cout << "You may view a [W]eekly or [D]aily schedule," << endl;
		cout << "[A]dd a new appointment, [R]emove an appointment," << endl;
		cout <<  "or [Q]uit." << endl;

		getline(cin, uinput);

		if (uinput == "W" || uinput == "w")
		{
				// if the user chooses "w" the weekly print is activated
			newfile.print_week();
			error_bool = false;
		}

		if (uinput == "D" || uinput == "d")
		{
				// if "d" is chosen, a day is prompted, then that day is used for the daily print
			int day = prompt_day();
			newfile.print_day(day);
			error_bool = false;

		}

		if (uinput == "A" || uinput == "a")
		{
				// Another exit int for the appointments add loop
			int exit2 = 0;
			bool error_bool2 = true;
			while (exit2 == 0)
			{
					// another input is taken by the user to decide what appointment to add
				string uinput2;
				cout << "[D]aily, [W]eekly, or [T]ask? " << endl;
				getline(cin, uinput2);
				if (uinput2 == "D" || uinput2 == "d")
				{
						// initilizes all the variables used for the constructor of Daily
					string app_type = "daily";
					string app_label;
					string app_notes;
					string app_place;
					string app_time;

						// Take in an input from the user and assign it to the respective strings
					cout << "What label should I give the appointment? " << endl;
					getline(cin, app_label);

					cout << "Enter notes: " << endl;
					getline(cin, app_notes);

					cout << "Where is this appointment? " << endl;
					getline(cin, app_place);

					cout << "What time? " << endl;
					getline(cin, app_time);

						// create a dynamically allocated daily object with the specified parameters, and then add
					    // it to the appointments vector
					Appointments* Dyptr = new Daily(app_label, app_notes, app_place, app_time);
					newfile.add(Dyptr);
					
						// The two exit variables are changed to confirm success
					error_bool2 = false;
					exit2 = 1;
				}
				if (uinput2 == "W" || uinput2 == "w")
				{
						// initializes all the variables needed for the weekly constuctor
					string app_type = "weekly";
					string app_label;
					string app_notes;
					string app_place;
					string app_time;
					int app_day;

						// takes in the input from the user for the variables
					cout << "What label should I give the appointment? " << endl;
					getline(cin, app_label);

					cout << "Enter notes: " << endl;
					getline(cin, app_notes);

					cout << "Where is this appointment? " << endl;
					getline(cin, app_place);

					cout << "What time? " << endl;
					getline(cin, app_time);

						// for the day we use the prompt_day function which returns a number,
						// corresponding to the day
					app_day = prompt_day();

						// create a dynamically allocated weekly object with the specified parameters, and then add
					    // it to the appointments vector
					Appointments* Wkptr = new Weekly(app_label, app_notes, app_place, app_time, app_day);
					newfile.add(Wkptr);
						// The two exit variables are changed to confirm success
					error_bool2 = false;
					exit2 = 1;
				}
				if (uinput2 == "T" || uinput2 == "t")
				{
						// initializes the variables to be used for the task constructor
					string app_type = "task";
					string app_label;
					string app_notes;
					int app_day;
					int app_duration;

						// takes in input from the user to add to the task constructor
					cout << "What label should I give the appointment? " << endl;
					getline(cin, app_label);

					cout << "Enter notes: " << endl;
					getline(cin, app_notes);

						// calls the prompt_day function to get the day for the task parameter
					app_day = prompt_day();
				
						// an exit variable that doesn't allow the user to continue until a correct duration is given
					int exit4 = 0;
					while (exit4 == 0)
					{
						cout << "How long is this task (in minutes)? " << endl;
						if (cin >> app_duration)
						{
								// if the duration is accepted the task constructor is called with the parameters and 
								// adds it to the appointments vector
							Appointments* Taptr = new Task(app_label, app_notes, app_day, app_duration);
							newfile.add(Taptr);

								// Since cin was used instead of getline we have to clear the buffer
							cin.clear();
							string clear;
							getline(cin, clear);
							cout << endl;

								// all the exit variables are activated to confirm success
							error_bool2 = false;
							exit2 = 1;
							exit4 = 1;
						}
						else
						{
								// if the input was non-numeric we give and error, clear the buffer and try again.
							cout << "Error, invalid duration, use numeric input ONLY." << endl;
							cin.clear();
							string clear;
							getline (cin, clear);
						}
					}

				}
					// if none of the commands match a task we have an error is called and the loop is repeated
				if (error_bool2 == true)
				{
					cout << "Unknown command: " << uinput2 << endl;
					cout << endl; 
				}

			}
				
			error_bool = false;
		}

		if (uinput == "R" || uinput == "r")
		{
				// a new exit varible for loop below
			int exit3 = 0;
			while (exit3 == 0)
			{
					// take the size of the appointments vector and subtract by 1 (to represent index)
				int number_limit = newfile.size()-1;
				int remove_number;
					// show the user what the current index is for the vector and let them input the one they wish to remove
					// or -1 to exit without removing anything
				cout << "Remove which appointment? [0-" << number_limit << "], -1 to cancel]" <<endl;
				cin >> remove_number;

					// if the input was non-numeric call this statement
				if (cin.fail()) 
				{
					cin.clear();
					cout << "Invalid appointment number." << endl;
						//since cin was used as opposed to getline we need to clear the buffer
					string clear;
					getline(cin, clear);
				}
				
					// if the user inputs -1, change success variables, clear buffer and break from the loop
				if (remove_number == -1)
				{
					error_bool = false;
					string clear;
					getline(cin, clear);
					exit3 = 1;
					break;
				}

					// If the index given was valid we call the remove method
				if (remove_number >= 0 && remove_number <= number_limit)
				{
					newfile.remove(remove_number);
						// clear the buffer becuase we went from getline to cin
					string clear;
					getline(cin, clear);

					exit3 = 1;
					error_bool = false;
				}
					// if the index was out of range this is called
				if (remove_number < -1 || remove_number > number_limit)
				{
						// clear the buffer and since the success varibles were not changed we repeat the loop
					cout << "Invalid Index" << endl;
					string clear;
					getline(cin, clear);
				}
			}
		}

			// if "q" is chosen exit the primary loop of the program and head to the exit of the program
		if (uinput == "Q" || uinput == "q")
		{
			error_bool = false;
			exit = 1;
		}

			// if none of the input if statements were tripped we show the user the invalid command and repeat the loop
		if (error_bool == true)
		{
			cout << "Unknown command: " << uinput << endl;
			cout << endl; 
		}
	}
		// call the deconstructor and exit the program
	newfile.~Schedule();
	pause_215(false);
	return 0;
}