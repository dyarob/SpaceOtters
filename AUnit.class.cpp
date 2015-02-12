#include    "AUnit.class.hpp"

Projectile	*AUnit::shoot(void)   const
{
	vector2	projPos(pos.x+1, pos.y);
	vector2	projAcc(1, 0);
	return (_weapon.fire(projPos, projAcc));
}

AUnit::AUnit(unsigned int height, unsigned int width, int hp,
    int hp_max, Weapon &weapon, vector2 coord, vector2 delta_v, char type)
    : AGameObject(height, width, hp, hp_max, coord, delta_v, type),
	_weapon(weapon)
{}

/*
AUnit::AUnit(AUnit const &src)
    : AGameObject(src), _weapon(src._weapon) {
    *this           = src;
}
AUnit           &AUnit::operator=(AUnit const & src) {
    this->_id               = src._id;
    this->_dmg              = src._dmg;
    this->_coord            = src._coord;
    this->_delta_v          = src._delta_v;
    this->_height           = src._height;
    this->_width            = src._width;
    this->_hp               = src._hp;
    this->_hp_max            = src._hp_max;
    this->_weapon           = src._weapon;
    return *this;
}
*/

Weapon const    &AUnit::getWeapon(void) const {
    return this->_weapon;
}

AUnit::~AUnit() {
}
