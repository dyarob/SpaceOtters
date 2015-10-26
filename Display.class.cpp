#include "Display.class.hpp"

		Display::Display(void) {
	windows = new std::vector<Window*>();
	windows->reserve(WINUMBER);
}

int	Display::update(unsigned const currFrame) {
	for (const auto win : *windows) {
		win->update(currFrame);
	}
	return 0;
}

		Display::~Display(void) {
	windows->clear(); //all elements are effectively destroyed
	delete(windows);
}
