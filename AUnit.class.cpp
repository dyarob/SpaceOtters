#include    "AUnit.class.hpp"
#include    "Weapon.class.hpp"

AUnit::_cur_id   = 0;

AUnit::AUnit(unsigned int _id, unsigned int speed, unsigned int height, unsigned int width, int hp, int hp_max, Weapon const & weapon)
    : _id(AUnit::_cur_id++), _speed(speed), _height(height), _width(width), _hp(hp), _hp_max(hp_max), _weapon(weapon) {

}

AUnit::AUnit(AUnit const & src) {
    *this = src;
    this->_id++;
}

AUnit           &AUnit::operator=(AUnit const & src) {
    this->_id               = src._id;
    this->_speed            = src._speed;
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

unsigned int    AUnit::getSpeed(void)   const {
    return this->_speed;
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

Weapon const &  AUnit::getWeapon(void)  const {
    return this->_weapon;
}

AUnit::~AUnit() {

}
