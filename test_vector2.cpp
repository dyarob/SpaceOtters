#include "vector2.class.hpp"
#include <iostream>

int	main(void) {
	vector2	a(0, 3);
	vector2	b(0, 4);
	vector2 c = a;
	std::cout << a.x;
	std::cout << a.y;
	std::cout << b.x;
	std::cout << b.y;
	std::cout << c.x;
	std::cout << c.y;
	//a += b;
	std::cout << (a < b);
	std::cout << (a <= b);
	return (0);
}
