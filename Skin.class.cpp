#include "Skin.class.hpp"

Skin::Skin(char c, int fg, int bg) 
: _id(Skin::_cId++), _fg(fg), _bg(bg), _c(c) {
	init_pair(_id, _fg, _bg);
}

Skin::~Skin() {}

int		Skin::getId() { return _id; }
int		Skin::getFg() { return _fg; }
int		Skin::getBg() { return _bg; }
char	*Skin::getCAddr() { return &_c; }


// === STATICS! ===
// vars
int					Skin::_cId(1);
std::vector<Skin*>	Skin::reserved_cp(*(new std::vector<Skin*>()));
short				Skin::cfg(7), Skin::cbg(0);

// functions
void	Skin::init_reserved_cp() {
	for (unsigned int i(1); i<=256; ++i) {
		reserved_cp.push_back(new Skin('.', 15, i));
	}
}

void	Skin::print_cc() {
	attron( COLOR_PAIR(cfg) );
	mvprintw( CURR_CP_INDIC_POS_Y, CURR_CP_INDIC_POS_X, "fg" );
	attroff( COLOR_PAIR(cfg) );
	attron( COLOR_PAIR(cbg) );
	mvprintw( CURR_CP_INDIC_POS_Y, CURR_CP_INDIC_POS_X+2, "bg" );
	attroff( COLOR_PAIR(cbg) );
}
// === !STATICS ===
