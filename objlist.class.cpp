#include "objlist.class.hpp"

//*structors
objlist::objlist() :
	std::list<AGameObject*>()
{}

objlist::~objlist()
{}
//!*structors

std::ostream	&operator<<(std::ostream &o, objlist const &lgo) {
	return lgo.printTo(o);
}
std::ostream	&objlist::printTo(std::ostream &o) const {
	objlist::const_iterator	it(begin());
	objlist::const_iterator	en(end());
	for(; it!=en; ++it) {
		(*it)->print(o);
	}
	return o;
}

/*
void	objlist::rmOne(objlist::iterator &it) {
	delete (*it);
	it = erase(it);
}

void	objlist::foreach(void (*f)(objlist::iterator)) {
	objlist::iterator	it(begin());
	objlist::iterator	en(end());
	for (it=begin(); it!=end;) {
		if ((*it)->hp <= 0) {
			delete (*it);
			it = erase(it);
		} else
			++it;
	}
}
*/

void	objlist::clean(void) {
	objlist::iterator	it(begin());
	objlist::iterator	en(end());
	for (; it!=en; ) {
		if ((*it)->hp <= 0) {
			delete (*it);
			it = erase(it);
		} else
			++it;
	}
}

void	objlist::clear(void) {
	objlist::iterator	it(begin());
	objlist::iterator	en(end());
	for (; it!=en; ) {
		delete (*it);
		it = erase(it);
	}
}

void	objlist::moveAll(int const currentFrame) {
	objlist::iterator	it(begin());
	objlist::iterator	en(end());
	for (; it!=en; ++it) {
		(*it)->move(currentFrame);
	}
}

void	objlist::collisions(void) {
	objlist::iterator	it(begin());
	objlist::iterator	en(end());
	for (; it!=en; ++it) {
		if ((*it)->pos.x <= 0
				|| ((*it)->pos.x >= W_SCREEN-1
					&& (*it)->t == 'm')) {
			(*it)->hp = 0;
		}
		(*it)->detect_collision(*this);
	}
}

//tests
bool	objlist::isOccupied(vector2 const &pos) {
	objlist::iterator	it(begin());
	objlist::iterator	en(end());
	for (; it!=en; ++it) {
		if ((*it)->pos == pos)
			return true;
	}
	return false;
}

bool	objlist::isOccupied(int x, int y) {
	objlist::iterator	it(begin());
	objlist::iterator	en(end());
	for (; it!=en; ++it) {
		if ((*it)->pos.x == x
			&& (*it)->pos.y == y)
			return true;
	}
	return false;
}
//!tests
