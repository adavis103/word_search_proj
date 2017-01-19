/*
Alexander Davis
CSCE 121-200
Word Search Project Play_window CPP

Description: Establishes Play_window class which creates a grid of buttons from which player will
create words from and try to get a high score.
*/

#include "Play_window.h"
#include "dictionary.h"
#include <unistd.h>

void append_file(Person p) {
	ofstream ofs;
	ofs.open("player_data.txt", ios::out | ios::app);
	ofs << p.get_name() << endl << p.get_score() << endl << p.get_file_name() << endl;
}

// takes a number and generates a random uppercase letter as a string
string genRandom(unsigned int x){
	srand(time(NULL)+x);
    int n = rand() % 26;
    char c = (char)(n+65);
	
	stringstream ss;
	string s;
	ss << c;
	ss >> s;
	return s;
}

// creates a square grid of buttons of specified size and pushes these into the vector passed
// in by reference
void Play_window::vector_of_buttons(int size, vector<Button*>& vl){
	for (int i = 0; i < size; ++i){
		for (int j = 0; j < size; ++j){
			if (i == 0 && j == 0) { // ensure there is always an "E" in grid
				vl.push_back(new Button(Point(20+i*40,20+j*40),40,40,"E",cb_letter));
			}
			else {
				vl.push_back(new Button(Point(20+i*40,20+j*40),40,40,genRandom(rand()),cb_letter));
			}
			attach(*vl[vl.size()-1]); //attach to window the current button object we add to the vector
		}
	}
}

// constructor:
Play_window::Play_window(Point xy, int w, int h, const string& title, int dimensions, Person& p):

	// initialization
	Window(xy,w,h,title),
	next_player_button(
	    Point(x_max()-90,45),    			// location of button
	    90, 20,                  			// dimensions of button
	    "Next Player",          			// label of button
	    cb_next_player),         			// callback function for button
	quit_button(							
		Point(x_max()-90,20),				// Same structure
		90, 20,
		"Quit",
		cb_quit),
	display_button(							
		Point(x_max()-90,70),				
		90, 20,
		"High Scores",
		cb_display),
	backspace_button(
		Point(360,y_max()-60), 
			90, 20,       
			"Backspace",        
			cb_backspace), 
	clear_button(
		Point(360,y_max()-35),
		90, 20,         
			"Clear",
			cb_clear),        
	enter_button(
		Point(360,y_max()-85),   
			90, 20,       
			"Enter",    
			cb_enter),       
	running_word(
		Point(100,y_max()-85),              // location of box
		250, 20,                    		// dimensions of box
		"running word:"),          			// label of box
	error_box(
		Point(100,y_max()-60),   			// Same structure
		250, 45,       
		"output box:"),     
	word_list(
		Point(100,y_max()-120), 
		350, 20, 
		"words entered:"),
	player(p)

// ---------end constructor arguments, etc.-------------

  // body of constructor
{
	// attach buttons and boxes to window
	vector_of_buttons(dimensions,v_letters);
	attach(next_player_button);
	attach(quit_button);
	attach(display_button);
	attach(backspace_button);
	attach(clear_button);
	attach(enter_button);
	attach(running_word);
	attach(error_box);
	attach(word_list);
}


// -------------end constructor---------------

// callback function for quit button - boilerplate:
void Play_window::cb_quit(Address, Address pw) {
  reference_to<Play_window>(pw).quit();   // quit is defined next
}

// what to do when quit button is pressed
void Play_window::quit() {
  hide();                   // FLTK idiom for delete window
}

// ----------------------------

// callback function for next player button - boilerplate:
void Play_window::cb_next_player(Address, Address pw) {
  reference_to<Play_window>(pw).next_player();  // next_player is defined next
}

// what to do when next player button is pressed
void Play_window::next_player() {
	append_file(player);
	hide();
	Init_window win(Point(0,0), 475, 175, "Word Search Project");
	gui_main();
}

// ----------------------------

// callback function for display scores button - boilerplate:
void Play_window::cb_display(Address, Address pw) {
  reference_to<Play_window>(pw).display_scores();  // display_scores is defined next
}

// what to do when next player button is pressed
void Play_window::display_scores() {
	append_file(player);
	hide();
	End_window win(Point(0,0), 600, 600, "Word Search Project"); // open new window
	gui_main();
}

// ----------------------------

// callback function for clear button - boilerplate:
void Play_window::cb_clear(Address, Address pw) {
	reference_to<Play_window>(pw).clear();   // clear is defined next
}

// what to do when clear button is pressed
void Play_window::clear() {
	word = "";                   // make word empty string
	running_word.put(word);
}

// ----------------------------

// callback function for backspace button - boilerplate:
void Play_window::cb_backspace(Address, Address pw) {
	reference_to<Play_window>(pw).backspace();   // backspace is defined next
}

// what to do when backspace button is pressed
void Play_window::backspace() {
	if (addresses.size() != 0) {
		addresses[addresses.size()-1]->activate();
		addresses.pop_back();
	}
	if (word.size() != 0) {
		word.pop_back();                   // remove last character
		running_word.put(word);
	}
}

// ----------------------------

// callback function for enter button - boilerplate:
void Play_window::cb_enter(Address, Address pw) {
	reference_to<Play_window>(pw).enter();   // enter is defined next
}

// what to do when backspace button is pressed
void Play_window::enter() {
	vector<string> words = read_dictionary();
	bool match = is_word(word, words);
	
	if (!is_unique(word)) {
		error_box.put("Word already entered");
	}
	else if (match) {
		words_entered.push_back(word);
		add_word();
		player.increment();
		stringstream ss;
		ss << "Point added. Current score: " << player.get_score();
		
		error_box.put(ss.str()); // display current score
	}
	else {
		error_box.put("Word not found in dictionary");
	}
	
	if (addresses.size() != 0) {
		for (unsigned int i = 0; i < addresses.size(); i++){
			addresses[i]->activate();
		}
	}
	
	clear();
}

// -------------------------------

// callback for when letter button is pressed - boilerplate
void Play_window::cb_letter(Address flbp, Address pw) {
	reference_to<Play_window>(pw).add_address((Fl_Button*)(flbp));
	
	string letter = ((Fl_Button*)(flbp))->label();
	((Fl_Button*)(flbp))->deactivate();
	reference_to<Play_window>(pw).letter_pressed(letter);
} 

// letter_pressed defined in Play_window class as part of declaration
