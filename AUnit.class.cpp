#include    "Vector2D.class.hpp"
#include    "Weapon.class.hpp"
#include    "AUnit.class.hpp"

unsigned int AUnit::_cur_id = 0;

Projectile    *AUnit::shoot(void)   const
{
	return ( NULL );
}

AUnit::AUnit(unsigned int height, unsigned int width, int hp,
    int hp_max, Weapon &weapon, Vector2D &coord, Vector2D &delta_v)
    : _id(AUnit::_cur_id++), _height(height), _width(width), _hp(hp),
    _hp_max(hp_max), _weapon(weapon), _coord(coord), _delta_v(delta_v) {

}

AUnit::AUnit(AUnit const &src)
    : _weapon(src._weapon), _coord(src._coord), _delta_v(src._delta_v) {
    *this           = src;
    this->_id++;
}

AUnit           &AUnit::operator=(AUnit const & src) {
    this->_id               = src._id;
    this->_coord            = src._coord;
    this->_delta_v          = src._delta_v;
    this->_height           = src._height;
    this->_width            = src._width;
    this->_hp               = src._hp;
    this->_hp               = src._hp_max;
    this->_weapon           = src._weapon;

    return *this;
}

unsigned int    AUnit::getId(void)      const {
    return this->_id;
}

unsigned int    AUnit::getHeight(void)  const {
    return this->_height;
}

unsigned int    AUnit::getWidth(void)   const {
    return this->_width;
}

unsigned int    AUnit::getHp(void)      const {
    return this->_hp;
}

unsigned int    AUnit::getHpMax(void)   const {
    return this->_hp_max;
}

Weapon const    &AUnit::getWeapon(void) const {
    return this->_weapon;
}

Vector2D   &AUnit::getCoord(void)  const {
    return this->_coord;
}

Vector2D const  &AUnit::getDeltaV(void) const {
    return this->_delta_v;
}

void            AUnit::move(Vector2D &delta_v) {
    this->_delta_v += delta_v;
}

void            AUnit::setDeltaV(Vector2D &delta_v) {
    this->_delta_v = delta_v;
}

AUnit::~AUnit() {

}
