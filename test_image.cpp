#include "Asciimg.class.hpp"
#include "WinUI_dialogBox.class.hpp"

#include <iostream>
#include <cmath>
#include <fstream>

void	initColors( void )
{
	unsigned short	i;
	std::ofstream	f("coucou2");
	f << COLORS << std::endl;
	f << COLOR_PAIRS << std::endl;
	for (i=1;i!=0;++i)	// on fait le tour en passant par le max et le min pour revenir a 0
	{
		f << i << " ";
		init_pair( i, i / 255, i % 255 );
	}
	f << std::endl;
	f << COLOR_PAIRS << std::endl;
}

int		main( void )
{
	initscr();
	start_color();
	initColors();
	refresh();
	WinUI_dialogBox		dbox(120, 5, 10, 5);

	Asciimg	blah;
	blah.h=2;
	blah.w=2;
	blah.load("bonjour");
	blah.draw(dbox.win, 1, 1);
	wrefresh(dbox.win);

	getch();
	return (0);
}
