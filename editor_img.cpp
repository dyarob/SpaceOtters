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
	xmax = atoi( av[2] );
	ymax = atoi( av[1] );
	Asciimg		img( ymax, xmax );
	WINDOW		*winimg = newwin( ymax + 2, xmax + 2, 1, 1);
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
					if ( x <= 1 && y > 1 )
						wmove( winimg, y - 1, xmax );
					else if ( x > 1 )
						wmove( winimg, y, x - 1 );
					break;
				case 'j':
					if ( y != ymax )
						wmove( winimg, y + 1, x );
					break;
				case 'k':
					if ( y != 1 )
						wmove( winimg, y - 1, x );
					break;
				case 'l':
					if ( x == xmax && y < ymax )
						wmove( winimg, y + 1, 1 );
					else if ( x < xmax )
						wmove( winimg, y, x + 1 );
					break;
				default:
					break;
			}
		}
	}
	endwin();
	return (0);
}
