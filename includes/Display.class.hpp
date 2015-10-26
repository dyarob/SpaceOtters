#ifndef DISPLAY
# define DISPLAY

#include <vector>
#include "Window.class.hpp"

#define WINUMBER	1

class		Display {

	private:
		std::vector<Window*>	*windows;

	public:
					Display();
					~Display();
		int		update(unsigned const currFrame);
};

#endif
