#include <iostream>
#include <string>
#include <vector>
#include <exception>
#include "Album.h"

using namespace std;

Album::Album(string artist, string album, int year)
{
	m_artist = artist;
	m_album = album;
	m_year = year;
}  

string Album::get_artist() const
{
	return m_artist;
}

string Album::get_album() const
{
	return m_album;
}

int Album::get_year() const
{
	return m_year;
}

void Album::print(ostream &out) const
{
	out << m_artist << ", _" << m_album << "_ (" << m_year << ")." << endl;
}
