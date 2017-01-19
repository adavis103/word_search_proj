/*
Stern McGee
CSCE 121-200
Word Search Project End_window header

Description:
Last window of word search program that displays a window of players and scores.
*/
#ifndef End_window_H
#define End_window_H

#include "Point.h"
#include "Graph.h"
#include "GUI.h"
#include "Window.h"
#include "Init_window.h"
#include "Person.h"

using namespace Graph_lib;

struct End_window : Graph_lib::Window
{
	End_window(Point xy, int w, int h, const string& title);		//end window constructor
	string image_name;
	string winner_name;
	int high_score = 0;
	vector<Person> players;
	Vector_ref<Text> scoreboard;
	stringstream winstream;

private:
	Button play_again_button;
	Button quit_button;
	Text players_label;
	Text scores_label;
	Text winner_label;

	static void cb_play_again(Address, Address);		//callback function for play_again()
	static void cb_quit(Address, Address);				//callback function for quit()

	void input_data(vector<Person>& players);		//inputs data from data file of player info into vector of Persons
	void play_again();			//returns program to first Initial Window

	void quit() { hide(); }			//exits GUI


	};	

#endif
