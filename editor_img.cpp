#include	"Asciimg.class.hpp"
#include	"WinUI_dialogBox.class.hpp"
#include	"WinColor.class.hpp"

#include	<ncurses.h>
#include	<fstream>
#include	<iostream>
#include	<cstdlib> //atoi
#include	<string>
#include	<cctype> //isprint

int			main( int ac, char **av )
{
	char	ch;
	int		x(1), y(1), xmax, ymax;
	bool	stop(false);
	// MODES
	char	mode('n');
	// n = normal
	// i = insert
	// f = change foreground
	// b = change background

	// ==== options & arguments check ====
	if ( ac != 3 )
	{
	/*
		if ( ac == 2 && !std::string(av[1]).compare("-h") )
			std::cout << "Commands memo:\nq\t| quit\nhjkl\t| move cursor around" << std::endl;
		else
			std::cout << "Usage: editor height width" << std::endl;
		return (0);
	*/
	}

	// ==== ncurses init ====
	initscr();
	noecho();
	start_color();
	Skin::init_reserved_cp();
	Skin::print_cc();
	WinColor::init_wincolors();
	//
	refresh();
	WinColor::refresh();

	xmax = atoi( av[2] );
	ymax = atoi( av[1] );
	Asciimg		img( ymax, xmax );
	img.load( "bonjour" );
	WINDOW		*winimg = newwin( ymax + 2, xmax + 2, 1, 5);
	box( winimg, 0, 0 );
	wmove( winimg, 1, 1 );
	img.draw( winimg, 1, 1 );

	while (!stop)
	{
		wrefresh( winimg );
		getyx( winimg, y, x );
		ch = getch();
		
		// == insert mode ==
		if ( mode == 'i' )
		{
			if ( ch == 27 )	// escape keys
			{
				switch ( ch = getch() )
				{
					case ERR:
						timeout(-1);
						mode = 'n';
						break;
					default:
						break;
				}
			}
			else if ( std::isprint(ch) && !(y == ymax && x > xmax) )
			{
				img.skins[(y-1) * img.w + (x-1)]->_c = ch;
				img.skins[(y-1) * img.w + (x-1)]->_fg = Skin::cfg;
				img.skins[(y-1) * img.w + (x-1)]->_bg = Skin::cbg;
				img.draw( winimg, 1, 1 );
			}
			if ( x > xmax )
				if ( y < ymax )
					wmove( winimg, y + 1, 1 );
		}

		// == color pick mode ==
		else if ( mode == 'f' || mode == 'b' )
		{
			switch( ch )
			{
				case 27:	// escape keys
					switch ( ch = getch() )
					{
						case ERR:
							timeout(-1);
							mode = 'n';
							break;
						default:
							break;
					}
					break;
				case ' ':	//validate pick
					if ( mode == 'f' )
						Skin::cfg = 42;
					else
						Skin::cbg = 42;
					Skin::print_cc();
					refresh();
					mode = 'n';
					break;
				default:
					break;
			}
		}

		// == normal mode ==
		else
		{
			switch( ch )
			{
				case 'q':
					stop = true;
					break;
				case 'i':
					timeout(0);
					mode = 'i';
					break;
				case 'f':	//change foreground color
					mode = 'f';
					break;
				case 'b':	//change background color
					mode = 'b';
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

	img.save( winimg );
	endwin();
	return (0);
}
