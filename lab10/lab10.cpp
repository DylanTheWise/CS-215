// Dylan Wise
// CS 215, Section 001, Fall 2014
// Lab 10
// 4/2/2014
#include <iostream>
#include <string>

using namespace std;


// Prototypes
void pause_215(bool have_newline);
string reverse_rec(const string &str);
int Tribonacci (int n);
// Define your global variable here.
int Trib_count;
// Implement your recursive functions here.

string reverse_rec(const string &str)
{
	int length = str.length();
	if (length == 0) return " ";
	return str[length-1] + reverse_rec(str.substr(0, length-1));
}

int Tribonacci (int n)
{
	Trib_count++;
	if (n <=2) return 1;

	return Tribonacci (n-1) + Tribonacci(n-2) + Tribonacci (n-3);
}

int main()
{
	// TODO: prompt the user for a string, reverse it using your
	// recursive function, and print both the original and reversed
	// string.
	string test_str;
	cout << "Please enter the string you wish to reverse " << endl;
	cin >> test_str;
	string reverse_str = reverse_rec(test_str);
	cout << "Original = " << test_str << endl;
	cout << "Reversed = " << reverse_str << endl;
	
	// TODO: prompt the user for a number n, use your recursive
	// function to calculate the nth Tribonacci number, and
	// print both the result and the global variable measuring
	// the number of recursive calls.
	cout << endl;

	int num;
	cout << "Please enter an n for your Tribonacci sequence " << endl;
	cin >> num;
	cout << Tribonacci(num) << " ";
	cout << Trib_count << endl;

	pause_215(true);
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