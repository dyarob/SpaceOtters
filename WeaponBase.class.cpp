#include    "ProjectileBase.class.hpp"
#include    "Weapon.class.hpp"
#include    "WeaponBase.class.hpp"

WeaponBase::WeaponBase(void)
    : Weapon(10) {

}

WeaponBase::WeaponBase(WeaponBase const &src) : Weapon(src) {
    *this = src;
}

WeaponBase          &WeaponBase::operator=(WeaponBase const & src) {
    this->_fire_rate    = src._fire_rate;
    return *this;
}

ProjectileBase      *WeaponBase::fire(Vector2D *coord, Vector2D *delta_v) {
    return ( new ProjectileBase(*coord, *delta_v));
}

WeaponBase::~WeaponBase(void) {

}
