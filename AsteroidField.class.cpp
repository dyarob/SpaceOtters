#include "AsteroidField.class.hpp"
#include "Vector2D.class.hpp"


void	AsteroidField::generateBlocks(List **units)
{
	int	nb_of_blks = rand() % 10;
	BlockBase	*b;
	int x;

	if (!nb_of_blks) {
		x = rand() % H_MAP;
		b = new BlockBase( *(new Vector2D(x, W_SCREEN)), b_speed );
		*units = (*units)->push( b, 'a' );
	}
}

AsteroidField::AsteroidField(int ab_speed)
	: b_speed(ab_speed)
{
}

AsteroidField::AsteroidField(AsteroidField const &src)
{
    *this = src;
}

AsteroidField          &AsteroidField::operator=(AsteroidField const & src) {
	this->b_speed = src.b_speed;
    return *this;
}

AsteroidField::~AsteroidField(void) {

}
