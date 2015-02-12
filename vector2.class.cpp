#include "vector2.class.hpp"

vector2::vector2() :
	std::pair<int, int>(0, 0),
	x(first), y(second)
{}

vector2::vector2(int a, int b) :
	std::pair<int, int>(a, b),
	x(first), y(second)
{}

vector2::~vector2() {
}

std::ostream	&operator<<(std::ostream &o, vector2 const &v) {
	o << v.x << " - " << v.y;
	return o;
}
