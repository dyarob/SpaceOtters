#include "AsteroidField.class.hpp"

void	AsteroidField::generateBlocks(std::list<AGameObject*> &units) {
	int	nb_of_blks = rand() % 10;
	BlockBase	*b;
	int x;

	if (!nb_of_blks) {
		x = rand() % H_MAP;
		b = new BlockBase( vector2(W_SCREEN, x), b_speed );
		units.push_back(b);
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
