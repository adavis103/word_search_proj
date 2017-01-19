/* Tristan Partin
 * CSCE 121-200
 *
 * Pupose: declare the Init_window class
 */

#ifndef INIT_WINDOW_H
#define INIT_WINDOW_H

#include "Window.h"
#include "GUI.h"
#include "Point.h"
#include "std_lib_facilities_4.h"
#include "Person.h"
#include "Play_window.h"
#include <sys/stat.h>

using namespace Graph_lib;
using namespace std;

class Init_window : public Graph_lib::Window
{
private:
	//member variables
	In_box name_box;
	In_box image_box;
	Menu dimensions;
	Button quit_button;
	Button play_button;

	int board_size;

	//member functions
	void create_file();

	void play();
	void quit();

	void three_pressed();
	void four_pressed();
	void five_pressed();

	static void cb_3(Address, Address);
	static void cb_4(Address, Address);
	static void cb_5(Address, Address);

	static void cb_quit(Address, Address);
	static void cb_play(Address, Address);

public:
	//constructor
	Init_window(Point xy, int dx, int dy, const string& title);
};

#endif
