#include "ProjectileBase.class.hpp"

ProjectileBase::ProjectileBase(vector2 &coord, vector2 &delta_v)
    : Projectile(1, 1, coord, delta_v) {
}

/*
ProjectileBase::ProjectileBase(ProjectileBase const &src)
    : Projectile(src) {
    *this = src;
}
ProjectileBase      &ProjectileBase::operator=(ProjectileBase const &src) {
    this->_dmg         		= src.getDamage();
    this->_width            = src._width;
    this->_height           = src._height;
    this->_coord            = src._coord;
    this->_delta_v          = src._delta_v;
    return *this;
}
*/

ProjectileBase::~ProjectileBase(void) {
	//delete &_delta_v;
	//delete &_coord;
}
