#include    "AUnit.class.hpp"
#include    "Vector2D.class.hpp"
#include    "Weapon.class.hpp"
#include    "EnemyBase.class.hpp"

Skin*	EnemyBase::skin(new Skin('<', 5, 0));

EnemyBase::EnemyBase(Vector2D &coord, Vector2D &delta_v, int pattern)
    : AUnit(1, 1, 3, 3, *(new WeaponBase()), coord, delta_v) {
        this->_pattern = pattern;
		_skin = skin;
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
    this->_pattern           = src._pattern;

    return *this;
}

EnemyBase::~EnemyBase() {
    delete &this->_weapon;
}

Projectile	*EnemyBase::shoot( ) const
{
	Vector2D	r = _coord + Vector2D(0, 1);
	return ( _weapon.fire( &r, new Vector2D(1, 1)));
}
