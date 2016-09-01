// CS 215, Spring 2014
// Lab 12
// 16-18 April, 2014
#include <iostream>
#include "position.h"
#include "positionlist.h"
using namespace std;

void pause_215(bool have_newline);

// Perform fifteen tests of the PositionList class, reporting the results.
int main()
{
	int failed_count = 0;

	// Create a new list with the default constructor.
	PositionList test_list;
	//
	if (!test_list.empty()) {
		cerr << "Failed test 1: default list is not empty." << endl;
		failed_count++;
	} else
		cout << "Passed test 1." << endl;

	if (test_list.size() != 0) {
		cerr << "Failed test 2: default list size is " << test_list.size()
		     << ", not zero." << endl;
		failed_count++;
	} else
		cout << "Passed test 2." << endl;

	// Try an out-of-bounds get.
	Position p = test_list.get(0);
	if (p.x() != -1 || p.y() != -1) {
		cerr << "Failed test 3: out-of-bounds get should return Position(-1,-1)."
		     << endl;
		failed_count++;
	} else
		cout << "Passed test 3." << endl;

	test_list.push_front(Position(1, 2));
	test_list.push_front(Position(3, 4));
	if (test_list.empty()) {
		cerr << "Failed test 4: list is still empty after pushing." << endl;
		failed_count++;
	} else
		cout << "Passed test 4." << endl;

	if (test_list.size() != 2) {
		cerr << "Failed test 5: list size is " << test_list.size()
		     << ", should be 2." << endl;
		failed_count++;
	}
	 else
		cout << "Passed test 5." << endl;

	p = test_list.get(0);
	if (p.x() != 3 || p.y() != 4) {
		cerr << "Failed test 6: get(0) returned  (" << p.x() << "," << p.y() << ")"
		     << ", should be (3, 4)" << endl;
		failed_count++;
	} else
		cout << "Passed test 6." << endl;

	p = test_list.get(1);
	if (p.x() != 1 || p.y() != 2) {
		cerr << "Failed test 7: get(1) returned  (" << p.x() << "," << p.y() << ")"
		     << ", should be (1, 2)" << endl;
		failed_count++;
	} else
		cout << "Passed test 7." << endl;

	test_list.pop_front();
	if (test_list.size() != 1) {
		cerr << "Failed test 8: list size is " << test_list.size()
		     << " after popping, should be 1." << endl;
		failed_count++;
	} else
		cout << "Passed test 8." << endl;

	p = test_list.get(0);
	if (p.x() != 1 || p.y() != 2) {
		cerr << "Failed test 9: get(0) returned  (" << p.x() << "," << p.y() << ")"
		     << ", should be (1, 2)" << endl;
		failed_count++;
	} else
		cout << "Passed test 9." << endl;

	test_list.pop_front();
	if (!test_list.empty()) {
		cerr << "Failed test 10: list should be empty after popping." << endl;
		failed_count++;
	} else
		cout << "Passed test 10." << endl;

	// End of the basic tests (Part 1)
	if (failed_count == 0) {
		cout << "Congratulations, you passed tests 1 through 10!" << endl;
		cout << "  Part 1 appears to be finished!" << endl;
	}

	cout << endl << "Proceeding to part 2 tests." << endl;
	pause_215(false);

	// The lists declared inside this block will be destroyed when the block ends,
	// testing the destructors.
	{
		// Now test the copy constructors.
		PositionList empty_copy(test_list);
		if (!empty_copy.empty()) {
			cerr << "Failed test 11: copy of an empty list is not empty." << endl;
			failed_count++;
		} else
			cout << "Passed test 11." << endl;


		test_list.push_front(Position(5, 6));
		test_list.push_front(Position(7, 8));
		PositionList copy(test_list);
		Position q = copy.get(0);
		if (q.x() != 7 || q.y() != 8) {
			cerr << "Failed test 12: copy had the wrong first element." << endl;
			failed_count++;
		} else
			cout << "Passed test 12." << endl;

		test_list.pop_front();
		q = copy.get(0);
		if (q.x() != 7 || q.y() != 8) {
			cerr << "Failed test 13: copy had the wrong first element "
			     << " after popping original." << endl;
			failed_count++;
		} else
			cout << "Passed test 13." << endl;

		PositionList assign;
		assign.push_front(Position(9, 10));
		assign = copy;
		if (assign.size() != copy.size()) {
			cerr << "Failed test 14: wrong size " << assign.size()
			     << " after assignment, should be " << copy.size()
			     << "." << endl;
			failed_count++;
		} else
			cout << "Passed test 14." << endl;
	}

	cout << "Passed test 15: program didn't crash in destructors." << endl;

	cout << endl;

	if (failed_count == 0) {
		cout << "Congratulations, you passed all the tests!" << endl;
	} else {
		cout << "Your code still fails " << failed_count << " out of 15 tests" << endl;
	}

	pause_215(false);
	return(0);
}
/* pause_215() - Wait for the user to press ENTER.
 *
 * Description: 
 *   Optionally read and discard the remainder of the user's last
 *   line of input.  Then, prompt the user to press ENTER, then
 *   read and discard another line of input.
 *
 * Inputs:
 *   bool have_newline:
 *     True if the user has already entered a newline that the
 *     program has not yet read.  If true, this function first
 *     discards remaining input up to and including that newline.
 *
 *   Reads two lines from standard input if have_newline is true,
 *   one line if it is false.  Lines are assumed to be less than
 *   two hundred characters long.
 *
 * Outputs:
 *   No return value.
 *
 *   Prints a prompt to standard output.
 *
 * Notes:
 *   This function is intended to be used at the end of a program,
 *   just before returning from main().  Reading another line of
 *   input prevents the console window from closing immediately.
 *
 *   In general, have_newline should be true if the last user input
 *   from cin used the extraction operator (>>), and false if there
 *   has been no user input or if the last input used getline().
 */
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
