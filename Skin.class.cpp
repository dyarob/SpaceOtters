#include "Skin.class.hpp"

int	Skin::_cId(0);

Skin::Skin(char c, int fg, int bg) 
: _id(Skin::_cId++), _fg(fg), _bg(bg), _c(c) {
	init_pair(_id, _fg, _bg);
}

Skin::~Skin() {}

int		Skin::getId() { return _id; }
int		Skin::getFg() { return _fg; }
int		Skin::getBg() { return _bg; }
char	*Skin::getCAddr() { return &_c; }
