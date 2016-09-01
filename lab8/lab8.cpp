// Dylan Wise
// CS 215 Lab 8
// 13 March 2014
//
// TODO: Answer the homework question here:  a. Base = Employee,    Derived = Manager
//                                           b. Base = Polygon,     Derived = Triangle
//                                           c. Base = Student,     Derived = GraduateStudent
//                                           d. Base = Person,      Derived = Student
//                                           e. Base = Employee,    Derived = Professor
//                                           f. Base = BankAccount, Derived = CheckingAccount
//                                           g. Base = Vehicle,     Derived = Car
//                                           h. Base = Vehicle,     Derived = Minivan
//                                           i. Base = Car,         Derived = Minivan
//                                           j. Base = Vehicle,     Derived = Truck                                                 
//
// R10.1 (10 pts, 1 each):
// Identify the base class and the derived class in each of the following
// pairs of classes.
// a. Employee, Manager
// b. Polygon, Triangle
// c. GraduateStudent, Student
// d. Person, Student
// e. Employee, Professor
// f. BankAccount, CheckingAccount
// g. Vehicle, Car
// h. Vehicle, Minivan
// i. Car, Minivan
// j. Truck, Vehicle

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include <exception>
#include "Album.h"
// TODO: create and include a header file for the Album class.
// TODO: also create a source file for Album's implementation.
using namespace std;

// Prototypes for non-member functions.
void pause_215(bool have_newline);
vector<Album> read_album_file(string filename);
Album parse_album(string line);


int main()
{
	// TODO: create an Album object representing your favorite
	// album, and display it.

	string album = "\"Weird Al\" Yankovic";
	string artist = "\"Weird Al\" Yankovic";
	int year = 1983;

	Album test(artist, album, year);

	test.print(cout);

	// TODO: Prompt for a filename, read a vector a Albums from
	// that file, and print each album (in a loop)

	bool yes = false;
	while (yes == false)
	{
		try{

			string filename;
			cout << "Please enter a file name: ";
			cin >> filename;

			vector<Album> vec_album = read_album_file(filename);

			for (int i = 0; i < vec_album.size(); i++)
				vec_album[i].print(cout);

			yes = true;
		}
		catch(runtime_error &e)
		{
			cout << "Error: " <<e.what() << endl;
		}
	}
	pause_215(true);
	return 0;
}

// Other non-member functions.
void pause_215(bool have_newline)
{
	if (have_newline) {
		// Ignore the newline after the user's previous input.
		cin.ignore(200, '\n');
	}

	// Prompt for the user to press ENTER, then wait for a newline.
	cout << endl << "Press ENTER to continue." << endl;
	cin.ignore(200, '\n');
}

// TODO: write a function to parse a line from albums.txt
// and make an Album object.
// Album parse_album(string line) {...}

Album parse_album(string line)
{
	 // Find the index of the first semicolon.
     const int first_sc = line.find(';');
     if (first_sc == string::npos) 
	 {
         throw runtime_error("Error: missing semicolon in " + line);
	 }

     // Everything up to but not including the first semicolon.
     string artist = line.substr(0, first_sc);

	 // Find the index of the second semicolon (start after the first one).
     const int second_sc = line.find(';', first_sc + 1);
     if (second_sc == string::npos) 
	 {
         throw runtime_error("Error: missing semicolon in " + line);
     }
	  // Start after the first semicolon, include characters between the two.
      string name = line.substr(first_sc + 1, second_sc - (first_sc + 1));
	  // Start after the second semicolon, include everything up to the end.
      string year = line.substr(second_sc + 1);

	 istringstream year_stream(year);
     int year_number;
     year_stream >> year_number;

     if (year_stream.fail()) 
	 {
           throw runtime_error("Error: invalid year: " + year);
     }

	 Album new_album(artist, name, year_number);
     return new_album;

}

// TODO: write a function to take a filename, read lines from
// a file, parse them into Album objects, and return a vector
// the results.
// vector<Album> read_album_file(string filename) {...}

vector<Album> read_album_file(string filename)
{
	ifstream infile;
	infile.open(filename.c_str());

	if (!infile.good())
		throw runtime_error("Error opening file.");

	vector<Album> vec_album;
	string line;

	while(getline(infile, line))
		vec_album.push_back(parse_album(line));

	infile.close();
	
	return vec_album;
}
