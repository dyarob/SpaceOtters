#include "Projectile.class.hpp"
#include "ProjectileEnemy.class.hpp"
#include "Vector2D.class.hpp"

Skin*	ProjectileEnemy::skin(new Skin(':', 3, 0));

ProjectileEnemy::ProjectileEnemy(Vector2D &coord, Vector2D &delta_v)
    : Projectile(1, 1, coord, delta_v) {
		_skin = skin;
}

ProjectileEnemy::ProjectileEnemy(ProjectileEnemy const &src)
    : Projectile(src) {
    *this = src;
}

ProjectileEnemy      &ProjectileEnemy::operator=(ProjectileEnemy const &src) {
    this->_dmg           = src.getDmg();
    this->_width            = src._width;
    this->_height           = src._height;
    this->_coord            = src._coord;
    this->_delta_v          = src._delta_v;
    return *this;
}

ProjectileEnemy::~ProjectileEnemy(void) {

}
