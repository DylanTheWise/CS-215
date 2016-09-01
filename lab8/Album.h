#ifndef LAB8_H
#define LAB8_H

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include <exception>

using namespace std;

class Album 
{
    public:
		Album(string artist, string album, int year);
		string get_artist() const;
		string get_album() const;
		int get_year() const;
		void print(ostream &out) const;

    private:
		string m_artist;
		string m_album;
		int m_year;

};
#endif