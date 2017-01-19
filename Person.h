/* Tristan Partin
 * CSCE 121-200
 *
 * Pupose: declare the Init_window class
 */

#ifndef PERSON_H
#define PERSON_H

#include "std_lib_facilities_4.h"

using namespace std;

class Person
{
private:
	//parameter that describe a Person
	string name;
	int score;
	string file_name;

public:
	//Constructors
	Person(string name);
	Person(string name, string file_name);
	Person(string name, int score);
	Person(string name, int score, string file_name);

	//member functions
	string& get_name();
	void increment();
	int& get_score();
	string& get_file_name();
};

#endif
