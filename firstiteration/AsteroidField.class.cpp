#include "AsteroidField.class.hpp"

void	AsteroidField::generateBlocks(objlist &units) {
	int	nb_of_blks = rand() % 10;
	int x;

	if (!nb_of_blks) {
		x = rand() % (H_MAP-2) +1;
		if (!units.isOccupied(W_SCREEN-2, x))
			units.push_back(new BlockBase(vector2(W_SCREEN-2, x), b_speed));
	}
}

AsteroidField::AsteroidField(int ab_speed)
	: b_speed(ab_speed)
{
}

AsteroidField::AsteroidField(AsteroidField const &src) {
    *this = src;
}

AsteroidField          &AsteroidField::operator=(AsteroidField const & src) {
	this->b_speed = src.b_speed;
    return *this;
}

AsteroidField::~AsteroidField(void) {

}
