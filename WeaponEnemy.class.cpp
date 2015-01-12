#include    "ProjectileEnemy.class.hpp"
#include    "Weapon.class.hpp"
#include    "WeaponEnemy.class.hpp"

WeaponEnemy::WeaponEnemy(void)
    : Weapon(10) {

}

WeaponEnemy::WeaponEnemy(WeaponEnemy const &src) : Weapon(src) {
    *this = src;
}

WeaponEnemy          &WeaponEnemy::operator=(WeaponEnemy const & src) {
    this->_fire_rate    = src._fire_rate;
    return *this;
}

ProjectileEnemy      *WeaponEnemy::fire(Vector2D *coord, Vector2D *delta_v) {
    return ( new ProjectileEnemy(*coord, *delta_v));
}

WeaponEnemy::~WeaponEnemy(void) {

}
