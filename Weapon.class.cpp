#include    "Projectile.class.hpp"
#include    "Weapon.class.hpp"

Weapon::Weapon(unsigned int fire_rate, Projectile &projectile)
    : _fire_rate(fire_rate), _projectile(projectile) {

}

Weapon::Weapon(Weapon const &src)
    : _projectile(src._projectile) {
    *this = src;
}

Weapon              &Weapon::operator=(Weapon const & src) {
    this->_fire_rate    = src._fire_rate;
    this->_projectile   = src._projectile;
    return *this;
}

unsigned int        Weapon::getFireRate(void)               const{
    return this->_fire_rate;
}

Projectile          &Weapon::getProjectile(void)            const{
    return this->_projectile;
}

Weapon::~Weapon(void) {

}
