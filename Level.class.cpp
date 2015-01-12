#include "Level.class.hpp"

Level::Level(int ab_speed)
	: af( new AsteroidField( ab_speed ))
{
}

Level::Level(Level const &src)
{
    *this = src;
}

Level          &Level::operator=(Level const & src) {
	this->af = src.af;
    return *this;
}

Level::~Level(void)
{

}
