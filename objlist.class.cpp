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
