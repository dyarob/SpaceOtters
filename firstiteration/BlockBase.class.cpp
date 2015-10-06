#include "BlockBase.class.hpp"

Skin		*BlockBase::skin ( new Skin( '#', 1, 0 ));

BlockBase::BlockBase(vector2 coord, int aspeed)
    : Block( 1, 1, coord, aspeed) {
	sk = skin;
}

/*
BlockBase::BlockBase(BlockBase const &src)
    : Block(src) {
    *this = src;
}

BlockBase      &BlockBase::operator=(BlockBase const &src) {
    this->_width            = src._width;
    this->_height           = src._height;
    this->_coord            = src._coord;
    this->_delta_v          = src._delta_v;
    return *this;
}
*/

BlockBase::~BlockBase(void) {
}
