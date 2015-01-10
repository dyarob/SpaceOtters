#include    "GUI.hpp"

GUI::GUI(void) {

}

GUI::GUI(unsigned int fire_rate, Projectile &projectile)
    : _fire_rate(fireRate), _projectile(projectile) {

}

GUI::GUI(GUI const & src) {
    *this = src;
}

GUI              &GUI::operator=(GUI const & src) {
    this->_fireRate     = src._fireRate;
    this->_projectile   = src._projectile;
    return *this;
}

unsigned int        GUI::getFireRate() const{
    return this->_fire_rate;
}

Projectile          &GUI::getProjectile() const{
    return this->_projectile;
}

GUI::~GUI(void) {

}
