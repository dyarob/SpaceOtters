#include "Block.class.hpp"

Skin		*Block::skin( new Skin( '%', 5, 0) );


void		Block::update(void) {
	++pos.y;
}

Block::Block(unsigned int width, unsigned int height, vector2 coord, int aspeed)
    : AGameObject(width, height, 4, 4, coord, vector2(aspeed, 0), 'a')
{
	sk = skin;
}

/*
Block::Block(Block const &src)
    : AGameObject(src) {
    *this = src;
}
Block          &Block::operator=(Block const & src) {
    this->_width            = src._width;
    this->_height           = src._height;
    this->_coord            = src._coord;
    this->_delta_v          = src._delta_v;
    return *this;
}
*/

Block::~Block(void) {
}
