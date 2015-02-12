#include    "Weapon.class.hpp"

Weapon::Weapon(unsigned int fire_rate)
    : _fire_rate(fire_rate) {
}

/*
Weapon::Weapon(Weapon const &src) {
    *this = src;
}
Weapon              &Weapon::operator=(Weapon const & src) {
    this->_fire_rate    = src._fire_rate;
    return *this;
}
*/

unsigned int        Weapon::getFireRate(void)               const{
    return this->_fire_rate;
}

Projectile      	*Weapon::fire(vector2 *coord, vector2 *delta_v) {
    return ( new Projectile(1, 1, *coord, *delta_v));
}

Weapon::~Weapon(void) {
}
