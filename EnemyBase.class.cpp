#include    "AUnit.class.hpp"
#include    "Vector2D.class.hpp"
#include    "Weapon.class.hpp"
#include    "EnemyBase.class.hpp"

EnemyBase::EnemyBase(Vector2D &coord, Vector2D &delta_v)
    : AUnit(1, 1, 3, 3, *(new WeaponBase()), coord, delta_v) {

}

EnemyBase::EnemyBase(EnemyBase const &src)
    : AUnit(src) {
    *this           = src;
    this->_id++;
}

EnemyBase           &EnemyBase::operator=(EnemyBase const & src) {
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

EnemyBase::~EnemyBase() {
    delete &this->_weapon;
}

void	EnemyBase::shoot( Weapon const & ) const
{
}
