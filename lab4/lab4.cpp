#include <iostream>
#include <vector>
#include <string>
#include "lab4.h"
using namespace std;

int main()
{
	vector<int> numstore = vector_create();
	print_vec(numstore);
	vec_reverse(numstore);
	print_vec(numstore);
	pause_215(false);
}

vector<int> vector_create()
{
	bool stop = false;
	vector<int> numstore;
	int num_to_store = 0;
	cout << "Please enter a sequence of numbers: " << endl;
	do {
		cin >> num_to_store;
		if (cin.fail())
		{
			cin.clear();
			string errorline;
			getline(cin, errorline);
			if (errorline == "quit")
				stop = true;
			else
				cout << "Your input is non-numeric. Please enter a number or 'quit' to exit. " << endl;
		}
		else
			numstore.push_back(num_to_store);

	}while(!stop);

	return numstore;
}

void print_vec (vector<int> numstore)
{
	for (int i = 0; i < numstore.size(); i++)
	{
		cout << numstore[i];
		if (i != numstore.size() - 1)
			cout << ", ";
	}
	cout << endl;
}

void vec_reverse (vector<int>& numstore)
{
	for (int i = 0; i < numstore.size() / 2; i++)
	{
		int new_num = numstore[i];
		numstore[i] = numstore[numstore.size() - i - 1];
		numstore[numstore.size() - i - 1] = new_num;
	}
}

void pause_215(bool have_newline)
{
	if (have_newline)
		cin.ignore(200, '\n');
    cout << endl << "Press ENTER to continue." << endl;
    cin.ignore(200, '\n');
}