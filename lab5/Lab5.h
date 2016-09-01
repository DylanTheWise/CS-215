#ifndef LAB5_H
#define LAB5_H

#include <iostream>
#include <string>
using namespace std;


void pause_215(bool have_newline);
void print_array(double *ptr, int size, ostream &out);
bool add_value(double value, double *ptr, int &size, int capacity);
double* reallocate(double *ptr, int size, int &capacity);

#endif