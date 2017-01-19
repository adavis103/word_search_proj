/* Tristan Partin
 * CSCE 121-200
 *
 * Pupose: define the Init_window class
 */

#include "Init_window.h"

Init_window::Init_window(Point xy, int dx, int dy, const string& title) : Window(xy, dx, dy, title),
	name_box(Point(50, 25), 175, 30, "Name"),
	image_box(Point(170, 60), 205, 30, "Path to Image"),
	dimensions(Point(225, 25), 75, 30, Menu::horizontal, "Board Size"),
	play_button(Point(225, 100), 150, 50, "Play", cb_play),
	quit_button(Point(75, 100), 150, 50, "Quit", cb_quit)
{
	//attaches all widgets to the window
	attach(name_box);
	attach(image_box);
	dimensions.attach(new Button(Point(0, 0), 0, 0, "3 x 3", cb_3));
	dimensions.attach(new Button(Point(0, 0), 0, 0, "4 x 4", cb_4));
	dimensions.attach(new Button(Point(0, 0), 0, 0, "5 x 5", cb_5));
	attach(dimensions);
	attach(quit_button);
	attach(play_button);
	play_button.hide();

	board_size = 0;
}

//creates the output file
void Init_window::create_file()
{
	ofstream out("player_data.txt");
}

//what to do when quit is pressed
void Init_window::quit()
{
	hide();
}

//what to do when play is pressed
void Init_window::play()
{
	string file_name = "player_data.txt";	//string for a file name
	struct stat buf;
	if(stat(file_name.c_str(), &buf) == -1)	//checks to see if file exists
	{
		create_file();	//create the file
	}
	string file = image_box.get_string();	//gets the string off the box
	if(file == "")	//creates the default image path
	{
		file = "blank.jpg";
	}
	Person player = Person(name_box.get_string(), file);	//creates a player
	hide();	//destroys the window
	Play_window win(Point(0,0), 460, 400, "Word Search Project", board_size, player);	//creates a Play_window
	gui_main();
}

//what to do when 3 is pressed
void Init_window::three_pressed()
{
	board_size = 3;
	play_button.show();	//show the play window
}

//what to do when 4 is pressed
void Init_window::four_pressed()
{
	board_size = 4;
	play_button.show();	//show the play window
}

//what to do when 5 is pressed
void Init_window::five_pressed()
{
	board_size = 5;
	play_button.show();	//show the play window
}

//callback for 3x3 button
void Init_window::cb_3(Address, Address pw)
{
	reference_to<Init_window>(pw).three_pressed();
}

//callback for 3x3 button
void Init_window::cb_4(Address, Address pw)
{
	reference_to<Init_window>(pw).four_pressed();
}

//callback for 3x3 button
void Init_window::cb_5(Address, Address pw)
{
	reference_to<Init_window>(pw).five_pressed();
}

//callback for quit button
void Init_window::cb_quit(Address, Address pw)
{
	reference_to<Init_window>(pw).quit();
}

//callback for play button
void Init_window::cb_play(Address, Address pw)
{
	reference_to<Init_window>(pw).play();
}
