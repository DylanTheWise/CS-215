#include <iostream>
#include <list>
#include <string>
using namespace std;
void pause_215(bool have_newline);

list<string>::iterator find_smallest(list<string>::iterator begin,
                                     list<string>::iterator end)
{
    // TODO: loop from begin to end and return an iterator pointing
    // to the smallest element.
	list<string>::iterator smallest = begin;

	for (list<string>::iterator curr = begin; curr != end; curr++)
	{
		if (*smallest > *curr)
			smallest = curr;
	}
    return smallest;
}

void selection_sort(list<string> &l)
{
    // TODO: sort the list using selection sort, looping over the
    // list and swapping using iterators.

	list<string>::iterator curr;
	for (curr = l.begin(); curr != l.end(); curr++)
	{
		list<string>::iterator smallest = find_smallest(curr, l.end());

		if (smallest != curr)
		{
			string tmpstring = *smallest;
			*smallest = *curr;
			*curr = tmpstring;
		}
	}



}

int main()
{
    list<string> inputs;

    cout << "Please enter a list of strings, one per line." << endl;
    cout << "Press <ENTER> on a line by itself to stop." << endl;

    // Read some strings until the user presses enter by itself.
    // If there is an error with cin, also stop the loop.
    while (cin)
    {
        string str;
        getline(cin, str);

        // Exit the loop on an empty line.
        if (str == "")
            break;

        inputs.push_back(str);
    }

    list<string>::iterator smallest = find_smallest(inputs.begin(), inputs.end());
    cout << "The smallest element is: " << *smallest << endl;

    selection_sort(inputs);

    cout << "Sorted alphabetically, that is:" << endl;
    for (list<string>::iterator it = inputs.begin(); it != inputs.end(); it++)
    {
        cout << *it << endl;
    }

    // Use false because we last used getline.
    pause_215(false);
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