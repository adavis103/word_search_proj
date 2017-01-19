/* Tristan Partin
 * CSCE 121-200
 *
 * Pupose: define the Init_window class
 */

#include "Person.h"

Person::Person(string name)
{
	this->name = name;
	score = 0;
	file_name = "blank.jpg";
}

Person::Person(string name, string file_name)
{
	this->name = name;
	score = 0;
	this -> file_name = file_name;
}

Person::Person(string name, int score)
{
	this -> name = name;
	this -> score = score;
	file_name = "blank.jpg";
}

Person::Person(string name, int score, string file_name)
{
	this -> name = name;
	this -> score = score;
	this -> file_name = file_name;
}

//return the name of the Person
string& Person::get_name()
{
	return name;
}

//increments the score by 1
void Person::increment()
{
	score = score + 1;
}

//return the score of the Person
int& Person::get_score()
{
	return score;
}

//return file name/path for a Person's image
string& Person::get_file_name()
{
	return file_name;
}
