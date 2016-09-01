/* Dylan Wise
 * CS 215, Section 001, Spring 2014
 * Programming assignment 2
 * 7 March, 2014
 *
 * Store a set of numbers in an array and compute some statistics
 * such as Mean, Median, Max, Min and current array size
 */

#include <iostream>
#include <sstream>
#include <vector>
#include <string>
#include <cmath>
#include <stdexcept>
#include "pa2.h"

using namespace std;

// TODO: implement all these method stubs!
data_set::data_set()
{
	curr_cap = 10;   // Default constructor creates an array with a capacity of 10 and no elements
	curr_size = 0;
	points = new double[curr_cap]; 
}

data_set::data_set(int initial_capacity)
{
	if (initial_capacity < 0)
		throw runtime_error ("Negative Capacity");  // Alternative constructor creates an array with 
	curr_cap = initial_capacity;                    // a specified size. Does not accept negative sizes
	curr_size = 0;
	points = new double[initial_capacity];
}
data_set::data_set(const data_set &original)
{
	curr_cap = original.curr_cap;                  // Makes a deep copy of the array
	curr_size = original.curr_size;
	points = new double[curr_cap];
	for (int i = 0; i < curr_size; i++)            // A simple assignment operator would be 
			points[i] = original.points[i];        // shallow copy, so you must insert every value
}

data_set &data_set::operator=(const data_set &original)
{
	if (this != &original)
	{
		curr_cap = original.curr_cap;
		curr_size = original.curr_size;   // If this does not already equal the original
		                                  // this method will make it equal to the
		delete[] points;                  // the original

		points = new double[curr_cap];

		for (int i = 0; i < curr_size; i++)   // Like before we must copy the induvidual values
			points[i] = original.points[i];

		return *this;

	}

}

data_set::~data_set()
{
	delete[] points;       // Delete what points was pointing to.
	points = NULL;         // Have it point to null to prevent a dangling pointer, always good practice to include
}

void data_set::insert(double value)
{
	if (curr_size >= curr_cap){                         // If the current size is already equal to the capacity
		double *resized = new double[curr_cap + 1];     // you must construct a new array with one more element of room
		for (int i = 0; i < curr_size; i++)     
			resized[i] = points[i];    // reinsert all of the emements into the new array
		delete[] points;            // delete the old array
		points = resized;         // make points point the new array with the larger size
		curr_cap += 1;            // iterate the capacity
	}


	points[curr_size] = value;   // inserts the new element into last available slot in the array
	curr_size++;                 // iterates the size so overwriting wont happen

	int sortnum;                 // initializes the two variables needed for a selection sort
	double tempnum;
	for (int i = 0; i < curr_size - 1; i++)
	{
		sortnum = i;
		for (int i2 = i + 1; i2 < curr_size; i2++)
		{
			if (points[i2] < points[sortnum])        // sees if current element is the smallest
				sortnum = i2;
		}
		if (sortnum != i)
		{
			tempnum = points[i];              
			points[i] = points[sortnum];       // if the element was the smallest is input into 
			points[sortnum] = tempnum;         // the current index of the first loop (current location in the array)
		}
	}
}

void data_set::print(ostream &out) const
{
	for (int i = 0; i < curr_size; i++)
	{ 
		if (i == 0)
			out << "{ ";
		out << points[i];
		if (i <= curr_size - 2)       // with the way index relates to the actual size of array
			out << ", ";              // you must subtract things in order to have the special elements print
		if (i == curr_size - 1)       // where you wish
			out << " }";
	}

	if (curr_size == 0){      // If there are no elements in the array a special 
		out << "{ }";         // print is called as the for loop above wont work for size 0
	}

	out << endl;
}

int data_set::size() const
{
    return curr_size;        
}

int data_set::capacity() const
{
    return curr_cap;
}

double data_set::mean() const
{
	if (curr_size == 0)
		throw runtime_error("No elements in array");    // There must be elements to have a mean

	double mean_num = 0;
	double total = 0;

	for (int i = 0; i < curr_size; i++){
		total = total + points[i];         // Find the total of all the elements
	}
	mean_num = total/curr_size;

    return mean_num;
}

double data_set::median() const
{
	if (curr_size == 0){
		throw runtime_error("No elements in array");
	}

	double median_num = 0;
	double average1 = 0;
	double average2 = 0;

	if (curr_size%2 == 1){              // With an odd number of elements just need to find the middle member of the array
		median_num = (curr_size/2);                  
		median_num = points[static_cast<int>(median_num)];   // Staic casts are needed due to median_num being a double
	}
	else{
		median_num = curr_size/2.0;     // With an even number the program must find the middle two and find their average
		average1 = points[static_cast<int>(median_num)-1];
		average2 = points[static_cast<int>(median_num)];
		median_num = (average1 + average2)/2;
	}

    return median_num;
}

double data_set::minimum() const
{
	if (curr_size == 0){
		throw runtime_error("No elements in array");
	}
	double minimum_num = points[0];   // Since all the elements are in order the minimum value is the
    return minimum_num;               // first element in the array 100% of the time
	
}

double data_set::maximum() const
{
	if (curr_size == 0){
		throw runtime_error("No elements in array");
	}
	double max_num = points[curr_size-1];   // Since arrays are sorted the max value will 
    return max_num;                         // always be the final element in the array
}

/* main() - Runs a test on the final data set
 *
 * Description: 
 *   Allows the user to input numbers via a loop into
 *   an array that, after the user quits the loop, is
 *   tested for its max, min, mean, median and size
 *
 * Inputs:
 *   Any number of inputs by the user, numbers are expected 
 *   and characters are handled
 *
 * Outputs:
 *   Prints the the array and the final statistics of the array
 *   after the user is done inputing
 *
 * Side-effects:
 *   Prints errors for non-numeric input. An array of nothing
 *   is not accepted
 *
 * Exceptions:
 *   If a called method unexpectedly throws an exception, it will
 *   be passed on (not caught).
 *
 */

int main()
{
    int failed = test_data_set();

    // TODO: Read doubles in a loop and add them to a data set.  Repeat
    //   the loop on invalid input, then end when the user types "quit".
    //   Print the data set before each prompt.

	cout << "Remember to type 'quit' to stop!" << endl;     // incase somebody other than you or me get ahold
	cout << endl;                                           // of this program...

	data_set last_set;

		while(1)
	{
		last_set.print(cout);               // print the array at the start of each loop before taking in a number
		cout << endl;                       // this way the element from the previous loop will be present in the print
		cout << "Enter a number: ";
			double num;
			cin >> num;
			cout << endl;
			if (cin.fail())                // if a non-number is inputed (that isnt quit) a fail will happen and will reset 
			{                              // the loop
				cin.clear();

				string line;              
				getline(cin, line);        // this removes he line from the buffer so it wont affect cin
				
				if (line == "quit")
					break;                 // however if that line is 'quit' the while is broken, this is the ONLY way to leave the while
				else
					cout << "That's a non-numeric input." << endl;
			}
			else
			{
				last_set.insert(num);      // if the input was legal, that number is inserted into the array which is then printed at the
			}                              // start of the next loop
	}


    // TODO: Print the final data set, and compute its statistics:
    //   size, mean, minimum, maximum, and median.
    
	cout << "The final data set is ";       
	last_set.print(cout);                 // Uses the print method to output the final data set to the console
	cout << endl;
	cout << "The final data set's size is " << last_set.size() << endl;       
	cout << "The final data set's minimum value is " << last_set.minimum() << endl;     // These all print their respective values to the console
	cout << "The final data set's maximum value is " << last_set.maximum() << endl;
	cout << "The final data set's median is " << last_set.median() << endl;
	cout << "The final data set's mean is " << last_set.mean() << endl;

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


int test_data_set()
{
    // Current test number.  Be sure to increment this before each test!
    int curr_test = 0;

    // Number of failed tests.
    int failed = 0;
    
    cerr << "Testing..." << endl;

    // Test 1: does the default constructor create an empty data set?
    //   Tests: default constructor, size method
    curr_test++;
    data_set empty;
    if (empty.size() != 0) {
        cerr << "Test " << curr_test << " failed: size is "
             << empty.size() << ", should be 0." << endl;
        failed++;
    }

    // Test 2: does the default constructor set the capacity correctly.
    //   Tests: default constructor, capacity method
    curr_test++;
    if (empty.capacity() != 10) {
        cerr << "Test " << curr_test << " failed: capacity is "
             << empty.capacity() << ", should be 10." << endl;
        failed++;
    }

    // Test 3: does the integer constructor work?
    //   Tests: int constructor, capacity method.
    curr_test++;
    data_set tiny(1);
    if (tiny.capacity() != 1) {
        cerr << "Test " << curr_test << " failed: capacity is "
             << tiny.capacity() << ", should be 10." << endl;
        failed++;
    }

    // Test 4: and is that data set empty, too?
    //   Tests: int constructor, size method.
    curr_test++;
    if (tiny.size() != 0) {
        cerr << "Test " << curr_test << " failed: size is "
             << tiny.size() << ", should be 0." << endl;
        failed++;
    }

    // Test 5: can we insert?
    //   Tests: int constructor, insert and size methods.
    curr_test++;
    data_set working(2);
    working.insert(4.5);
    if (working.size() != 1) {
        cerr << "Test " << curr_test << " failed: size is "
             << working.size() << ", should be 1." << endl;
        failed++;
    }

    // Test 6: can we insert over the current capacity?
    //   Tests: int constructor, insert and size methods.
    curr_test++;
    working.insert(5.5);
    working.insert(3.5);
    if (working.size() != 3) {
        cerr << "Test " << curr_test << " failed: size is "
             << working.size() << ", should be 3." << endl;
        failed++;
    }
    
    // Test 7: did that update the capacity?
    //   Tests: int constructor, insert and capacity methods.
    curr_test++;
    if (working.capacity() < 3) {
        cerr << "Test " << curr_test << " failed: capacity is "
             << working.capacity() << ", should be at least 3." << endl;
        failed++;
    }

    // Test 8: does the vector print in order and with the correct
    //         formatting?
    //   Tests: int constructor, insert and print methods.
    //   Uses an ostringstream to capture the output.
    curr_test++;
    ostringstream out;
    working.print(out);
    string expected = "{ 3.5, 4.5, 5.5 }\n";
    if (out.str() != expected) {
        cerr << "Test " << curr_test << " failed:" << endl;
        cerr << "Actual output:   " << out.str() << endl;
        cerr << "Expected output: " << expected << endl;
        failed++;
    }

    // Test 9: does the copy constructor faithfully copy?
    //   Tests: copy constructor and print methods.
    curr_test++;
    data_set copy(working);
    ostringstream out_copy;
    copy.print(out_copy);
    if (out_copy.str() != out.str()) {
        cerr << "Test " << curr_test << " failed:" << endl;
        cerr << "Original: " << out.str() << endl;
        cerr << "Copy:     " << out_copy.str() << endl;
        failed++;
    }
    
    // Test 10: did it do a deep copy?  Changing the copy shouldn't change
    //          the original.
    //   Tests: copy constructor, insert and print methods.
    curr_test++;
    copy.insert(2.0);
    
    ostringstream out_orig;
    working.print(out_orig);
    if (out_orig.str() != expected) {
        cerr << "Test " << curr_test << " failed:" << endl;
        cerr << "Actual output:   " << out_orig.str() << endl;
        cerr << "Expected output: " << expected << endl;
        failed++;
    }

    // Test 11: does the assignment operator change the size?
    //   Tests: assignment operator, size method.
    curr_test++;
    tiny = working;
    if (tiny.size() != 3) {
        cerr << "Test " << curr_test << " failed: size is "
             << tiny.size() << ", should be 3." << endl;
        failed++;
    }
    
    // Test 11: did the assignment operator copy the values?
    //   Tests: assignment operator, print method.
    curr_test++;
    ostringstream out_tiny;
    working.print(out_tiny);

    if (out_tiny.str() != out_orig.str()) {
        cerr << "Test " << curr_test << " failed:" << endl;
        cerr << "Original: " << out_orig.str() << endl;
        cerr << "Copy:     " << out_tiny.str() << endl;
        failed++;
    }
    
    // Test 12: did it do a deep copy?
    //   Tests: assignment operator, insert and print methods.
    curr_test++;
    tiny.insert(9.0);
    
    ostringstream out_orig2;
    working.print(out_orig2);

    if (out_orig2.str() != expected) {
        cerr << "Test " << curr_test << " failed:" << endl;
        cerr << "Actual output:   " << out_orig2.str() << endl;
        cerr << "Expected output: " << expected << endl;
        failed++;
    }
    
    // Test 13: does minimum() work?
    //   Tests: insert and minimum methods
    curr_test++;
    if (working.minimum() != 3.5) {
        cerr << "Test " << curr_test << " failed: got "
             << working.minimum() << ", expected 3.5." << endl;
        failed++;
    }
    
    // Test 14: does minimum throw an exception on an empty
    //          vector?
    //   Tests: empty constructor, minimum method
    curr_test++;

    bool caught = false;
    // We need a try/catch because we expect an exception.
    try {
        double x = empty.minimum();
    } catch (exception e) {
        caught = true;
    }
    if (!caught) {
        cerr << "Test " << curr_test << " failed: missing exception" << endl;
        failed++;
    }

    // TODO: implement two tests each for mean, maximum, and median.

    // Test 15: does mean() work?
	// tests insert and mean methods
	curr_test++;
    if (working.mean() != 4.5) {
        cerr << "Test " << curr_test << " failed: got "
             << working.mean() << ", expected 4.5." << endl;
        failed++;
    }

	// Test 16: does median() work?
	// tests insert and median methods
	curr_test++;
    if (working.median() != 4.5) {

        cerr << "Test " << curr_test << " failed: got "
             << working.median() << ", expected 4.5." << endl;
        failed++;
    }

	// Test 17: does maximum() work?
	// tests insert and maximum methods
	curr_test++;
    if (working.maximum() != 5.5) {

        cerr << "Test " << curr_test << " failed: got "
             << working.maximum() << ", expected 5.5." << endl;
        failed++;
    }

	// Test 18 does median work with an even number of elements?
	// tests insert and median methods

	data_set custom_test(1);
	custom_test.insert(2.5);
	custom_test.insert(3.5);
	custom_test.insert(7.5);
	custom_test.insert(6.0);
	curr_test++;
    if (custom_test.median() != 4.75) {

        cerr << "Test " << curr_test << " failed: got "
             << custom_test.median() << ", expected 4.75." << endl;
        failed++;
    }

	// Test 19: does maximum() work with one element
	// tests insert and maximum methods
	curr_test++;
	data_set test2(1);
	test2.insert(5);
    if (test2.maximum() != 5) {

        cerr << "Test " << curr_test << " failed: got "
             << test2.maximum() << ", expected 5." << endl;
        failed++;
    }

	// Test 20: does mean() work with one element?
	// tests insert and mean methods
	curr_test++;
    if (test2.mean() != 5) {
        cerr << "Test " << curr_test << " failed: got "
             << test2.mean() << ", expected 5." << endl;
        failed++;
    }

    // If you are doing the bonus, remember the five test cases for remove!


    if (failed == 0)
    {
        cerr << "All tests passed." << endl;
    }

    // Add an extra blank line after the tests.
    cerr << endl;

    return 0;
}