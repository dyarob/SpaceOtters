#include	"Asciimg.class.hpp"
#include	"WinUI_dialogBox.class.hpp"
#include	<fstream>
#include	<iostream>
#include	<cstdlib> //atoi
#include	<ncurses.h>
#include	<string>
#include	<cctype> //isprint

int			main( int ac, char **av )
{
	char	ch;
	int		x(1), y(1), xmax, ymax;
	bool	stop(false), insert(false);
	if ( ac != 3 )
	{
		if ( ac == 2 && !std::string(av[1]).compare("-h") )
			std::cout << "Commands memo:\nq\t| quit\nhjkl\t| move cursor around" << std::endl;
		else
			std::cout << "Usage: editor height width" << std::endl;
		return (0);
	}
	initscr();
	noecho();
	start_color();
	refresh();
	xmax = atoi( av[2] ) + 1;
	ymax = atoi( av[1] ) + 1;
	Asciimg		img( ymax - 1, xmax - 1 );
	WINDOW		*winimg = newwin( ymax + 1, xmax + 1, 1, 1);
	box( winimg, 0, 0 );
	wmove( winimg, 1, 1 );

	while (!stop)
	{
		wrefresh( winimg );
		getyx( winimg, y, x );
		ch = getch();
		if ( insert )
		{
			if ( ch == 27	// escape keys
			   && getch() == ERR )	// escape
			{
				timeout(-1);
				insert = false;
			}
			else if ( std::isprint(ch) )
				waddch( winimg, ch );
		}
		else
		{
			switch( ch )
			{
				case 'q':
					stop = true;
					break;
				case 'i':
					timeout(0);
					insert = true;
					break;
				case 'h':
					wmove( winimg, y, x-1 );
					break;
				case 'j':
					wmove( winimg, y+1, x );
					break;
				case 'k':
					wmove( winimg, y-1, x );
					break;
				case 'l':
					wmove( winimg, y, x+1 );
					break;
				default:
					break;
			}
		}
	}
	endwin();
	return (0);
}
