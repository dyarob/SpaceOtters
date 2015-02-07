#include	"WinColor.class.hpp"

WinColor::~WinColor( void )
{
	wborder(win, ' ', ' ', ' ',' ',' ',' ',' ',' ');
	wrefresh(win);
	delwin(win);
	endwin();
}

WinColor::WinColor( int id_ )
	: id(id_)
{
	win = newwin( WC_DEFAULT_H + 2, WC_DEFAULT_W + 2,
			WC_DEFAULT_POS_Y, WC_DEFAULT_POS_X);
	box( win, 0, 0 );
	draw();
}

void		WinColor::draw( void )
{
	unsigned int		ih(0), iw(0), i(1);

	wmove( win, 1, 1 );
	for (; i<=36; ++i)
	{
		init_pair( i, 15, 15 + id*36 + i );
		wattron( win, COLOR_PAIR(i));
		if ( ih == curs_y && iw == curs_x )
			waddch( win, '+' );
		else
			waddch( win, ' ' );
		waddch( win, ' ' );
		wattroff( win, COLOR_PAIR(i));
		++iw;
		if ( iw >= WC_DEFAULT_W/2 )
		{
			iw = 0;
			++ih;
			wmove( win, 1 + ih, 1 );
		}
	}
}


// === STATICS! ===
// vars
std::vector<WinColor*>	WinColor::wc(*(new std::vector<WinColor*>()));
int						WinColor::curr_id(0);
unsigned int			WinColor::curs_x(0);
unsigned int			WinColor::curs_y(0);

// functions
void	WinColor::init_wincolors( void ) {
	for (unsigned int i(0); i<WC_NUMBER; ++i) {
		wc.push_back(new WinColor(i));
	}
}

void	WinColor::refresh( void ) {
	wc[curr_id]->draw();
	wrefresh(wc[curr_id]->win);
}

void	WinColor::prev( void ) {
	if ( --curr_id < 0 )
		curr_id = wc.size() - 1;
	WinColor::refresh();
}
void	WinColor::next( void ) {
	if ( ++curr_id >= static_cast<int>(wc.size()) )
		curr_id = 0;
	WinColor::refresh();
}

void	WinColor::validate_pick( void ) {
	Skin::color_pick( getCursColor() );
}

short	WinColor::getCursColor( void ) {
	return ( 16 + curr_id*36 + curs_y*6 + curs_x );
}

void	WinColor::up( void ) {
	if ( curs_y != 0 )
		--curs_y;
	refresh();
}
void	WinColor::down( void ) {
	if ( curs_y < WC_DEFAULT_H-1 )
		++curs_y;
	refresh();
}
void	WinColor::left( void ) {
	if ( curs_x <= 0 && curs_y > 0 ) {
		--curs_y;
		curs_x = WC_DEFAULT_W/2-1;
	} else if ( curs_x > 0 )
		curs_x -= 1;
	refresh();
}
void	WinColor::right( void ) {
	if ( curs_x == WC_DEFAULT_W/2-1 && curs_y < WC_DEFAULT_H-1 ) {
		++curs_y;
		curs_x = 0;
	} else if ( curs_x < WC_DEFAULT_W/2-1 )
		curs_x += 1;
	refresh();
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
