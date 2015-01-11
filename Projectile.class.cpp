#include "Projectile.class.hpp"
#include "Vector2D.class.hpp"

void		Projectile::update( void )
{
	_coord += Vector2D(0,1);
}

Projectile::Projectile(unsigned int damage, unsigned int width, unsigned int height, Vector2D &coord, Vector2D &delta_v)
    : AGameObject(width, height, 1, 1, coord, delta_v), _damage(damage)
{}

Projectile::Projectile(Projectile const &src)
    : AGameObject(src) {
    *this = src;
}

Projectile          &Projectile::operator=(Projectile const & src) {
    this->_damage           = src._damage;
    this->_width            = src._width;
    this->_height           = src._height;
    this->_coord            = src._coord;
    this->_delta_v          = src._delta_v;
    return *this;
}

unsigned int        Projectile::getDamage(void)         const {
    return this->_damage;
}

Projectile::~Projectile(void) {

}