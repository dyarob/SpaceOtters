#include    "Vector2D.class.hpp"

Vector2D::Vector2D(void)
    : _x(0), _y(0) {

}

Vector2D::Vector2D(int x, int y)
    : _x(x), _y(y) {

}

Vector2D::Vector2D(Vector2D const &src) {
    *this = src;
}

Vector2D              &Vector2D::operator=(Vector2D const &src) {
	this->_x        = src.getX();
	this->_y        = src.getY();
    return *this;
}

Vector2D              &Vector2D::operator-=(Vector2D const &rhs) {
    this->_x        -= rhs.getX();
    this->_y        -= rhs.getY();
    return *this;
}

Vector2D              &Vector2D::operator+=(Vector2D const &rhs) {
    this->_x        += rhs.getX();
    this->_y        += rhs.getY();
    return *this;
}

Vector2D              Vector2D::operator+(Vector2D const &rhs) {
    return Vector2D(this->getX() + rhs.getX(), this->getY() + rhs.getY());
}

Vector2D              Vector2D::operator-(Vector2D const &rhs) {
    return Vector2D(this->getX() - rhs.getX(), this->getY() - rhs.getY());
}

int                     Vector2D::getX(void)               const{
    return this->_x;
}

int                     Vector2D::getY(void)               const{
    return this->_y;
}

void                    Vector2D::setX(int x) {
    this->_x = x;
}

void                    Vector2D::setY(int y) {
    this->_y = y;
}

Vector2D::~Vector2D(void) {

}
