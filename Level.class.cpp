#include "Level.class.hpp"


void			Level::init( WinUI_dialogBox *db )
{
	db->fixeDialog( name, 1, 1 );
}

Level::Level(std::string nam, int ab_speed)
	: name(nam),
		af( new AsteroidField( ab_speed ))
{
}

Level::Level(Level const &src)
{
    *this = src;
}

Level          &Level::operator=(Level const & src) {
	this->name = src.name;
	this->af = src.af;
    return *this;
}

Level::~Level(void)
{

}
