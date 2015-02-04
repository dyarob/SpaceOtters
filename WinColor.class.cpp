#include	"WinColor.class.hpp"

WinColor::~WinColor( void )
{
	// destroy window
	wborder(win, ' ', ' ', ' ',' ',' ',' ',' ',' ');
	wrefresh(win);
	delwin(win);
	endwin();
}

WinColor::WinColor( int id_ ) {
	id = id_;
	win = newwin( WC_DEFAULT_H + 2, WC_DEFAULT_W + 2,
			WC_DEFAULT_POS_Y, WC_DEFAULT_POS_X);
	box( win, 0, 0 );
	draw();
}

void		WinColor::draw( void )
{
	/*
	short	i(0), x, y;
	wmove( win, 1, 1 );
	for (; i<16; ++i)
	{
		getyx( win, y, x );
		init_pair( i, 7, i );
		wattron( win, COLOR_PAIR(ccount) );
		waddch( win, '.' );
		wattroff( win, COLOR_PAIR(ccount) );
		wmove( win, y+1, x );
		++ccount;
	}
	*/
}


// === STATICS! ===
// vars
std::vector<WinColor*> WinColor::wc(*(new std::vector<WinColor*>()));
int						WinColor::curr_id(0);

// functions
void	WinColor::init_wincolors() {
	for (unsigned int i(0); i<WC_NUMBER; ++i) {
		wc.push_back(new WinColor(i));
	}
}
void	WinColor::refresh() {
	wrefresh(wc[curr_id]->win);
}
// === !STATICS ===


// crap --
WinColor::WinColor( void )
{
	// create window
	win = newwin( WC_DEFAULT_H + 2, WC_DEFAULT_W + 2, 1, 1);
	box( win, 0, 0 );
	draw();
	wrefresh( win );
}

WinColor::WinColor( WinColor const &in )
{
	*this = in;
}

WinColor	&WinColor::operator=( WinColor const &in )
{
	win = dupwin( in.win );
	return (*this);
}
// --
