// Dylan
// CS 215, Spring 2014
// Lab 11
// 4/9/14
#include <iostream>
#include <list>
#include <string>
#include <stack>
// Remember your #includes!
using namespace std;

void pause_215(bool have_newline);
bool is_balanced(string input);

int main()
{
	// Part 1:
	// TODO: make a list of integers
	// TODO: read numbers into the list in a loop
	
	list<int> num_list;
	cout << "Please enter a number for the list(enter 0 to exit) " << endl;
	while(1)
	{
		int uinput;
		cin >> uinput;
		if (uinput == 0)
			{break;}

		if (cin.fail())
		{
			cin.clear();
			string clear;
			getline(cin, clear);
			cout << "Non-Numeric input, please input numbers " << endl;
		}
		else
		{
			num_list.push_back(uinput);
		}	
	}

	// TODO: traverse and print the list with an iterator.

	for (list<int>::iterator i = num_list.begin(); i != num_list.end(); i++)
		cout << " " << *i;

	cout << endl;

	// TODO: traverse and print the list with a range-based for loop.

	for(int n : num_list)
		cout << " " << n;

	cout << endl;

	// Part 2:
	// TODO: implement is_balanced() function.
	// TODO: read a line of input
	string line;
	cout << "Please enter a string: ";
	cin >> line;
	// TODO: test and print whether the line is balanced.

	if (is_balanced(line))
		cout << "String is balanced" << endl;
	else
		cout << "String is not balanced" << endl;

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

bool is_balanced(string input)
{
	stack<char> st;

	for (char c : input)
	{
		if (c == '(' || c == '[')
			st.push(c);

		if (c == ')' || c == ']')
		{
			if (st.empty())
				return false;

			if (c == ')' && st.top() == '[' || c == ']' && st.top() == '(')
				return false;

			st.pop();
		}
	}

	if (st.empty())
	{
		return st.empty();
	}

	else
		return false;

}
