/* Tristan Partin
 * CSCE 121-200
 *
 * Pupose: declare the manipulation of a dictionary using a vector of strings
 */

#ifndef DICTIONARY_H
#define DICTIONARY_H

#include "std_lib_facilities_4.h"

using namespace std;

//functions for manipulating a dictionary
vector<string> read_dictionary();
bool is_word(string& word, vector<string>& dictionary);

#endif
