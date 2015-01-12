#include    "Vector2D.class.hpp"
#include    "Weapon.class.hpp"
#include    "AUnit.class.hpp"

Projectile    *AUnit::shoot(void)   const
{
	Vector2D	*pos = new Vector2D(_coord);
	Vector2D	*vel = new Vector2D(0, 1);
	return (_weapon.fire(pos, vel));
}

AUnit::AUnit(unsigned int height, unsigned int width, int hp,
    int hp_max, Weapon &weapon, Vector2D &coord, Vector2D &delta_v)
    : AGameObject(height, width, hp, hp_max, coord, delta_v),
	_weapon(weapon)
{}

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

Weapon const    &AUnit::getWeapon(void) const {
    return this->_weapon;
}

AUnit::~AUnit() {

}
