#include    "EnemyBase.class.hpp"

Skin*	EnemyBase::skin(new Skin('<', 5, 0));

EnemyBase::EnemyBase(vector2 coord, vector2 delta_v, int pattern)
    : AUnit(1, 1, 1, 1, *(new WeaponEnemy()), coord, delta_v, 'e') {
        pat = pattern;
		sk = skin;
}

/*
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
    this->_pattern           = src._pattern;

    return *this;
}
*/

EnemyBase::~EnemyBase() {
    delete &this->_weapon;
}

Projectile	*EnemyBase::shoot( ) const
{
	return ( _weapon.fire( vector2(pos.x-1, pos.y), vector2(0, -1)));
}
