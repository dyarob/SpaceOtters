#include "Projectile.class.hpp"

Skin*	Projectile::skin(new Skin('-', 4, 0));

void	Projectile::update( void ) {
	++pos.y;
}

Projectile::Projectile(unsigned int width, unsigned int height, vector2 position, vector2 acceleration)
    : AGameObject(width, height, 1, 1, position, acceleration, 'm') {
        sk = skin;
}

/*
Projectile::Projectile(Projectile const &src)
    : AGameObject(src) {
    *this = src;
}

Projectile          &Projectile::operator=(Projectile const & src) {
    this->_dmg           = src._dmg;
    this->_width            = src._width;
    this->_height           = src._height;
    this->_coord            = src._coord;
    this->_delta_v          = src._delta_v;
    return *this;
}
*/

Projectile::~Projectile(void) {
}
