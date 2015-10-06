#include "Player.class.hpp"

Skin	*Player::skin(new Skin('>', 7, 0));


Player::Player(vector2 coord, vector2 delta_v)
    : AUnit(1, 1, 3, 5, *(new WeaponBase()), coord, delta_v, 'p') {
	sk = Player::skin;
}

/*
Player::Player(Player const &src)
    : AUnit(src) {
    *this           = src;
    id++;
}
Player           &Player::operator=(Player const & src) {
    this->_id               = src._id;
    this->_coord            = src._coord;
    this->_delta_v          = src._delta_v;
    this->_height           = src._height;
    this->_width            = src._width;
    this->_hp               = src._hp;
    this->_hp               = src._hp_max;
    this->_weapon           = src._weapon;
    return *this;
}
*/

Player::~Player() {
   // delete &this->_weapon;
}
