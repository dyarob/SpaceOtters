#include "AsteroidField.class.hpp"
#include "Vector2D.class.hpp"


void	AsteroidField::generateBlocks(List **units)
{
	int	nb_of_blks = rand() % 2;
	BlockBase	*b;
	int x;

	for (int i = 0; i < nb_of_blks; ++i)
	{
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
