#include "Event.class.hpp"

Event::Event() : _type(FIRSTNODE), _next(NULLL, _prev(NULLL) {
}

Event::Event(int type, int delay, int posY) : _type(type), _delay(delay), _posY(posY), _next(NULLL), _prev(NULLL) {
}

Event::Event(Event const & e) {
	*this = e;
}

Event		&	Event::operator=(Event const & e) {
	this->_type = e._type;
	this->_delay = e._delay;
	this->_posY = e._posY;
	return *this;
}

int			Event::getType() const{
	return this->_type;
}
int			Event::getDelay() const{
	return this->_delay;
}
int			Event::getPosY() const{
	return this->_posY;
}

void		Event::pushFront(int type, int delay, int posY) {
	Event * n = new Event(type, delay, posY);
	this->_prev = n;
	n->_next = this;
}
void		Event::pushBack(int type, int delay, int posY) {
	Event * n = new Event(type, delay, posY);
	this->_next = n;
	n->_prev = this;
}

Event::~Event() {}
