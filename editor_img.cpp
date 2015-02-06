#include	"Asciimg.class.hpp"
#include	"WinUI_dialogBox.class.hpp"
#include	"WinColor.class.hpp"
#include	"Skin.class.hpp"

#include	"debug.hpp"

#include	<ncurses.h>
#include	<fstream>
#include	<iostream>
#include	<cstdlib> //atoi
#include	<string>
#include	<string.h> //strcmp
#include	<cctype> //isprint

void	displayDefaultHelp( void ) {
	std::cout << "Usage:" << std::endl;
	std::cout << "- To open existing file:\teditor file_name" << std::endl;
	std::cout << "- To create new file:\t\teditor name height width" << std::endl;
	std::cout << "- Open cheat sheet:\t\teditor -h" << std::endl;
}

void	displayModes( void ) {
	std::cout << "Modes:" << std::endl;
	std::cout << "n\tnormal" << std::endl;
	std::cout << "i\tinsert" << std::endl;
	std::cout << "f\tchange foreground color" << std::endl;
	std::cout << "b\tchange background color" << std::endl;
}

void	displayMemo( void ) {
	displayModes();
	std::cout << "Commands:" << std::endl;
	std::cout << "esc\treturn to normal mode" << std::endl;
	std::cout << "Normal mode:" << std::endl;
	std::cout << "q\tquit" << std::endl;
	std::cout << "hjkl\tmove cursor around" << std::endl;
}

int		main( int ac, char **av ) {
	char	ch;
	int		x(1), y(1), xmax, ymax;
	bool	stop(false);
	char	mode('n');
	WINDOW	*winimg;
	Asciimg	*img;

	// ==== options & arguments check ====
	switch( ac ) {
		case 2:
			if ( !strcmp( av[1], "-h" ) ) {
				displayDefaultHelp();
				displayMemo();
				return (0);
			} else {
	xmax = atoi( av[2] );
	ymax = atoi( av[1] );
	Asciimg		img( ymax, xmax );
	img.load( "bonjour" );
	winimg = newwin( ymax + 2, xmax + 2, 1, 5);
	box( winimg, 0, 0 );
	wmove( winimg, 1, 1 );
	img.draw( winimg, 1, 1 );
			}
		case 4:
	xmax = atoi( av[2] );
	ymax = atoi( av[1] );
	Asciimg		img( ymax, xmax );
	img.load( "bonjour" );
	winimg = newwin( ymax + 2, xmax + 2, 1, 5);
	box( winimg, 0, 0 );
	wmove( winimg, 1, 1 );
	img.draw( winimg, 1, 1 );
			break;
		default:
			displayDefaultHelp();
			return (0);
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


	while (!stop) {
		wrefresh( winimg );
		getyx( winimg, y, x );
		ch = getch();

		// == insert mode ==
		if ( mode == 'i' ) {
			if ( ch == 27 ) {	// escape keys
				switch ( ch = getch() ) {
					case ERR:
						timeout(-1);
						mode = 'n';
						break;
					default:
						break;
				}
			} else if ( std::isprint(ch) && !(y == ymax && x > xmax) ) {
				img.skins[(y-1) * img.w + (x-1)]->_c = ch;
				img.skins[(y-1) * img.w + (x-1)]->redefine_fg(Skin::cfg);
				img.skins[(y-1) * img.w + (x-1)]->redefine_bg(Skin::cbg);
				img.draw( winimg, 1, 1 );
				wrefresh( winimg );
			}
			if ( x > xmax && y < ymax )
				wmove( winimg, y + 1, 1 );
		}

		// == color pick mode ==
		else if ( mode == 'f' || mode == 'b' ) {
			switch( ch ) {
				case 27:	// escape keys
					switch ( ch = getch() ) {
						case ERR:
							timeout(-1);
							mode = 'n';
							break;
						default:
							break;
					}
					break;

				case ' ':	//validate pick
					if ( mode == 'f' ) {
						Skin::cfg = WinColor::getCursColor();
						Skin::curr_sk->redefine_fg( WinColor::getCursColor() );
					} else {
						Skin::cbg = WinColor::getCursColor();
						Skin::curr_sk->redefine_bg( WinColor::getCursColor() );
					}
					Skin::print_cc();
					refresh();
					mode = 'n';
					break;

				case ',':	//previous wincolor
					WinColor::prev();
					break;
				case '.':	//next wincolor
					WinColor::next();
					break;
				case 'h': WinColor::left(); break;
				case 'j': WinColor::down(); break;
				case 'k': WinColor::up(); break;
				case 'l': WinColor::right(); break;
				default: break;
			}
		}

		// == normal mode ==
		else {
			switch( ch ) {
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
				default: break;
			}
		}
	}

	img.save( winimg );
	endwin();
	return (0);
}
