#include <iostream>
#include <stdexcept>
#include "lab6.h"

using namespace std;

// Implement your constructors and methods for the rational class here.


rational::rational()
{
	m_numerator = 0;
	m_denominator = 1;
}

rational::rational(int numerator, int denominator)
{
	m_numerator = numerator;
	m_denominator = denominator;

	if(m_denominator == 0)
		throw domain_error("Divide by Zero");
}  

void rational::print(ostream &out) const
{
	out << m_numerator << "/" << m_denominator << endl;
}

// Static_cast to convert to a double
double rational::as_double() const
{
	return static_cast<double>(m_numerator) / m_denominator;
}  

void rational::add(rational r)
{
	m_numerator = m_numerator * r.m_denominator + m_denominator * r.m_numerator;
	m_denominator = m_denominator * r.m_denominator;
}


int main()
{
	// TODO: make and use some rationals.
	rational zero;
	rational half(1, 2);
	rational test(1, 3);
	test.add(half);
	test.add(zero);
	test.print(cout);
	cout << " = " << test.as_double() << endl;


	try{
		rational bad(0, 0);
		cout << "This is in the try body." << endl;
	}
	catch(domain_error &e){
		cout << "Error: " << e.what() << endl;
	}

	cout << "Program terminated." << endl;


	pause_215(false);
	return 0;
}

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