#include "Projectile.class.hpp"
#include "Vector2D.class.hpp"

Skin*	Projectile::skin(new Skin('-', 4, 0));

void		Projectile::update( void )
{
	_coord += Vector2D(0,1);
}

Projectile::Projectile(unsigned int width, unsigned int height, Vector2D &coord, Vector2D &delta_v)
    : AGameObject(width, height, 1, 1, coord, delta_v){
        _skin = skin;
}

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

unsigned int        Projectile::getDamage(void)         const {
    return this->_dmg;
}

Projectile::~Projectile(void) {

}
