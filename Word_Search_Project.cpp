#include "std_lib_facilities_4.h"
#include "Init_window.h"

using namespace std;
using namespace Graph_lib;

int main()
{
	try
	{
		// construct the GUI window
		Init_window win(Point(0, 0), 475, 175, "Word Search Project");
		return gui_main();  // inherited from Window; calls FLTK's run
	}
	catch(exception& e)
	{
		cerr << "exception: " << e.what() << '\n';
		return 1;
	}
	catch(...)
	{
		cerr << "some exception\n";
		return 2;
	}
}
