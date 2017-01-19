/*
Alexander Davis
CSCE 121-200
Word Search Project Play_window Header

Description: Establishes Play_window class which creates a grid of buttons from which player will
create words from and try to get a high score. 
*/

#ifndef Play_window_H
#define Play_window_H

#include <iostream>    // for i/o
#include <sstream>     // for string streams
#include "GUI.h"
#include "Graph.h"
#include "Point.h"
#include "Person.h"
#include <FL/Fl_Button.H>
#include "Init_window.h"
#include "End_window.h"

using namespace Graph_lib;
using namespace std;

struct Play_window : Graph_lib::Window {       // inherits from Window

	 // constructor
	Play_window(Point xy,              		// top lefthand corner
			     int w,                		// width
				 int h,                		// height
				 const string& title,   	// label
				 int dimensions,		   	// grid of button dimension
				 Person& player
				 );

	private:
		// data members
		vector<Button*> v_letters;
		vector<string> words_entered;
		vector<Fl_Button*> addresses;
		string word;
		Person& player;

		// widgets:
		Button next_player_button;
		Button quit_button;
		Button backspace_button;
		Button clear_button;
		Button enter_button;
		Button display_button;
		Out_box running_word;
		Out_box error_box;
		Out_box word_list;

	// function members
	// takes a string, always one letter, adds to running word output box
	void add_letter(string letter) {
		word = word + letter;
		running_word.put(word);
	}
	
	// adds word to vector, prints out to word list output box
	void add_word() {
		stringstream ss;
		
		for (int i = 0; i < words_entered.size(); i++){
			ss << words_entered[i] << " ";
		}
		word_list.put(ss.str());
	}
	
	// checks that a word has not already been previously entered, takes a string
	bool is_unique(const string& s){
		for (unsigned int i = 0; i < words_entered.size(); i++){
			if (s == words_entered[i]) {return false;}
		}
		return true;
	}

	// actions invoked by callbacks:
	
	// makes string (one letter) lowercase and uses add_letter to add to running word
	void letter_pressed(string s) {
		add_letter(to_string(char(tolower(s[0]))));
	}
	
	// adds address of FLTK button to vector
	void add_address(Fl_Button* a) {
		addresses.push_back(a);
	}

	void next_player();   // defined in CPP
	void quit();
	void backspace();
	void clear();
	void enter();
	void display_scores();

	void vector_of_buttons(int x, vector<Button*>& vl);

	// callback functions; declared here and defined in CPP.
	static void cb_letter(Address, Address);
	static void cb_next_player(Address, Address);
	static void cb_quit(Address, Address);
	static void cb_clear(Address,Address);
	static void cb_backspace(Address,Address);
	static void cb_enter(Address,Address);
	static void cb_display(Address, Address);
};

#endif