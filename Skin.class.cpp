#include "Skin.class.hpp"

// *structors
Skin::Skin(char c, int fg, int bg) 
	: _fg(fg), _bg(bg), _id(Skin::_cId++), _c(c) {
	init_pair(_id, _fg, _bg);
}

Skin::~Skin() {
}

// operators
std::ofstream	&Skin::printTo( std::ofstream &o ) const {
	o << _c << ' ' << _fg << ' ' << _bg << ' ';
	return o;
}
std::ofstream	&operator<<( std::ofstream &o, Skin const &sk ) {
	return sk.printTo( o );
}
std::ostream	&Skin::printTo( std::ostream &o ) const {
	o << _c << ' ' << _fg << ' ' << _bg << ' ';
	return o;
}
std::ostream	&operator<<( std::ostream &o, Skin const &sk ) {
	return sk.printTo( o );
}


// functions
void	Skin::init_cp( void ) {
	init_pair(_id, _fg, _bg);
}

void	Skin::redefine_fg( short fg ) {
	_fg = fg;
	init_pair(_id, _fg, _bg);
}

void	Skin::redefine_bg( short bg ) {
	_bg = bg;
	init_pair(_id, _fg, _bg);
}


// === STATICS! ===
// vars
int					Skin::_cId(1);
std::vector<Skin*>	Skin::reserved_cp(*(new std::vector<Skin*>()));
short				Skin::cfg(7), Skin::cbg(0);
Skin				*Skin::curr_sk;
char				Skin::color_mode('b');

// functions
void	Skin::init_reserved_cp() {
	for (unsigned int i(1); i<=36; ++i) {
		reserved_cp.push_back(new Skin('+', 15, 5));
	}
	curr_sk = new Skin( 'o', cfg, cbg );
}

void	Skin::color_pick( short c ) {
	if ( color_mode == 'f' ) {
		cfg = c;
		curr_sk->redefine_fg( c );
	} else if ( color_mode == 'b' ) {
		cbg = c;
		curr_sk->redefine_bg( c );
	}
}

void	Skin::print_cc() {
	attron( COLOR_PAIR(curr_sk->_id) );
	mvprintw( CURR_CP_INDIC_POS_Y, CURR_CP_INDIC_POS_X, "current skin" );
	attroff( COLOR_PAIR(curr_sk->_id) );
	printw( " | color mode: " );
	addch( color_mode );
}
// === !STATICS ===
