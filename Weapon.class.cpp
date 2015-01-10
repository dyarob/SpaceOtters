#include    "Weapon.hpp"

Weapon::Weapon(void) {

}

Weapon::Weapon(unsigned int fire_rate, Projectile &projectile)
    : _fire_rate(fireRate), _projectile(projectile) {

}

Weapon::Weapon(Weapon const & src) {
    *this = src;
}

Weapon              &Weapon::operator=(Weapon const & src) {
    this->_fireRate     = src._fireRate;
    this->_projectile   = src._projectile;
    return *this;
}

unsigned int        Weapon::getFireRate() const{
    return this->_fire_rate;
}

Projectile          &Weapon::getProjectile() const{
    return this->_projectile;
}

Weapon::~Weapon(void) {

}
