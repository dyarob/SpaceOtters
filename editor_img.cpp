#include	"Asciimg.class.hpp"
#include	"WinUI_dialogBox.class.hpp"
#include	<fstream>
#include	<iostream>
#include	<cstdlib> //atoi
#include	<ncurses.h>

int			main( int ac, char **av )
{
	char	ch;
	int		x(1), y(1), xmax, ymax;
	bool	stop(false);
	if ( ac != 3 )
	{
		std::cout << "Usage: editor height width" << std::endl;
		return (0);
	}
	initscr();
	start_color();
	refresh();
	xmax = atoi( av[2] ) + 1;
	ymax = atoi( av[1] ) + 1;
	Asciimg		img( ymax - 1, xmax - 1 );
	WINDOW		*winimg = newwin( ymax + 1, xmax + 1, 1, 1);
	box( winimg, 0, 0 );
	wmove( winimg, 1, 1 );
	wrefresh( winimg );
	while (!stop)
	{
		getyx( winimg, y, x );
		ch = getch();
		switch( ch )
		{
			case ' ':
				stop = true;
				break;
			case 'h':
				//if 
	wmove( winimg, y, x );
				break;
			case 'j':
				break;
			case 'k':
				break;
			case 'l':
				break;
			default:
				break;
		}
	}
	endwin();
	return (0);
}
