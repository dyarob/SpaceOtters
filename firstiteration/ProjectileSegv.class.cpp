#include "Projectile.class.hpp"
#include "ProjectileSegv.class.hpp"
#include "Vector2D.class.hpp"

Skin*	ProjectileEnemy::skin(new Skin("segv", 5, 0));

ProjectileSegv::ProjectileSegv(Vector2D &coord, Vector2D &delta_v)
    : Projectile(1, 1, 1, coord, delta_v) {
		_skin = skin;
}

ProjectileSegv::ProjectileSegv(ProjectileSegv const &src)
    : Projectile(src) {
    *this = src;
}

ProjectileSegv      &ProjectileSegv::operator=(ProjectileSegv const &src) {
    this->_damage           = src.getDamage();
    this->_width            = src._width;
    this->_height           = src._height;
    this->_coord            = src._coord;
    this->_delta_v          = src._delta_v;
    return *this;
}

ProjectileSegv::~ProjectileSegv(void) {
	delete &_delta_v;
	delete &_coord;

}
