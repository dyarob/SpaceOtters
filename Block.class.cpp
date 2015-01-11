#include "Block.class.hpp"
#include "Vector2D.class.hpp"


Skin		*Block::skin( new Skin( '%', 1, 0) );

void		Block::update( void )
{
	_coord += Vector2D(0,1);
}

Block::Block(unsigned int width, unsigned int height, Vector2D &coord)
    : AGameObject(width, height, 1, 1, coord, *(new Vector2D(0,B_SPEED)))
{
	_skin = skin;
}

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

Block::~Block(void) {

}
