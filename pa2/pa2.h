#ifndef PA2_H_INCLUDED
#define PA2_H_INCLUDED

#include <vector>
#include <iostream>

using namespace std;

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
 * Outputs:
 *   No return value.
 *
 * Side-effects:
 *   Prints a prompt to standard output.  Reads one or two lines
 *   from standard input.
 *
 * Exceptions:
 *   None.
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
void pause_215(bool have_newline);


/* test_data_set() - Test the data_set class.
 *
 * Description: 
 *   Run a series of tests on the data_set class.  Prints an
 *   error message for each failed test.
 *
 * Inputs:
 *   None.
 *
 * Outputs:
 *   Returns the number of failed tests.
 *
 * Side-effects:
 *   Prints an error message to standard error for each test that
 *   fails.  Also prints a message at the end if all tests passed.
 *
 * Exceptions:
 *   If a called method unexpectedly throws an exception, it will
 *   be passed on (not caught).
 *
 */
int test_data_set();


class data_set
{
public:
    // TODO: Remember to add your method documentation in the class definition.

    // Default constructor: make an empty data set with
    // a capacity of 10.
    data_set();
    // Make an empty data set with the specified capacity.
    // Throws an exception if initial_capacity is negative.
    data_set(int initial_capacity);

    // The Big Three: copy constructor, assignment operator,
    // and destructor.
    data_set(const data_set &original);
    data_set &operator=(const data_set &original);
    ~data_set();
    
    // Return the number of points in the data set.
    int size() const;
    
    // Return the allocated capacity of the data set.
    int capacity() const;

    // Add and remove data points to/from the set.
    // Be sure to reallocate if necessary, and to
    // insert the element in sorted order.
    void insert(double value);

    // Print the set to a stream, with the format:
    //   { value0, value1, value2, ..., valuen }
    void print(ostream &out) const;

    // Calculate various statistics on the set.  All of
    // these throw an exception if the set is empty.
    double mean() const;
    double minimum() const;
    double maximum() const;
    double median() const;

private:
    // Current allocated capacity of the array.
    int curr_cap;
    // Number of elements in use.
    int curr_size;
    // Pointer to a dynamically-allocated array of points.
    double *points;
};

#endif
