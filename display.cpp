#include "display.hpp"
#include "data.hpp"

void	x::initiate() {
	//windows = new std::vector<Window*>();
	//windows->reserve(WINUMBER);
	d::resource[0] = (void*)malloc(30*120);
}

int	x::update(unsigned const currFrame) {
	(void)currFrame;
//	for (const auto depth : d::depth) {
		//draw here
//	}
	return 0;
}
