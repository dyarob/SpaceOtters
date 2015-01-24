#include "Asciimg.class.hpp"
#include "WinUI_dialogBox.class.hpp"

#include <iostream>
#include <cmath>
#include <fstream>

int		main( void )
{
	initscr();
	start_color();
	refresh();
	WinUI_dialogBox		dbox(120, 5, 10, 5);

	Asciimg	blah;
	blah.h=1;
	blah.w=4;
	blah.load("bonjour");
	blah.draw(dbox.win, 1, 1);
	wrefresh(dbox.win);

	getch();
	return (0);
}
