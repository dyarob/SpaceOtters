#include "vector2.class.hpp"
#include <iostream>

void	pr(vector2 &v) {
	std::cout << "x= " << v.x;
	std::cout << ", y= " << v.y;
	std::cout << std::endl;
}

int	main(void) {
	vector2	*a = new vector2(0, 3);
	vector2	b(0, 4);
	vector2 c = *a;
	vector2 &d = *a;
	vector2 e(*a);
	vector2 &f(*a);
	pr(*a);
	pr(b);
	pr(c);
	pr(d);
	pr(e);
	pr(f);
	a->x = 23;
	delete a;
	std::cout << "a supprime\n";
	pr(c);
	pr(d);
	pr(e);
	pr(f);
	//a += b;
	//std::cout << (a < b);
	//std::cout << (a <= b);
	return (0);
}
