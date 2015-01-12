#include    "AUnit.class.hpp"
#include    "Vector2D.class.hpp"
#include    "Weapon.class.hpp"
#include    "Player.class.hpp"

Skin	*Player::skin(new Skin('>', 7, 0));


Player::Player(Vector2D &coord, Vector2D &delta_v)
    : AUnit(1, 1, 3, 3, *(new WeaponBase()), coord, delta_v) {
	_skin = Player::skin;
    setDmg(10);
}

Player::Player(Player const &src)
    : AUnit(src) {
    *this           = src;
    this->_id++;
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

Player::~Player() {
    delete &this->_weapon;
}

