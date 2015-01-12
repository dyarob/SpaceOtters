#include    "Projectile.class.hpp"
#include    "Weapon.class.hpp"
#include 	"Vector2D.class.hpp"

Weapon::Weapon(unsigned int fire_rate)
    : _fire_rate(fire_rate) {

}

Weapon::Weapon(Weapon const &src) {
    *this = src;
}

Weapon              &Weapon::operator=(Weapon const & src) {
    this->_fire_rate    = src._fire_rate;
    return *this;
}

unsigned int        Weapon::getFireRate(void)               const{
    return this->_fire_rate;
}

Projectile      	*Weapon::fire(Vector2D *coord, Vector2D *delta_v) {
    return ( new Projectile(1, 1, *coord, *delta_v));
}

Weapon::~Weapon(void) {

}
