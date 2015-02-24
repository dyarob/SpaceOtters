#include "Level.class.hpp"

//statics
short	Level::id(0);
std::vector<Level*>	Level::lvls(NB_LVL);

void	Level::lvlsInit() {
	lvls[0] = new Level ("Level 1 - Asteroid field", -2 );
	lvls[1] = new Level ("Level 2 - Asteroid field", -3 );
	lvls[2] = new Level ("Level 3 - Asteroid field", -1 );
	lvls[3] = new Level ("Face Zaz, the final boss!", -1 );
}

void	Level::update(objlist &objects) {
	lvls[id]->af->generateBlocks(objects);
}
//!statics

void	Level::init( WinUI_dialogBox *db ) {
	db->fixeDialog( name, 1, 1 );
}

Level::Level(std::string nam, int ab_speed)
	: name(nam),
	af( new AsteroidField( ab_speed )) {
}

Level::Level(Level const &src) {
    *this = src;
}

Level	&Level::operator=(Level const & src) {
	this->name = src.name;
	this->af = src.af;
	return *this;
}

Level::~Level(void) {
}
