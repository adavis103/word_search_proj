/* Tristan Partin
 * CSCE 121-200
 *
 * Pupose: define the manipulation a dicitonary file using a vector of strings
 */

#include "dictionary.h"

//reads in the dictionary file to return a vector of strings
vector<string> read_dictionary()
{
	vector<string> dictionary;
	ifstream ifile = ifstream("wordsEn.txt");
	while(ifile.good())
	{
		string word;
		getline(ifile, word);
		if(!word.empty())
		{
			dictionary.push_back(word);
		}
	}
	return dictionary;
}

//checks to see if a word is in a vector of strings
bool is_word(string& word, vector<string>& dictionary)
{
	for(unsigned int i = 0; i < dictionary.size(); i++)
	{
		if(word == dictionary[i])
		{
			return true;
		}
	}
	return false;
}
