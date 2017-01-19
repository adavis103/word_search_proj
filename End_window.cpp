/*
stern McGee
CSCE 121-200
Word Search Project End_window source

Description:
Last window of word search program that displays a window of players and scores.
*/
#include "End_window.h"


End_window::End_window(Point xy, int w, int h, const string& title)
	: Window(xy, w, h, title),
	play_again_button(Point(x_max()-100, 25), 80, 20, "Play Again", cb_play_again),
	quit_button(Point(x_max() - 100, 0), 80, 20, "Quit", cb_quit),
	 players_label(Point(20, 20), "PLAYER"),
	 scores_label(Point(100, 20), "SCORE"),
	 winner_label(Point(200, 250), winstream.str())
{

	input_data(players);        //stores player data from file into vector players

	for (Person p : players)        //loop for storing the winning player's information
	{
		if (p.get_score() > high_score)
		{
			winner_name = p.get_name();
			high_score = p.get_score();
			image_name = p.get_file_name();
			//if (image_name == "") {image_name = "blank.jpg";}
		}
	}

	for (int i = 0; i < players.size() - 1; ++i)		//loop attaches the player names to the window
	{
		scoreboard.push_back(new Text(Point(20, 50 + i * 20), players[i].get_name()));
		scoreboard[scoreboard.size() - 1].set_color(1 + i * 2); //we can also use numbers from 0 to 255 for colors
		attach(scoreboard[scoreboard.size() - 1]); //attach to window the current Text object we add to the vector
	}
	for (int i = 0; i < players.size() - 1; ++i)		//loop attaches the player scores to the window
	{
		stringstream str;
		str << players[i].get_score();
		string num = str.str();
		scoreboard.push_back(new Text(Point(100, 50 + i * 20), num));
		scoreboard[scoreboard.size() - 1].set_color(1 + i * 2); //we can also use numbers from 0 to 255 for colors
		attach(scoreboard[scoreboard.size() - 1]); //attach to window the current Text object we add to the vector
	}
    //outputs a message above the winning player image with the name and score.
	winstream << winner_name << " had the high score of " << high_score << "!";
	winner_label.set_label(winstream.str());
	winner_label.set_font_size(25);
    //image of winner
	Image* winner = new Image(Point(200, 275), image_name);
    //changing crop dimensions
	(*winner).set_mask(Point(150,150), 400, 400);
    //attaching of all widgets
	attach(players_label);
	attach(scores_label);
	attach(winner_label);
	attach(*winner);
	attach(play_again_button);
	attach(quit_button);
	redraw();
}

// callback function for quit button - boilerplate:
void End_window::cb_quit(Address, Address pw)
{
	reference_to<End_window>(pw).quit();
}
// callback function for play again button - boilerplate:
void End_window::cb_play_again(Address, Address pw) {
	reference_to<End_window>(pw).play_again();  // next_player is defined next
}

// what to do when play again button is pressed
void End_window::play_again() {
	hide();
    Init_window win(Point(0, 0), 475, 175, "Word Search Project");
	gui_main();
}
//inputs data into vector of Persons from the data file, player_data.txt
void End_window::input_data(vector<Person>& players)
{
	ifstream ifs("player_data.txt");
	while (ifs) {
		if (ifs.eof()) return;
		string name;
		getline(ifs, name);  // use getline
		string score;
		getline(ifs, score);  // use getline
		int num;
		istringstream(score) >> num;
		string file_name;
		getline(ifs, file_name);
		//string emptyTP;
		//getline(ifs, emptyTP);
		players.push_back(Person(name,num,file_name));
		}
	}
