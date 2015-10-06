#include "ProjectileEnemy.class.hpp"

Skin*	ProjectileEnemy::skin(new Skin(':', 3, 0));

ProjectileEnemy::ProjectileEnemy(vector2 &coord, vector2 &delta_v)
    : Projectile(1, 1, coord, delta_v) {
		sk = skin;
}

/*
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
*/

ProjectileEnemy::~ProjectileEnemy(void) {
//delete &_coord;
//delete &_delta_v;
}
