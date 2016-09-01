#include <iostream>
#include <string>
#include "Lab5.h"

using namespace std;

int main()
{
	// TODO (step 2): Dynamically allocate an array, and track its
	//  size and capacity.
	double* ptr = new double[2];
	int size = 0;
	int capacity = 2;

	// TODO (step 5): Read numbers in a loop until "quit", adding them
	//  to the array.  Print a message if the array was full, and
	//  print the size and capacity after every iteration.
	while(1)
	{
		cout << endl;
		cout << "Enter a number: ";
			double num;
			cin >> num;

			if (cin.fail())
			{
				cin.clear();


				string line;
				getline(cin, line);
				
				if (line == "quit")
					break;
				else
					cout << "That's a non-numeric input." << endl;
			}
			else
			{
				bool successful = add_value(num, ptr, size, capacity);

				if (successful)
					cout << num << " was added to the array. The size of the array is " << size << " and the capacity is " << capacity << ". " << endl;

				else
				{
					cout << "The array was full!" << endl;
					ptr = reallocate(ptr, size, capacity);
					successful = add_value(num, ptr, size, capacity);
					cout << num << " was added to the array. The size of the array is " << size << " and the capacity is " << capacity << ". " << endl;
				}
			}
	}

	// TODO (step 6): Have the above loop call your re-allocation
	//  function, and attempt to insert again, if the array was full.
	
	// TODO (step 5): Call your print function after the loop.
	cout << "The contents of the array are: ";
	print_array(ptr, size, cout);

	// TODO (step 2): Free the array.
	delete[] ptr;

	pause_215(true);
	return 0;
}

// TODO: implement a function to print an array to an output stream.
void print_array(double *ptr, int size, ostream &out)
{
	for (int i = 0; i < size; i++)
	{ 
		out << ptr[i];
		if (i <= size - 1)
			out << " ";
	}
	out << endl;
}

// TODO: implement a function to add an element to the end of the array.
bool add_value(double value, double *ptr, int &size, int capacity)
{
	if (size < capacity)
	{
		size++;
		ptr[size - 1] = value;
		return true;
	}
	else
		return false;
}
// TODO: implement a function to reallocate an array.
double* reallocate(double *ptr, int size, int &capacity)
{
	double* nptr = new double[capacity * 2];

	for (int i = 0; i < size; i++)
		nptr[i] = ptr[i];

	capacity = capacity * 2;
	delete[] ptr;

	return nptr;
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