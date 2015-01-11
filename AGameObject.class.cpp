#include    "Vector2D.class.hpp"
#include    "Weapon.class.hpp"
#include    "AGameObject.class.hpp"

unsigned int AGameObject::_cur_id = 0;

AGameObject::AGameObject(unsigned int height, unsigned int width, int hp,
    int hp_max, Vector2D &coord, Vector2D &delta_v)
    : _id(AGameObject::_cur_id++), _height(height), _width(width), _hp(hp),
    _hp_max(hp_max), _coord(coord), _delta_v(delta_v) {

}

AGameObject::AGameObject(AGameObject const &src)
    : _coord(src._coord), _delta_v(src._delta_v) {
    *this           = src;
    this->_id++;
}

AGameObject           &AGameObject::operator=(AGameObject const & src) {
    this->_id               = src._id;
    this->_coord            = src._coord;
    this->_delta_v          = src._delta_v;
    this->_height           = src._height;
    this->_width            = src._width;
    this->_hp               = src._hp;
    this->_hp               = src._hp_max;

    return *this;
}

unsigned int    AGameObject::getId(void)      const {
    return this->_id;
}

unsigned int    AGameObject::getHeight(void)  const {
    return this->_height;
}

unsigned int    AGameObject::getWidth(void)   const {
    return this->_width;
}

unsigned int    AGameObject::getHp(void)      const {
    return this->_hp;
}

unsigned int    AGameObject::getHpMax(void)   const {
    return this->_hp_max;
}

Vector2D		&AGameObject::getCoord(void)  const {
    return this->_coord;
}

Vector2D		&AGameObject::getDeltaV(void) const {
    return this->_delta_v;
}

void            AGameObject::move(Vector2D &delta_v) {
    this->_coord += delta_v;
}

void            AGameObject::setDeltaV(Vector2D &delta_v) {
    this->_delta_v = delta_v;
}

AGameObject::~AGameObject() {

}